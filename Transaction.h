#pragma once
//#include "Checking.h"
#include "Account.h"

/*Topic53-3, virtual keyword, Transaction module to perform transation on checking amount

we cannot perform transaction on saving
cause we have hardcoded the arguemtn Checking *pAccout inside Transaction method below
tightly coupled with Checking class as included header
any changes in Checking, affect on Transaction

NOTE:
base class represents all its child classes
contain common behavior of all its children
base class obj points to any of its child class obj.
but that obj needs to be *ptr/&ref
base class ptr/ref can points to its any of class /obj
->replace Checking -> Account
*/

//void Transaction(Checking *pAccount);
/*
//Transaction module deoends only on base class
//does not known about child classes
//now we can perform transaction on SAving as well -> main()
*/
void Transaction(Account *pAccount);
/*Topic58-1, dynamic_cast<> can also work with reference*/
void Transaction(Account &pAccount);    //overloaded Account object
