/*Topic36, std:;move Function*/
#pragma once
#include <iostream>

class moveFunction
{
    int *p_moveInt; 
    public:
    //default constr
    moveFunction();
    //param constr
    moveFunction(int value); //:p_moveInt{value}{}
    //copy constr
    moveFunction(const moveFunction &obj);//:p_moveInt{obj.p_moveInt}{}
    //move constr
    moveFunction(moveFunction &&obj);

    //copy assignment
	moveFunction & operator=(const moveFunction & obj);
    //Move assignment
	moveFunction & operator=(moveFunction && obj);

    //getValueMoveFun
    int getValueMoveFun();
    //setValueMoveFun
    void setValueMoveFun(int value);
    //destructor
    ~moveFunction();

};