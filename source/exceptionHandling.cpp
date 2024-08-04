#include <iostream>
#include "../header/exceptionHandling.hpp"

using namespace std;

int processRecords(int count)
{
    /*
    using malloc, since it return null when no mem allocation done
    it cannot alocate very large memory as called from allocated from main()
    new throws an expection and that will be used later as an example for this program
    */
    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr)
    {
        /*cout << "failed to allocate a very large memory using numeric_limits::max()" << endl;
        return -1;*/
        throw std::runtime_error("failed to allocate a very large memory");
    }
    
    for(int i =0; i< count;++i)
    {
        pArray[i];
    }
    free(pArray);
    return 0;
}