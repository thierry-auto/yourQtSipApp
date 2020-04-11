#pragma once

#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QList>
#include <QSharedPointer>

#include "yourstruct.h"

#if defined(YourClass_LIBRARY)
#define YourClassSHARED_EXPORT Q_DECL_EXPORT
#else
#define YourClassSHARED_EXPORT Q_DECL_IMPORT
#endif

class YourClassSHARED_EXPORT YourClass : public QObject {

    Q_OBJECT

public:

    YourClass(int member = 0, QObject *parent = nullptr);
    ~YourClass();

    void init();
    int getMember();
    int * getMemberRef();
    void setMember(const int);
    const char * returnCharPtr();
    static void setSleep(const int);
    QList<YourStruct> getAListOfYourStruct();
    YourStruct * getYourStruct();
    int * returnAIntPtr();

private:
    int        m_member1;
    QTimer     m_timer;
    QMutex     m_mutex;
    static int s_sleep;
    YourStruct m_ys;

public slots:
    int processIdle();

};

void aFunction();
