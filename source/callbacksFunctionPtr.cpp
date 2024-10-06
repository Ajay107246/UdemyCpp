#include "../header/callbacksFunctionPtr.hpp"
#include<iostream>


template <typename T, int size>
inline void sort(T (&arr)[size])
{
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-1; ++j)
        {
            /*
                if user defined array used, then multiple copies will created
                to avoid this, move semantics can useful
            */
            if (arr[j]> arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void all_callbacksFunctionPtr_methods()
{
    int arr[]{1,5,9,7,3,6};
    for (auto x: arr)
    {
        std::cout << x << ' '; 
    }
    std::cout << std::endl; 
    sort(arr);
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
    */
}