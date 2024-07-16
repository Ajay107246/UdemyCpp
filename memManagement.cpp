/* Topic36, Memory management
1. Smart-raw pointer
2. unique_ptr: doesn"t have to be share to other part of code. <memory> header
it is class template, meaning you have to specify type info when you create a instance of unique_ptr
3. shared_ptr
4. weak_ptr
5. circular reference
6. deleter
7. Dyanmic Array
8. Make function
*/
#include <iostream>
#include <memory>
#include "memManagement.h"

using namespace std;

void Display(moveFunction *p)
{
    if(!p)
    {
        return;
    }
    cout << p->getValueMoveFun() << endl;
}

moveFunction * getPointer(int value)
{
    moveFunction *p = new moveFunction{value};
    return p;
}

void Store(unique_ptr<moveFunction> p)
{
    cout << "Storing data into a file="<< p->getValueMoveFun() << endl;
}

void operate(int value)
{
    //moveFunction *p = getPointer(value);    //Topic36
    std::unique_ptr<moveFunction> p{getPointer(value)}; //Topic37, assume getPointer can return nullptr
    if (p==nullptr) //compare ptr with nullptr
    {
        /* code */
        //p = new moveFunction{value};    //Topic36
        //Topic37, unique_ptr
        //reset(), if smart ptr holds existing memory, that will deleted first
        // then it will take ownership of new ptr
        p.reset(new moveFunction{value});   
    }
    p->setValueMoveFun(20); //unique_ptr oveload the arrow operator
    //Display(p); //Topic36
    Display(p.get());   //Topic37, get() will return underline ptr
    //delete p; //Topic36, not needed for unique_ptr since it is an object
    //p = nullptr; //Topic36// not needed since allocate memory below., otherwise dangling ptr, unique_ptr oveloder =, that accpet nullptr as param
    //p = new moveFunction{};   //Topic36
    p.reset(new moveFunction{});    //Topic37
    *p= __LINE__;
    // Display(p);  //Topic36
    Display(p.get());   //Topic37, unique_ptr
    /*memManagement.cpp:62:10: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = moveFunction; _Dp = std::default_delete<moveFunction>]'
    62 |     Store(p);
    */
    //copy constr of unique ptr is deleted, cannot create a copy of unique_ptr obj
    // can invoke in this way when //Store(unique_ptr<moveFunction> &p) -> &p pass by referece
    //Store(p); 
    //*p = 200; //can possible after Store(p); with Store(unique_ptr<moveFunction> &p)
    
    /*this will move the state of p obj to p which is an arguement to Store() fucntion
      simply give up the ownership of underline pointer
    */
    Store(move(p)); //Store(unique_ptr<moveFunction> p) p is pass by value here.
    //you can not create a copy of unique_ptr but always move it (using reset(new moveFunction{}))

    //delete p; //Topic36   
}

void showEmpInfo(Employee *emp) //Employee *emp, use unique_ptr<Employee> emp, pass pointer object (emp.get()), delete with emp.reset()
{
    cout << "Employee Project Details=";// << endl;
    emp->getProject()->setProjectDetail();
}

void showEmpInfoShared(const shared_ptr<Employee> &empShared)
{
    cout << "Employee Project Details (shared_ptr)=";
    empShared->getProjectShared()->setProjectDetail();
}

void Project::setName(const string &name)
{
    m_name = name;
}

void Project::setProjectDetail() const
{
    cout << "[Project Name], " << m_name << endl;
}

void Employee::setProject(Project *prj)
{
    //m_pProject = prj;   //unique_ptr can not be copied, use move assignment/constr
    m_pProject = prj; //Topic40, shared_ptr (replaced all unique_ptr (from Topic39) -> shared_ptr)
}

void Employee::setProjectShared(shared_ptr<Project> &prjShared)
{
    //m_pPrejectUnique = std::move(prjUnique);    //!Problem!-> prjUnique looses its state after moving ownship to eUnique1
    m_pProjectShared = prjShared;   //shared_ptr
}

const Project *Employee::getProject() const
{
    return m_pProject;
}

const shared_ptr<Project>& Employee::getProjectShared() const
{
        return m_pProjectShared;
}

