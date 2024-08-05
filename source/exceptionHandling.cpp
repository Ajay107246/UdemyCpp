#include <iostream>
#include <memory>
#include <vector>
/*user-defined headers*/
#include "../header/exceptionHandling.hpp"

using namespace std;

class testStk{
    public:
    testStk() { cout << "testStk():constr. Acquire resource !"<< endl;}
    ~testStk() { cout << "~testStk():destructor, Release resource!"<< endl;}
};
class testHeapPtr{
    public:
    testHeapPtr() { cout << "testHeapPtr():constr. Acquire resource !"<< endl;}
    ~testHeapPtr() { cout << "~testHeapPtr():destructor, Release resource!"<< endl;}
};
int processRecords(int count)
{
    /* 61-4
    stck unwinding: only destroy local objects
    just to check, after exception occurs, resource get released or not from stack
    */
    testStk Ts;    

    /* 61-5
    if object is created on heap , they won't be destroyed 
    and memory can be leaked .
    if processRecords() throws an exception, then delete pT won't get execute
    so, object won't be destroyed, leads to memory leak

    !RAII can be used to properly destroyed the object once exception is thrown
    using smart_ptr! 
    */
    testHeapPtr *pHT = new testHeapPtr;

    /*
    output:
    Topic61, Topic61-1: exception handling part-1!
    std::numeric_limits<int>::max()= 2147483647
    testStk():constr. Acquire resource !
    testHeapPtr():constr. Acquire resource ! -> !destructor won't get called cause of early exception! 
    ~testStk():destructor, Release resource!
    catch exception: Count should be greater than 10    
    */

    unique_ptr<testHeapPtr> tUni(new testHeapPtr);  
    /* 61-6
      !RAII- smart_ptr, auto dealllocation/destroy of object + in case of exception!
    here, it is object, not a ptr

   output:
   Topic61, Topic61-1: exception handling part-1!
    std::numeric_limits<int>::max()= 2147483647
    testStk():constr. Acquire resource !
    testHeapPtr():constr. Acquire resource ! -> 61-5: !destructor won't get called cause of early exception! 
    testHeapPtr():constr. Acquire resource !
    ~testHeapPtr():destructor, Release resource! -> !destructor gets called cause use of smart_ptr (auto deallocation of memory)! 
    ~testStk():destructor, Release resource!
    catch exception: Count should be greater than 10
   */

    if ( 0 < count < 10)
    {
        throw std::runtime_error("Count should be greater than 10");
    }
    else
    {
        throw std::out_of_range("Count should be in range 0 ~ 10");
    }
    
    /*
    using malloc, since it return null when no mem allocation done
    it cannot alocate very large memory as called from allocated from main()
    new throws an expection and that will be used later as an example for this program
    */

    /* 61-7 
    dynamic array -> vector
    
    */
    vector<int> pV;
    pV.reserve(count);
    //processRecords
    for(int i =0 ; i< count ; ++i)
    {
        pV.push_back(i);
    }
    /*
    output:
    Topic61, Topic61-1: exception handling part-1!
    std::numeric_limits<int>::max()= 2147483647
    testStk():constr. Acquire resource !
    testHeapPtr():constr. Acquire resource !
    testHeapPtr():constr. Acquire resource !
    ~testHeapPtr():destructor, Release resource!
    ~testStk():destructor, Release resource!
    catch exception: Count should be greater than 10
    */

    int *pArray = (int*)malloc(count * sizeof(int));    //61-2
    int *pNew = new int[count]; //61-3
    if (pArray == nullptr)
    {
        /*cout << "failed to allocate a very large memory using numeric_limits::max()" << endl;
        return -1; 61-2*/
        throw std::runtime_error("failed to allocate a very large memory");
    }
    
    for(int i =0; i< count;++i)
    {
        pArray[i];
    }
    free(pArray);
    delete[] pNew;
    delete pHT;
    return 0;
}