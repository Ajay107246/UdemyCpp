/*
SWR: 
Add the Checking class to the hierarchy. 
It does not have any interest rate, therefore, 
it will not implement the corresponding member functions.
The only difference is that the account mandates the balance should not fall below 50. 
So, you'll have to re-implement the Withdraw function accordingly. 

You should proceed only after implementing the entire Account hierarchy.
	
*/
#pragma once
#include "Account.h"
//#include "Saving.h"

using namespace std;

class Checking : public Account
{
    float m_MinimumBalance;
    public:

    /*
    NOTE:
    with Checkig Ch("bob", 500);, 
    not needed below Checking constr, so that automatically constr of Account class will invoke here
    but since we have defined data member with min_balance amount
    we need this constr
    */
    using Account::Account; 
    Checking(const string &name, float balance,float minbalance);
    
    /*
    if you miss virtual at base class, 
    error:'void Checking::withdrawAmount(float)' marked 'override', but does not override
    */
    void withdrawAmount(float amount)override;  
    float getMinimumBalanace()const;
    ~Checking();

};