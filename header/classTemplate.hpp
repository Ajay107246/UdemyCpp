#pragma once
#ifndef CLASSTEMPLATE__H
#define CLASSTEMPLATE__H

#include <iostream>
#include <array>

//using namespace std;

/*
    classes that should be able to handle the different types, i.f. class template is used with containers
    e.g. basic Stack class example to understand the need of variable data type by using class template 

    1. same Stack class can be used for different class type
    2. compiler will instantiate stk class for all the types that it is instantiated for
    3. only those functions are instantitated that are invoked. if dn't invoke some of member functions, then they are not instantiated
    4. Class template can also accept non-type template args -> int size is specified here.
    5. e.g. Stack<float, 10> stFlSize;
    6. this is much better than using const value in member variable
    7. while defining the method outside of the class, we need to mentioned with template and class with size
    8. 
    e.g.{ void Pop(); }
    template<typename T, int size>
    void Stack<T, size>::Pop(){--m_Top;}
    9. factory method (method to create instance of class) for this Stack class
    
    link: https://sl.bing.net/i3pXXDkhvP2 
*/


template<typename T, /*int*/std::size_t size>  // can take size as arg to obj
class Stack
{
    private:
    //T m_Buffer[size]; //error: array subscript is not an integer
    std::array<T, size> m_Buffer;
    T m_Top {-1};   // int type can be used instead T
    
    public:
    /*
        Explicitly defaulted constructor, where compiler will generate its own constr
        To ensure that the compiler generates the default constructor even if other constructors are defined
        Make code more readable and explicit about the presence of a default constructor
        To control the accessibility of the default constructor (e.g., making it public, protected, or private)
    */
    Stack() = default;  
    /*
        copy constr
        //arg -> uses shorthand notation, since appears within class
        long hand notation can be used.
        Stack(const Stack<T, size> &obj);    
    */
    Stack(const Stack &obj);    

    void Push(const T &elem);   //can be user defined type , passed by const reference
    void Pop();
    const T& Top()const;
    bool isEmpty() const;

    /* 
        factory method, that creates and return instance of Stack class
        this is short hand notation since inside class, do not need to mentioned template paramter
        can be written only if that type occurs inside class definition
        can not write shorthand definition outside the class, have to use complete type class in that definition outside
        error: deduced class type 'Stack' in function return type
        i.e. shorthand notation ony works in side class

        need all template parameter at return type in definition
    */
    static Stack Create();

    ~Stack() noexcept;  //noexcept: good practice in c++
};
class classTemplate
{
private:
    //Stack st; //67-1 without template class example
    Stack<float, 10> stFloat = Stack<float, 10>::Create(); //67-2
public:
    classTemplate();
    void all_classTemplate_methods();
    ~classTemplate() noexcept;  //noexcept: good practice in c++
};


#endif //CLASSTEMPLATE__H
#pragma endregion