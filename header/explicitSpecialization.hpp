#pragma once
#ifndef EXPLICITSPECIALIZATION__H
#define EXPLICITSPECIALIZATION__H

#include <iostream>
#include <vector>

template<typename T>
class explicitSpecialization
{
private:
    T *m_pData;
public:
    explicitSpecialization(T *data): m_pData(data){}    //custom/param constr with common data type (here int, float)
    void Print();
    T * getData();

    // ~explicitSpecialization();
};

/*
    when creation of template specialization, template arg should be empty
    need to specify type next to class name<type>
    class explicitSpecialization<char*>{};
    this become explicit specialization of class -> explicitSpecialization of the char* type

*/
template<>
class explicitSpecialization<char*>
{
    private:
    char *m_pData;
    public:
    explicitSpecialization(char * data) : m_pData(data){}
    // void printExplicitSpecial();
    void Print()
    {
        std::cout << '{' << m_pData << '}' << std::endl;    //no dereferencing done here for m_pData
    }
    // char * getExplicitData();
    char * getData()
    {
        return m_pData;
    }
};

//68-3, explicit specialization for vector
/*
    'inline' Keyword: 
    If you need to define the function in the header file, you can use the inline keyword to avoid multiple definitions.
    This tells the linker to allow multiple definitions and to pick one
    OR
    inline Keyword: If you need to define the function in the header file, you can use the inline keyword to avoid multiple definitions.
    This tells the linker to allow multiple definitions and to pick one
    // Declaration of the specialization
    template <>
    void explicitSpecialization<std::vector<int>>::Print();

    definition in cpp:
    // Definition of the specialization
    template <>
    void explicitSpecialization<std::vector<int>>::Print() {
        std::cout << "Specialized Print for std::vector<int>" << std::endl;
    }

    output:
    68-3, explicit specialization for vector
    {1234}

*/
template<>
inline void explicitSpecialization<std::vector<int>>::Print()
{
    std::cout << '{';  /*<< m_pData <<*/
    for (const auto &x : *m_pData)
    {
        std::cout << x;
    }
    std::cout << '}' << std::endl;    //no dereferencing done here for m_pData
}

/*
    // 68-3, explicit specialization for vector can be done easily with char*,
    // and adding specialized method Print() with type vector 
template<>
class explicitSpecialization<std::vector<int>>
{
    private:
    std::vector<int> *m_pData;
    public:
    explicitSpecialization(std::vector<int> * data) : m_pData(data){}
    // void printExplicitSpecial();
    void Print()
    {
        std::cout << '{';  
        for (const auto &x : *m_pData)
        {
            std::cout << x;
        }
        std::cout << '}' << std::endl;    //no dereferencing done here for m_pData
    }
    // char * getExplicitData();
    std::vector<int> * getData()
    {
        return m_pData;
    }
};
*/

/*
    method to call from main.cpp for all feature of explicitSpecialization
*/
void all_explicitSpecialization_methods();



#endif //EXPLICITSPECIALIZATION__H
#pragma endregion
/*
inline void explicitSpecialization<char *>::printExplicitSpecial()
{
    std::cout << '{' << m_pData << '}' << std::endl;    //no dereferencing done here for m_pData
}

inline char *explicitSpecialization<char *>::getExplicitData()
{
    return m_pData;
}*/
