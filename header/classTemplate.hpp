#pragma once
#ifndef CLASSTEMPLATE__H
#define CLASSTEMPLATE__H

using namespace std;

/*
    classes that should be able to handle the different types, i.f. class template is used with containers
    e.g. basic Stack class example to understand the need of variable data type by using class template 
*/

class Stack
{
    private:
    int m_Buffer[512];
    int m_Top{-1};
    
    public:
    Stack();
    void Push(int elem);
    void Pop();
    int Top()const;
    bool isEmpty();
    ~Stack();
};

class classTemplate
{
private:
    Stack st;
public:
    classTemplate(/* args */);

    void all_classTemplate_methods();
    
    ~classTemplate();
};


#endif //CLASSTEMPLATE__H
#pragma endregion