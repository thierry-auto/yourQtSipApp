#pragma once

#include <QObject>
#include <QMutex>
#include <QTimer>
#include <QList>
#include <QSharedPointer>

#if defined(YourClass_LIBRARY)
#define YourClassSHARED_EXPORT Q_DECL_EXPORT
#else
#define YourClassSHARED_EXPORT Q_DECL_IMPORT
#endif

struct YourStruct {

    int  m_member1;
    char m_member2;

    YourStruct(int member1 = 17, char member2 = 0x45);
    YourStruct(const YourStruct & other);
    YourStruct operator = (const YourStruct &);

    void set() {

        m_member2 = 0x41;
    }

    void printMember() const;
};

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
