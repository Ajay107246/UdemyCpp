#include "../header/templateEx.hpp"

using namespace std;

/* Topic 64-1 Normal methods for some operation
 this increase the number of methods to handle different data types
*/
int iMAX(int x, int y)
{
    return x > y ? x:y;
}
float fMAX(float x, float y)
{
    return x > y ? x:y;
}

/* Topic64-2 : Template:
to avoid multiple methods with complex implementation
template useful to defined any kind of function/class that can handle any data types
until function template is not invoke, compiler will not generate the function by itself
e.g. in this case until MAX() is not invoke, compiler won't generate function in disassembler
this process ~ instanciation
compiler will examine the arguments of function'T and accordingly it will deduce the type of T
-> can create generalized SWC
-> such SWC can reuse in different situations
-> operates with any kind of data
-> compile time: no runtime cost are involve
-> library_ Active Template Lib, Window TL, Boost, POCO, ACE, etc uses template for implementation
-> e.g. function template
template <typename T>
T function(T args)
{
//statements
}
*/

/* Topic64-3, template instantiation:
1. template function / class only acts ass blurprint
2. compiler generates code form blueprint at compile time
3. known as template instantiation
4. occurs implicitly when ->
5. template is invoked
6. taking addr og function template
7. using explicit instant.
8. creating explicit specialization
9. full definition of template should be available
10. define in header file
*/


template <typename T>
T MAX(T x, T y)
{
    cout << "typeid(T).name()= " << typeid(T).name() << endl;
    return x > y ? x:y;
}

//explicite template instantiation
template char MAX(char x, char y);

void allTemplateMethods()
{
    //07.08.2024:
    auto numInt = iMAX(4,5);
    cout << "iMAX INT number: " << numInt << endl;
    auto numFloat = fMAX(9.4,5.9);
    cout << "fMAX FLOAT number: " << numFloat << endl;

    /*
    output:
    Topic64: Templates in c++(11)
    iMAX INT number: 5
    fMAX FLOAT number: 9.4
    */
    auto numGeneric = MAX(19.4,5.9);
    cout << "template MAX FLOAT number: " << numGeneric << endl;
    auto numGeneric2 = MAX<int>(9,5);
    cout << "template MAX INT number: " << numGeneric2 << endl;
    auto numGeneric3 = MAX(static_cast<double>(5),8.9);
    cout << "template MAX typecast Double number: " << numGeneric3 << endl;

    /*function template can also instantiated when you take its address.
    addr of MAX function, invoke for integer
    */
    int (*pfp)(int, int)= MAX<int>;  //MAX isn't invoked for INT type, but got addr of MAX here, later invoked for INT type

    //also explicitly instantiate function template
    
    /*
    output:
    typeid(T).name()= d
    template MAX FLOAT number: 19.4
    typeid(T).name()= i
    template MAX INT number: 9
    typeid(T).name()= d
    template MAX typecast Double number: 8.9
    */
}

/*
Assignemnt1:
Convert the following functions into templates

int Add(int x,int y) ; //Return the sum of two elements

int ArraySum(const int *pArr, size_t arrSize); //Returns the sum of array elements

int Max(const int *pArr, size_t arrSize) ; //Return the largest element in the array

std::pair<int,int> MinMax(const int *pArr, size_t arrSize) ; //Return the smallest and largest element in a pair

Take care to avoid copies of user-defined objects wherever applicable.

*/  