#pragma once
#include <iostream>
#include <cstdint>
#include <cstdio>

using namespace std;

class MoveSema
{
	int *m_pMoveInt;
	public:
	//Default constr
	MoveSema();

	//Parameterized constr
	MoveSema(int value);

	//copy constr
	MoveSema(const MoveSema &objCpy);

	//Move Constr
	MoveSema(MoveSema &&objMov);

	//from below 2xconstr we can handle underline resources of class
	//copy assignment
	MoveSema & operator=(const MoveSema & objCpyAssign);

	//Move assignment
	MoveSema & operator=(MoveSema && objMovAssign);

	int getValueMov()const;
	void setValueMov(int value);
	~MoveSema();
};

MoveSema Addvalue(const MoveSema &, const MoveSema &);

/*Topic35, copy & move ->  constr, assignment
Explanation: 
Any function that is synthesized in Number class (by compiler),
will internally call correspoding function of MoveSema class
*/

class Number
{
	MoveSema m_Value{};
	public:
	//param constr
	Number(int value):m_Value{value}{}
	//copy constr for Number, and you will not see any move operation and move operation get deleted
	Number(const Number &n):m_Value{n.m_Value}{}

	//when custom implementation of move operation provided, then other move and copy operations become deleted
	//compiler won't create a copy at auto nn2{nn1};, and can't copy assign at nn2 = nn1;
	//also nn3 = createNumber(3); -. move assignment is also deleted
	Number(Number &&n):m_Value{std::move(n.m_Value)}{}
	
	//commenting /replacing std::move operation as below also should work
	//Number(Number &&n) =default; //move operation, synthsized by default specifier again
	
	//below copy operation, synthsized by default specifier again
	//copy will work, but copy assignement (nn2 = nn1) won't work
	//compiler won't synthesized here, cause provided atleast one custom move operation
	//Number(const Number &n) =default; 
	
	//provide default copy assignment
	//then, copy assignement (nn2 = nn1) will work
	//Number & operator=(const Numer&)=default; 

	//Number n1; // won't work 
	// need to provide default specifier
	//Number()=default;

	//no need to implement other move opearation as well
	// simply implement default specifier
	// compiler will synthesized a default impl. of mvoe assignement
	//this impl. internally call move assignment if MoveSema class
	Number & operator =(Number &&)=default;	//move operation
	
	//and there is no suppport for copy in class now.
	//if destructor is privided, there will no more call to move operation
	//by commenting -> Number(const Number &n):m_Value{n.m_Value}{}
	~Number();
};

Number createNumber(int num)
{
    Number n{num};
    return n;
}
