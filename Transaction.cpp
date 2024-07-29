#include <iostream>
#include "Transaction.h"
#include "Checking.h"
using namespace std;


//void Transaction(Checking *pAccount)
void Transaction(Account * pAccount)
{
    cout << "!Transaction started!" << endl;
    cout << "Initial balance: " << pAccount->getBalance() << endl;
    pAccount->dispositAmount(100);
    pAccount->accumulateInterest();

    /*
    below we do blindly down cast pAccount to pChecking 
    -> leads to undefined bahavior to Saving: interestRate()
    -> RTTI concept come n picture to check
    -> pAccount pointing to which object/to Checking object/not
    -> so use typeid(Classobj) then proceed with next action
    
    if(typeid(*pAccount) == typeid(Checking))
    {
        Checking *pChecking = static_cast<Checking*>(pAccount); 
        cout << "Minimum Balanceof Checking: " << pChecking->getMinimumBalanace() << endl;
    }
    Typeid, dyanamic_cast<>:
    1. this will check whether type cast can be perfomed or not
	2. if perfomed, it returns type casted pointer, otherwise nullptr
	3. this does the same opeation as above with same output
    4. Topic58-1, dynamic_cast<> can also work with reference, 
    5. cannot be a nullptr, if() is not requried, it will throw expection
    */
    Checking *pChecking = dynamic_cast<Checking*>(pAccount);
    if(pChecking!=nullptr)
    {
        cout << "Minimum Balanceof Checking: " << pChecking->getMinimumBalanace() << endl;
    }
    pAccount->withdrawAmount(170);
    /*
    compiler does not know what ptr:pAccount pointing at/which method (from child obj).
    to tell the compiler to generate the call these functions
    such that compiler invoke correct method form obj
    have to mock function with special keyword -> "virtual"
    */
    cout << "Interest Rate: " << pAccount->getInterestRate() << endl;   //!Compiler is not calling getInterestRate() method from saving : outut=0 !
    cout << "Final Balance: " << pAccount->getBalance() << endl;
}

// replace * ptr with & reference, access operator -> with '.'
void Transaction(Account &pAccount)
{
    cout << "!Transaction started!" << endl;
    cout << "Initial balance: " << pAccount.getBalance() << endl;
    pAccount.dispositAmount(100);
    pAccount.accumulateInterest();

    /*
    below we do blindly down cast pAccount to pChecking 
    -> leads to undefined bahavior to Saving: interestRate()
    -> RTTI concept come n picture to check
    -> pAccount pointing to which object/to Checking object/not
    -> so use typeid(Classobj) then proceed with next action
    
    if(typeid(*pAccount) == typeid(Checking))
    {
        Checking *pChecking = static_cast<Checking*>(pAccount); 
        cout << "Minimum Balanceof Checking: " << pChecking->getMinimumBalanace() << endl;
    }
    Typeid, dyanamic_cast<>:
    1. this will check whether type cast can be perfomed or not
	2. if perfomed, it returns type casted pointer, otherwise nullptr
	3. this does the same opeation as above with same output
    4. Topic58-1, dynamic_cast<> can also work with reference, 
    5. cannot be a nullptr, if() is not requried, it will throw expection
    */
    Checking &pChecking = dynamic_cast<Checking&>(pAccount); //referece & -> cannot be a nullptr, it will throw exception, bad type_cast
    //if(pChecking!=nullptr)
    //{
    cout << "Minimum Balanceof Checking: " << pChecking.getMinimumBalanace() << endl;
    //}
    pAccount.withdrawAmount(170);
    /*
    compiler does not know what ptr:pAccount pointing at/which method (from child obj).
    to tell the compiler to generate the call these functions
    such that compiler invoke correct method form obj
    have to mock function with special keyword -> "virtual"
    */
    cout << "Interest Rate: " << pAccount.getInterestRate() << endl;   //!Compiler is not calling getInterestRate() method from saving : outut=0 !
    cout << "Final Balance: " << pAccount.getBalance() << endl;
}
