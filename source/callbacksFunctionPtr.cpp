#include "../header/callbacksFunctionPtr.hpp"
#include<iostream>

/*
    73-2, added function ptr prototype and second arg for sort(), and modify condition
*/
template <typename T, int size>
inline void sort(T (&arr)[size], comparator comp)
{
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-1; ++j)
        {
            /*
                if user defined array used, then multiple copies will created
                to avoid this, move semantics can useful
                call for comparator function (predicate)
                predicate is function that return boolean value
                when sort() algo is used, usr has to create a predicate and pass as arg to this function
                check Comp() function definition as below

                using function pointer, simplifies usage of sort() algo
                sorting control how it should be performed 
                
                for array of strings, implement a predicate function that compares string
                using strcmp, sort() algo become more flexible

                however one limitation, sort() function template that instantiate at compile time
                (comp(arr[j],arr[j+1])) about expression ?
                its invocation of function through its address, cause function is invoked through its address
                it cannot be optiomized, i.e. this function comp() cannot be inlined

                disadvantage of function ptr:
                1. cannot be optimized by compiler
                2. they points to global function which cannot have a state
                e.g.
                how many comparison have been made? -> store info in variable which cannot be a local variable
                even try to store the state in variable, state will be shared between different invokations of this (predicate) function
                so, second arg of sort() is callback and its implemented through a function pointer
                
                callbacks can also be implemented using function objects
            */

            if (comp(arr[j],arr[j+1])) //called comparator here
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = std::move(temp);
            }
        }
    }
}

bool CompAsc(int x, int y)
{
    return x > y;   //used > operator as sorting ascending order and pass this function as arg in sort()
}

bool CompDisc(int x, int y)
{
    return x < y;   //used < operator as sorting descending order and pass this function as arg in sort()
}

/*    

*/
void all_callbacksFunctionPtr_methods() 
{
    int arr[]{9,5,1,7,0,6};
    for (auto x: arr)
    {
        std::cout << x << ' '; 
    }
    std::cout << std::endl; 
    
    sort(arr, CompAsc);
    sort(arr, CompDisc);

    for (auto x: arr)
    {
        std::cout << x << ' '; 
    }
    std::cout << std::endl;
    /*
        output:
        Topic73, callbacks - funtion pointer revisit for lymbda expression
        1 5 9 7 3 6
        1 3 5 6 7 9

        output:
        Topic73, callbacks - funtion pointer revisit for lymbda expression
        9 5 1 7 0 6
        9 7 6 5 1 0
    */
}