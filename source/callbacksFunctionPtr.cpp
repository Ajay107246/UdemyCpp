#include "../header/callbacksFunctionPtr.hpp"
#include<iostream>

/*
    73-2, added function ptr prototype and second arg for sort(), and modify condition
    73-3, Callback function object, and added 3rd arg in template
*/
template <typename T, int size, typename comparator>
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
    /*
        Topic73-3: callbacks function objects
        to invoke function call operator, first create an instance of struct and invoke function call
        CompAsc(5,3);//Global function call
        CompAsc(5,3); //member function call, internally resolve as CompAsc.operator()(5,3); obj.opearator(operator itself)(args...); 
        in sort(), comp(arr[j],arr[j+1]) -> comp is ptr to function
        if generalize this thing, also use function object here, and possible by converting this Comparator into template type
        
        comment out alias and specify one more template arg 
        template<typename T, int size, typename Comparator> : type of Comparator is unknwon until invoke sort() function
        
        for invokation of sort() function, sort(arr, CompDisc); -> CompDisc is address of function, type -> function ptr
        no changes are needed in sort() function invication

        inlining the function operator() call and optiomize the code.
        instead of inlined, advantage of function object as callback -> its faster than function ptr
        CompAsc -> object, instance of struct
        meaning : it can have a state, possible to store sime state different invocations of this function
        function objects have a state, while global function do not have a state
        in STL, algo that take a callback can either accept a function ptr or function object as callback.
        in most cases, function objects is preferable to pass cause its more efficient

        RECALL:
        1. function object:
        object with overloaded function call operator -> functor
        call to overloaded function call operator resembles a global function call
        i.y. function object can be used as callback instead of  function ptr with templates
        its more efficient than function ptr
        function object -> implemented as struct rather than classes
        
        invoked through an object
        static in nature
        must be specified at compiler time
        easy to optiomize
        fast
        can store state 
        
        **in c++11, there is better way to implements callbacks through lambda expression**

        2. function ptr:
        invoked through a ptr
        dynamic in nature
        can be specified at runtime
        difficult to optimize cause function is invoked through address
        its slow cause dynamic in nature
        cannot store state

    */
    CompAsc(5,3);//Global function call
    callbacksFunctionObject CompAsc;// call_fObj;
    // call_fObj(5,3); //internally resolve as call_fObj.operator()(5,3); obj.opearator(operator itself)(args...); 
    CompAsc(5,3); //member function call, internally resolve as CompAsc.operator()(5,3); obj.opearator(operator itself)(args...); 

    /* Topic72: callbacks function ptr  */
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

        Topic73, callbacks - funtion pointer & object (fast) revisit for lambda expression
        9 5 1 7 0 6
        9 7 6 5 1 0
    */
}