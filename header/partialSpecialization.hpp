#pragma once
#ifndef PARTIALSPECIALIZATION__H
#define PARTIALSPECIALIZATION__H

#include <iostream>
#include <vector>

template<typename T, int columns>
class partialSpecialization
{
    T *m_partialData;
    public:
    partialSpecialization(T  *data):m_partialData(data){}
    void Print()
    {    
        std::cout << "columns: " << columns << std::endl;    //Topic69: partial
        std::cout << "{" << *m_partialData << "}" << std::endl;
    }
    T * getPartialData()
    {
        return m_partialData;
    }
};

/*
    69-2, first param : T, second: 80 (value)
    based on this, decide implmentation of class method
*/
template<typename T>
class partialSpecialization<T, 80>
{
    T *m_partialData;
    public:
    partialSpecialization(T  *data):m_partialData(data){}
    void Print()
    {    
        std::cout << "Using 80 columns: " << std::endl;    //Topic69: partial
        std::cout << "{" << *m_partialData << "}" << std::endl;
    }
    T * getPartialData()
    {
        return m_partialData;
    }
};

//to call all method from class partialSpecialization
void all_partial_specialization_methods();

#endif
#pragma endregion

