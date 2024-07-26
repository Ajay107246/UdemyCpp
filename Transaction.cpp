#include <iostream>
#include "Transaction.h"

using namespace std;


//void Transaction(Checking *pAccount)
void Transaction(Account * pAccount)
{
    cout << "!Transaction started!" << endl;
    cout << "Initial balance: " << pAccount->getBalance() << endl;
    pAccount->dispositAmount(100);
    pAccount->accumulateInterest();
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