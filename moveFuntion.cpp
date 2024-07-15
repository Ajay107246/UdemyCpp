/*Topic36, std:;move Function*/
#include <iostream>
#include "moveFuntion.h"

using namespace std;

moveFunction::moveFunction()
{
    cout << "moveFunction()" << endl;
}

//param constr
moveFunction::moveFunction(int value)
{
    cout << "moveFunction(int)" << endl;
    p_moveInt = new int(value);
}

//copy constr
moveFunction::moveFunction(const moveFunction &obj)
{
    cout << "moveFunction(const moveFunction &)" << endl;
    p_moveInt = new int(*obj.p_moveInt);
}

//move constr
moveFunction::moveFunction(moveFunction &&obj)
{
    cout << "moveFunction(const moveFunction &&)" << endl;
    p_moveInt = obj.p_moveInt;
    obj.p_moveInt = nullptr;
}

moveFunction &moveFunction::operator=(const moveFunction &obj)
{
    // TODO: insert return statement here
    std::cout << "copy assignment operator=(const moveFunction&)" << std::endl;
	if(this== &obj)
	{
		return *this;
	}
	delete p_moveInt;
	p_moveInt = new int(*obj.p_moveInt);
	//m_pMoveInt = new int{};
}

moveFunction &moveFunction::operator=(moveFunction &&obj)
{
    // TODO: insert return statement here
    std::cout << "move assignment operator=(const moveFunction&& obj)" << std::endl;
	if (this == &obj)
	{
		/* code */
		return *this;
	}
    if(p_moveInt == nullptr)
    {
        p_moveInt = new int{};  //solution
    }
	//delete p_moveInt; //Error:Exception has occurred. Unknown signal
	p_moveInt = obj.p_moveInt;
	obj.p_moveInt = nullptr;
	return *this;
}

//getter
int moveFunction::getValueMoveFun()
{
    cout << "getValueMoveFun()" << endl;
    return *p_moveInt;
}

void moveFunction::setValueMoveFun(int value)
{
    cout << "setValueMoveFun()" << endl;
    if(p_moveInt == nullptr)
    {
        p_moveInt = new int{};  //solution
    }
    *p_moveInt = value;
}

moveFunction::~moveFunction()
{
    cout << "~moveFunction()" << endl;
}
