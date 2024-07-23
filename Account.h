#pragma once
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Account
{
    private:
    string m_Name;
    int m_Accno;
    static int s_ANGenerator;
    protected:
    float m_balance;
    public:
    Account(const string &name, float balance);
    virtual ~Account();

    const string getName()const;
    float getBalance()const;
    int getAccountNum()const;
    
    virtual void accumulateInterest();
    virtual void withdrawAmount(float amount);
    void dispositAmount(float amount);
    virtual float getInterestRate()const;

};