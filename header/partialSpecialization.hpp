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

/*
    69-3: usage of smart pointer with template class
    RAII concept, used for creating smart pointers with templates, 
    smart pointer can be created that can work with any type.
    SmartPointer class, contains a constructor through we initialize this member and
    overloaded arrow operator (->) & also asterist (*) operator to return value at address
    finally, destructor which will free the memory of internal pointer then use SmartPointer class and 
    it'll automatically free mempry at end of scope    print the value using * operator : 3
*/

template<typename T>
class SmartPointer
{
    T *m_sPtr;
    public:SmartPointer(T *ptr):m_sPtr(ptr){}
    // overloaded arrow operator (->) & also asterist (*) operator to return value at address
    T * operator ->()
    {
        return m_sPtr;
    }

    T & operator *()
    {
        return *m_sPtr;
    }

    ~SmartPointer()
    {
        delete m_sPtr;
    }
};

/*
    SmartPointer class template with arrat type
    this class SmartPointer instantiated with any type, 
    but only used if it array type 
*/
template<typename T>
class SmartPointer<T[]> 
{
    T *m_sPtr;
    public:SmartPointer(T *ptr):m_sPtr(ptr){}
    // overloaded arrow operator (->) & also asterist (*) operator to return value at address
    /*
        these operators won't make sense and
        replaced with overloaded subscript operator
    T * operator ->()
    {
        return m_sPtr;
    }

    T & operator *()
    {
        return *m_sPtr;
    }
    */

    T & operator [](int index)
    {
        return m_sPtr[index];
    }

    //destructor will be updated with correct form of delete[] to free memory
    ~SmartPointer()
    {
        delete[] m_sPtr;
    }
};

//to call all method from class partialSpecialization
void all_partial_specialization_methods();

#endif
#pragma endregion

