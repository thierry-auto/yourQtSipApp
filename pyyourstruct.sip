
%If (Qt_5_0_0 -)

%ModuleCode
#include <yourstruct.h>
#include <iostream>
%End

struct YourStruct {

%TypeHeaderCode
#include <./yourclass.h>
%End

    YourStruct(int, char);
    YourStruct(const YourStruct &);
    //YourStruct operator = (const YourStruct &);
    void set();
    void printMember() const;
};

%MappedType QList<YourStruct>
{
  %TypeHeaderCode
  #include "yourclass.h"
  %End

  %ConvertFromTypeCode
    // sipCpp is an implicit object, basically a pointer the
    // instance currently being mapped.
    size_t size = sipCpp->size();
    PyObject *l = PyList_New(size);

    // iterate over all elements and copy them into the PyList
    for (size_t i = 0; i < size; ++i) {
      // Create a pointer to an element
      YourStruct* cppStats = new YourStruct(sipCpp->at(i));
      // convert from a C/C++ type to Python
      PyObject *pyObj = sipConvertFromType((void*)(cppStats), sipType_YourStruct, NULL);
      // put it into the PyList object
      PyList_SetItem(l, i, pyObj);
    }

    // return the PyList
    return l;
  %End

  %ConvertToTypeCode
    Py_ssize_t size = PyList_Size(sipPy);
    QList<YourStruct> *cppList = new QList<YourStruct>();
    int sipErr = 0;
    for(int i = 0; i < size; i++) {

      // get the element from the list
      PyObject *pyStat = PyList_GET_ITEM(sipPy, i);

      // Convert to a C/C++ type from Python
      YourStruct *cppType = (YourStruct*)sipConvertToType(pyStat, sipType_YourStruct, NULL, SIP_NOT_NONE, NULL, &sipErr);

      // add it to the C/C++ container
      cppList->append(*cppType);
    }
    *sipCppPtr = cppList;
    return sipGetState(sipTransferObj);
  %End
};

%End

