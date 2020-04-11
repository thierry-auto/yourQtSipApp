#include "yourclass.h"

#include <QMutexLocker>
#include <QThread>
#include <iostream>


YourClass::YourClass(int member, QObject *parent) : QObject(parent)  {

    std::cout << "YourClass::YourClass(" << member << ", " << parent << ");" << std::endl;
    m_member1 = member;
    m_ys.m_member1 = 44;
    m_ys.m_member2 = 'G';
}

YourClass::~YourClass() {

    std::cout << "YourClass::~YourClass();" << std::endl;
}

int YourClass::getMember() {

    QMutexLocker locker(&m_mutex);
    return m_member1;
}

int * YourClass::getMemberRef() {

    return &m_member1;
}

void YourClass::setMember(const int member) {

    QMutexLocker locker(&m_mutex);
    m_member1 = member;
}

void YourClass::setSleep(const int sleep) {

    std::cout << "YourClass::static_method1(" << sleep << ");" << std::endl;
    s_sleep = sleep;
}

const char * YourClass::returnCharPtr() {

    const char * const STRING = "hello world!";

    return STRING;
}

YourStruct * YourClass::getYourStruct() {

    return &m_ys;
}

void YourClass::init() {

    connect(&m_timer, &QTimer::timeout, this, &YourClass::processIdle);
    m_timer.start(1000);
}

int YourClass::s_sleep = 0;

int YourClass::processIdle() {

    QMutexLocker locker(&m_mutex);
    QThread::sleep(s_sleep);
    m_member1++;
    return 0;
}

QList<YourStruct> YourClass::getAListOfYourStruct() {

    QList<YourStruct> list;

    YourStruct ys1 = {100, 'a'};
    YourStruct ys2 = {101, 'b'};

    list.append(ys1);
    list.append(ys2);

    return list;
}

int * YourClass::returnAIntPtr() {

    static int AINT = 666;

    return &AINT;
}

void aFunction() {

    std::cout << "aFunction();" << std::endl;
}
