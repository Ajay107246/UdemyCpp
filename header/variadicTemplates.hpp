#pragma once
#ifndef VARIADICTEMPLATE__H
#define VAIADICTEMPLATE__H
#include <iostream>

using namespace std;

/*
    Variadic Template: these templates are functions and classes that accepts arbitary number of args
    e.g. printf() can accepts any number of args, internally implemented through MACROs
    cause of MACROs, it is not type safe
    can not accepts references as an arguments
    1.  this can be implement using c++11 -> initializer_list
        with initializer_list args have to be of same type
*/

template<typename T>
void PrintVariadic(initializer_list<T> args)
{
    /* using range based for loop to access the int elements */
    for (const auto &x : args)
    {
        cout << x << " ";
    }
}

void all_variadicTemplates_method();

#endif //VARIADICTEMPLATE__H
#pragma endregion