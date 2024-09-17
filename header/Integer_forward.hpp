#pragma once
#ifndef INTEGER_FORWARD__H
#define INTEGER_FORWARD__H

#include <iostream>

using namespace std;

class Integer_forward
{
    int *m_pInt;
    public:
    //default constructor
    Integer_forward();
    
    //parameterized constr
    Integer_forward(int value);

    //copy constr
    Integer_forward(const Integer_forward &obj);

    //move constr
    Integer_forward(Integer_forward &&obj);

    //operator<< as friend function
    friend ostream& operator<<(ostream& os, Integer_forward& obj);

    int getForwardValue()const;
    void setForwardValue(int value);
    ~Integer_forward();
};


#endif //INTEGER_FORWARD__H
#pragma endregion