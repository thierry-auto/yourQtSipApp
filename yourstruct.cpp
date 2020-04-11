#include <iostream>

#include "yourclass.h"

YourStruct::YourStruct(int member1, char member2) {

    m_member1 = member1;
    m_member2 = member2;
}

YourStruct::YourStruct(const YourStruct & other) {

    m_member1 = other.m_member1;
    m_member2 = other.m_member2;
}

YourStruct YourStruct::operator = (const YourStruct & other) {

    m_member1 = other.m_member1;
    m_member2 = other.m_member2;

    return *this;
}

void YourStruct::printMember() const {

    std::cout << "this->m_member1=" << this->m_member1 << std::endl;
    std::cout << "this->m_member2=" << this->m_member2 << std::endl;
}
