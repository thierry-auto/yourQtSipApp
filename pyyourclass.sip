%Module pyyourclass
%Import QtCore/QtCoremod.sip

%If (Qt_5_0_0 -)

%ModuleCode
#include <yourclass.h>
#include <iostream>
%End

%Include pyyourstruct.sip

class YourClass : public QObject {

%TypeHeaderCode
#include <./yourclass.h>
%End

public:
    YourClass(int member = 0, QObject * parent = 0);
    ~YourClass();

public:

    void init();
    int getMember();

    const char * returnCharPtr();
    YourStruct * getYourStruct();
    //int * returnAIntPtr();

    void setMember(const int);
    static void setSleep(const int);
};

void aFunction();

%End

