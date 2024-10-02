#pragma once
#ifndef EXPLICITSPECIALIZATION__H
#define EXPLICITSPECIALIZATION__H

#include <iostream>

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
