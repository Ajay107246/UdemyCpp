#include "../header/templateEx.hpp"
#include <iostream>
#include <cstdint>

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

/*
explicit template instantiation
template specialization for specific data type
provides correct semantic for some  datatype
implement an algo optiomally for specific type
explicitly specialized function must be defined in cpp file
primary template definition should occur before specialization

template char Max(char x, char y);
template<> const char * Max(const char* x, const char *y)
{
    cout << "Max<const char *>(): " << endl;
    return strcmp(x,y) > 0 ? x:y;
}
*/
/*
template char Max(char x, char y)
{
    cout << "Max<const char *>(): " << endl;
    return strcmp(x,y) > 0 ? x:y;
}
*/

/* Non-type template arguments:
1. expression that computed at compile time within a template args list
2. must be a const expression (addr (static, ptr to var/func), ref, integrals, nullptr, enum)
3. part of template type
4. used by std::begin() & std::end() functions 
*/
template <int64_t size>
void Print()
{
    char butter[size];
    // size++; //cannot possible, error: increment of read-only location 'size'
    cout << "non type template size: " << size << endl;
}

/* function , return array that can be of any type */
template <typename T>
T Sum(T *pArr, uint32_t size)
{
    /*
    This initializes a variable Sum of type T to its default value. 
    The {} syntax ensures that Sum is zero-initialized, 
    which is important for types like integers or floating-point number
    */
    T Sum{};    //variable init, 
    for (size_t i = 0; i < size; i++)
    {
        /*
        if instance is not created -> T Sum{};
        error: overloaded function with no contextual type information
        cannot resolve overloaded function 'Sum' based on conversion to type 'int'
        */
        Sum+=pArr[i];   
    }
    return Sum;
}

/* function template with ref to array*/
template <typename T, uint32_t size>
T sumRef(T (&pArr)[size])
{
    /*
    This initializes a variable sumRef of type T to its default value. 
    The {} syntax ensures that sumRef is zero-initialized, 
    which is important for types like integers or floating-point number
    */
    T sumRef{};    //variable init, 
    for (size_t i = 0; i < size; i++)
    {
        sumRef+=pArr[i];   
    }
    return sumRef;
}

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

    /*Explicit specializations*/
    const char *a {"A"};    //this will hold the addr
    const char *b {"B"};    //this will hold the addr
    auto s = MAX(a,b);
    cout << "Primary template MAX: " << s << endl;

    /*
    !not working!
    auto sExpl = Max(a,b);
    cout << "Explicit template MAX: " << sExpl << endl;
    */
    /*
     output:
    typeid(T).name()= PKc
    Explicit template MAX: B
    */
    cout << "\nTopic64, non-type templates!" << endl;
    Print<3>(); // works fine
    //int i = 4;
    //Print<i>(); // not work, error: the value of 'i' is not usable in a constant expression 
    const int cI = 5;
    Print<cI>(); // works with const expression,possible for compiler to compute it at compile time
    int64_t j = 6;
    Print<sizeof(j)>(); // works with const expression

    //non type template size: 4
    /*
    output:
    Topic64, non-type templates!
    non type template size: 3
    non type template size: 5
    non type template size: 8
    */
    /* function return array of any type using template */
    int arr[] {1,2,3,4,5};
    int sumArr = Sum(arr, 5);
    cout << "sumArr with template: " << sumArr << endl;
    /*
    output:
    sumArr with template: 15

    using template/non-type template, we can skip size argument, or pass an array without its size as arg
    we need &ref[size], with exact size of array.
    */
    int arr1[] {3,7,4,6};
    //to get beginning iterator of this array
    auto it = begin(arr1);  //arg to this begin()is &ref[] to array only
    /*
    needed, ref to array with its actual size, if size wrong -> leads to an error
    also, it should work, with/without specifying its size using &ref[]
    */
    //int (&ref)[4] = arr1; //should work with/out this &ref[]
    int sumRefTot = sumRef(arr1);
    cout << "sumRef with template refArray: " << sumRefTot << endl;

    /*
    output:
    sumRef with template refArray: 20
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


Assignment III
For the functions in questions 2,3 & 4 in Assignment I above,

Modify to accept array by reference.

Specialize for an array of strings (const char *). Observe, the limitations.

Specialize for an array of std::strings. Compare with the previous implementation.

Define the specialized functions in a .h file and include it in multiple source (.cpp) files. Observe what happens.
*/  