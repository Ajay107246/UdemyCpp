#include <iostream>
#include "Checking.h"

/*
NOTE:
we need this user-defined constr with calling (base class) Account::() constr
if we don't call constr of Account, Checking class will invkde default constr of Account class. -> not want this 
to avoid this -> using Account::Account; is used in Checking class
*/

Checking::Checking(const string &name, float balance, float minbalance):Account(name, balance), m_MinimumBalance(minbalance)
{
}
//with Checkig Ch("bob", 500);this constr is not needed since we used -> using Account::Account; in Checking class


Checking::~Checking()
{
}

void Checking::withdrawAmount(float amount)
{
    if((m_balance - amount) > m_MinimumBalance)
    {
        Account::withdrawAmount(amount);    //we can write own implementation or call Account:: withdrawAmount()
    }
    else
    {
        cout << "\nChecking():Invalid Amount!" << endl;
        //throw runtime_error("Insufficient balance! Enter valid Amount!");
        //throw invalid_argument("Insufficient balance! Enter valid Amount!");
    }
}

float Checking::getMinimumBalanace() const
{
    return m_MinimumBalance;
}

