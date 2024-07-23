#include <iostream>
#include  <stdexcept>
#include "Account.h"

using namespace std;

/*
Account::Account()
{
}
*/

int Account::s_ANGenerator = 1000;
Account::Account(const string &name, float balance):
m_Name(name), m_balance(balance)
{
    m_Accno = ++s_ANGenerator;
}

Account::~Account()
{
}

const string Account::getName() const
{
    return m_Name;
}

float Account::getBalance() const
{
    return m_balance;
}

int Account::getAccountNum() const
{
    return m_Accno;
}

void Account::accumulateInterest()
{
    //different account -> different ROI
    //empty definition
}

void Account::withdrawAmount(float amount)
{
    if (amount < m_balance && m_balance > 0)
    {
        m_balance -= amount;
    }
    // else if (amount < 0)
    // {
    //     
    //     throw invalid_argument("Can not withdraw negative amount!");
    // }
    else
    {
        /*handle cases of negative balance or negative amount, onstead printing it
        cout << "Insufficient balance!" << endl;
        */
        throw runtime_error("Insufficient balance! Can not have negative balance!");
    }
}

void Account::dispositAmount(float amount)
{
    if(amount < 0)
    {
        throw invalid_argument("Can not deposit negative amount");
    }
    m_balance += amount;
}

float Account::getInterestRate() const
{
    //Interest will be implemented by child classes
    return 0.0f;
}
