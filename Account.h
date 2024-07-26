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
    /* description:
    e.g. if create ->
    (1)
    Saving *acc = new Saving("Bob",500, 0.5f ); //create a object on heap (local obj -> without ptr obj)
    ---
    delete acc; // we have to delete this ptr
    ---
    output:
    Accont()
    Saving()
    ~Accont()
    ~Saving()
    ---> this will call all constr & destructor 
    (2)
    base class ptr/ref can points to any of its derived class object
    e.g.
    Account *acc = new Saving("Bob",500, 0.5f ); //acc ptr can points to any of its child class
    ---
    delete acc; // we have to delete this ptr
    output:
    Accont()
    Saving()
    ~Accont()
    
    delete acc -> called based on its type -> Account
    want-> call to destructor should based on obj Account ptr pointing at 
    -> *acc -> Saving() -> decided at runtime
    i.e. compiler should generate polyorphic call to destructor of Account ptr -> *acc
    ---> for this reason -. destructor of base should be virtual
    virtual ~Account();
    in this case --->
    output:
    Accont()
    Saving()
    ~Accont()
    ~Saving()
    
    */

    const string getName()const;
    float getBalance()const;
    int getAccountNum()const;
    
    virtual void accumulateInterest();
    virtual void withdrawAmount(float amount);
    void dispositAmount(float amount);
    virtual float getInterestRate()const;

};