#pragma once
#ifndef PERFECT_FORWARDING__H
#define PERFECT_FORWARDING__H
#include <iostream>
#include <string>

#include "Integer_forward.hpp"

using namespace std;

class perfect_forwarding
{
private:
    std::string m_forName;
    Integer_forward m_Id;
public:
    //param constr
    // perfect_forwarding(const std::string &name, const Integer_forward &id);//for case1 & 2
    //move constr
    // perfect_forwarding(std::string &&name, Integer_forward &&id);    //for case1 & 2
    /*
        function templates that accepts rvalue references as arguments (with &&variable)
        then, if lvalue references as arguments passed to function templates then Type T1 & T2 become lvalue ref.  (consider as &variable)
        and also m_forName {name}, m_Id {id} will consider as r-value references (both case, will not work with l-value ref mentioned with typename)

        info about type, l/r-value ref should preserved -> can be done using std::forward
        m_forName {std::forward<T1>(name)}, m_Id {std::forward<T2>(id)}
    */
    template<typename T1, typename T2>
    //perfect_forwarding(T1 &&name,T2 &&id): m_forName {name}, m_Id {id} case 3/3-1 (std::forward)
    perfect_forwarding(T1 &&name,T2 &&id): m_forName {std::forward<T1>(name)}, m_Id {std::forward<T2>(id)}
    {
        cout << "perfect_forwarding(T1 &&name,T2 &&id)" << endl;
    }
    
    //~perfect_forwarding();
};

//case6:
template<typename T1, typename T2>
perfect_forwarding *createForward(T1 && a, T2 &&b)
{
    /*
        in below case after calling case6 from main() 
        perfect_forwarding pFor5{"case5", Integer_forward{600}};
        -> info for b will lost -> l-value ref since we passed it by name
        -> this invoked copy constr for b -: m_Id {id}
        case6, Perfect Forwarding!

        Integer_forward::Integer_forward(const Integer_forward &obj) // copy constr since it invoked with name with (l-value) for b not with r-value ref

    */
    // return new perfect_forwarding(a,b); //case 6
    return new perfect_forwarding(std::forward<T1>(a), std::forward<T2>(b)); //case 6-1
    /*
    Integer_forward::Integer_forward(Integer_forward &&obj) --> with std::forward, move constr of Integer_forward has invoked 
    */

}
// template <typename T1, typename T2>
// inline perfect_forwarding::perfect_forwarding(T1 &&name, T2 &&id): m_Id {id}, m_forName {name}
// {
// }


#endif //PERFECT_FORWARDING__H

#pragma endregion

/*
    output4: case4 with std::forward function with objects in constr
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(Integer_forward &&obj)
    perfect_forwarding(T1 &&name,T2 &&id)
    Integer_forward::~Integer_forward()
    after end if main ->
    Integer_forward::~Integer_forward()
*/

