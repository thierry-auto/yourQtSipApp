#pragma once

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
