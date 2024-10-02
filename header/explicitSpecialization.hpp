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
    method to call from main.cpp for all feature of explicitSpecialization
*/
void all_explicitSpecialization_methods();



#endif //EXPLICITSPECIALIZATION__H
#pragma endregion


