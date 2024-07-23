#pragma once
#include <iostream>
#include "Account.h"


class Saving : public Account
{
    int m_Rate;
    public:
    Saving(const string &name, float balance, float rate);
    float getInterestRate()const override;
    void accumulateInterest()override;
        
    ~Saving();


};