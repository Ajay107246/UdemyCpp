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
    2. using variadic template, can write a function accept any type ad number of argument
    e.g. 
    //template param pack
    template<typename... Params>
    ... -> ellipsis and used in varies places in cpp
    it senifies a variadic template, need to mentioned name that will represent variable num of type name
    Params doesn't represent typename, rather it is an alias to the list of typenames
    (pack of template typename)
    further Params will used in function to signify the arguments of function

    -> used in call catch block in exception handling

*/

//function to stop recursion once num of args = 0 
void PrintVariadic()
{   
    /*  leads to error: 
        multiple definition of `PrintVariadic()'; C:\Users\Shimpi\AppData\Local\Temp\cc5oVYX1.o:G:/CPP/2024/VSCode/UdemyCpp/header/
        variadicTemplates.hpp:31: first defined here
        collect2.exe: error: ld returned 1 exit status
        Build finished with error(s)
    */
}

//Template param pack
template<typename T, typename... Params>
//Function parma pack
void PrintVariadic(T a, Params... args)
{
    /* 
        1. using variadic template with any number of type and args
        template<typename... Params>
        (1, 2.5, 3, '4') -> args will expanded automatically by compiler at -> (Params... args)
        void PrintVariadic(Params... args)
        
        2. we can not access individual arg directly, instead rely on recursion
        in each recursive call the num of args will reduced by one.
        also, just like normal recursion to end the operation, we need to condition.
        
        3. here, in variadic template function, that will done by writing another PrintVariadic() function
        without using variadic template -> called as base case function
        ** write PrintVariadic() function to pass function parameter pack (args...)
        PrintVariadic(args...);
        
        4. compiler will invoke PrintVariadic() with same args that were passed in PrintVariadic()
        ** but compiler give a warning : runtime stackover flow because of infinite recursion
        so we need write a base case that will stop recursion.
        by passing one more arg to PrintVariadic() function.
        template<typename T, typename... Params>
        void PrintVariadic(T a, Params... args)

        5. This will give an error, 
            no matching fucntion call to 'PrintVariadic()' [expected 2 args and provided 0 arg]
        in each recursive call, the num of args is reduced by one, and PrintVariadic() will invoke 0 num of arg
        -> PrintVariadic(1, 2.5, 3, '4');
            1 : T a,  2.5, 3, '4' : (Params... args) fun param pack.
        
        -> PrintVariadic(2.5, 3, '4');
            num of param reduced by one
            2.5 : T a,  && 3, '4' : (Params... args) fun param pack.

        -> PrintVariadic(3, '4');
        
        -> PrintVariadic('4');
            '4' : T a -> here, when PrintVariadic(args...) invoked with 0 num of args

        -> PrintVariadic(); 
            using template instantiation, compiler will look for a function PrintVariadic() does not accept any arg
            and we dnt have a such function, but we can write PrintVariadic() with no args,
            this function will be act as base case function to stop recursion
    */
   PrintVariadic(args...);

}


template<typename T>
void PrintInitList(initializer_list<T> args)
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