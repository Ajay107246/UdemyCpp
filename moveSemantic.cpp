/*'*/
#include <iostream>
#include "moveSemantic.h"

using namespace std;

// Topic35, Copy &  move constr, copy & move assignment
//default constr
MoveSema::MoveSema()
{
}

//param constr
MoveSema::MoveSema(int value)
{
	m_pMoveInt = new int(value);
}

//copy constr
MoveSema::MoveSema(const MoveSema & objCpy)
{
	std::cout << "copy constr MoveSema(const MoveSema &)" << std::endl;
	m_pMoveInt = new int(*objCpy.m_pMoveInt);
}

//Topic 35,36, Move Constr
MoveSema::MoveSema(MoveSema && objMov)
{
	std::cout << "move constr MoveSema(MoveSema &&)" << std::endl;
	m_pMoveInt = objMov.m_pMoveInt;
	objMov.m_pMoveInt = nullptr;
}

//copy assignment
MoveSema &MoveSema::operator=(const MoveSema &objCpyAssign)
{
    // TODO: insert return statement here
	std::cout << "copy assignment operator=(const MoveSema&)" << std::endl;
	if(this== &objCpyAssign)
	{
		return *this;
	}
	delete m_pMoveInt;
	m_pMoveInt = new int(*objCpyAssign.m_pMoveInt);
	//m_pMoveInt = new int{};
}

//move assignment
MoveSema &MoveSema::operator=(MoveSema &&objMovAssign)
{
    // TODO: insert return statement here
	std::cout << "move assignment operator=(const MoveSema&& objMovAssign)" << std::endl;
	if (this == &objMovAssign)
	{
		/* code */
		return *this;
	}
	delete m_pMoveInt;
	m_pMoveInt = objMovAssign.m_pMoveInt;
	objMovAssign.m_pMoveInt = nullptr;
	return *this;
}

int MoveSema::getValueMov() const
{
    return *m_pMoveInt;	//segementation fault
}

void MoveSema::setValueMov(int value)
{
	/* probably solution
	if(p_moveInt == nullptr)
    {
        p_moveInt = new int{};  //solution
    }
	*/
	*m_pMoveInt = value;	//segementation fault
	
}

MoveSema::~MoveSema()
{
	std::cout << "~MoveSema()" << std::endl;
}

MoveSema Addvalue(const MoveSema &aInt, const MoveSema &bInt)
{
	MoveSema temp;	//state of temp was not copied, moved to that temporary
	temp.setValueMov(aInt.getValueMov() + bInt.getValueMov());
	return temp;
}

