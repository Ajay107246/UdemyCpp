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

inline void PrintVariadic();

//Template param pack
template<typename T, typename... Params>
//Function parma pack
void PrintVariadic(T &&a, Params&&... args)
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
    //cout << sizeof...(args) << endl; //3 2 1 0
    //cout << sizeof...(Params) << endl; //3 2 1 0
    // cout << a << ',' ; // 12.534, need ',' seperator, but this will print extra , at end
    // we can avoid printing extra seperator by using variadic sizeof operator
    // can be used to count num of args in function param pack and template param pack.
    
    /*
        error: //no type named 'type' in 'struct std::enable_if<false, void>', 
        no match for 'operator<<' (operand types are 'std::ostream' {aka 'std::basic_ostream<char>'} and 'Integer_forward')

        **solution**: error resolved by adding operator<< method in Integer_forward class.
        this is to allow it access to the private members of the Integer_forward class
        link: https://sl.bing.net/bdpRc5IAQvs 

        INFO:
        Access to Private Members: By making operator<< a friend function,
        it can directly access the private member value of the Integer_forward class.
        This is necessary because operator<< needs to output the value stored in the Integer_forward object.
        
        Encapsulation: Even though the friend function has access to private members,
        it doesn’t break encapsulation because it’s a controlled way to allow specific external functions to access private data.
        This is better than making the member public just for the sake of one function.
        
        Consistency: Defining operator<< as a friend function ensures that the 
        syntax for outputting Integer_forward objects is consistent with other types in C++. 
        It allows you to use std::cout << obj; seamlessly.
    */
    std::cout << a; 
    if (sizeof...(args) != 0)
    {
        cout << ',';
    }
    
    /*
        Integer_forward {2} -> passing as R-value, in recursive call, it became L-value
        -> whether pass R/L-value, they will appropriately forwarded to next recursive call
    */
    PrintVariadic(std::forward<Params>(args)...); 

    /*
        if we pass user defined types to function then multiple copies created
        we are passing by value, now pass pass by const reference
        use perfect forwarding here ->
        now replace L-value reference arg to R-value reference.
        void PrintVariadic(const T &a, const Params&... args) -> void PrintVariadic(T &&a, Params&... args)

        
    */
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

/*
Assignement:
Create a factory that creates an instance of some type T, initializes it with arguments and returns it.

Here are some usage examples of the factory.

int *p1 = CreateObject<int>(5) ;
 
std::string *s = CreateObject<std::string>() ;//Default construction
 
Employee * emp = CreateObject<Employee>(
"Bob",    //Name
101,      //Id
1000) ;   //Salary
 
Contact *p = CreateObject<Contact>(
"Joey",                //Name
987654321,             //Phone number
"Boulevard Road, Sgr", //Address
"joey@poash.com") ;    //Email

*/