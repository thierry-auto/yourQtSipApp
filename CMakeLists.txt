cmake_minimum_required(VERSION 3.11.4)
project(youclass VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

FIND_PACKAGE(Qt5 COMPONENTS Core Test)

include_directories(${PYTHON_INCLUDE_DIRS})
set(CMAKE_VERBOSE_MAKEFILE ON)

ADD_DEFINITIONS(${QT_DEFINITIONS})

find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp REQUIRED)

ADD_DEFINITIONS(-Wall)
ADD_DEFINITIONS(-fPIC)
ADD_DEFINITIONS(-DDEBUG)
ADD_DEFINITIONS(-DTUNIT)

INCLUDE_DIRECTORIES(SYSTEM ${QT_USE_FILE})
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
find_package(SIP REQUIRED)
INCLUDE(SIPMacros)
SET(SIP_TAGS "WS_X11")

SET(HEADER_FILES

  yourclass.h
  yourstruct.h
)

SET(SOURCE_FILES

  yourclass.cpp
  yourstruct.cpp
)

add_compile_definitions(HOST)
ADD_LIBRARY(yourclass SHARED ${SOURCE_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES(yourclass Qt5::Core)


SET(SIP_INCLUDES "/usr/lib/python3.8/site-packages/PyQt5/bindings/")
set(SIP_EXTRA_OPTIONS -g -n PyQt5.sip) # -g means always release the GIL before calling C++ methods.
SET(SIP_CONCAT_PARTS 1)
add_sip_python_module(pyyourclass ./pyyourclass.sip yourclass)



