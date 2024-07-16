/* Memory management
1. Smart-raw pointer
2. unique_ptr
3. shared_ptr
4. weak_ptr
5. circular reference
6. deleter
7. Dyanmic Array
8. Make function
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "moveFuntion.h"

using namespace std;

void Display(moveFunction *);
moveFunction * getPointer(int);
void operate(int);

/*Topic39, mem-management shared_ptr*/


class Project
{
    string m_name;
    public:
    void setName(const string &name);
    void setProjectDetail()const;
};

//if have number of emp then Employee class and its obj hlep here
class Employee
{
    Project *m_pProject{}; //each emp have project ptr they are working on_> emp will contain ptr to project, can not add destructor
    shared_ptr<Project> m_pProjectShared{}; //shared_ptr<Project>
    public:
    //no constr, cause can add the proj details when Emmployee obj is constructed
    //reallife emp can move to other proj as well
    void setProject(Project *prj);
    void setProjectShared(shared_ptr<Project> &prjShared);    //using shared_ptr<Project> &prj

    const Project * getProject()const;
    const shared_ptr<Project>& getProjectShared()const;  //using  shared_ptr<Project> 
};

void showEmpInfo(Employee *emp);

void showEmpInfoShared(const shared_ptr<Employee> & empShared);

/*Topic41, weak_ptr
1. drawback of shared_ptr vs 
destroying obj/ptr won"t work*/
class Printer
{
    //int *m_ptrShared{}; //holds int ptr, Topic41-1 normal ptr
    shared_ptr<int> m_ptrShared{}; //Topic41-2 shared_ptr ptr
    public:
    //void setPtrValue(int *p)  //Topic41-1 normal ptr
    void setPtrValue(shared_ptr<int> p)  //Topic41-2 shared_ptr ptr
    {
        m_ptrShared = p;
    }
    void printPtr()
    {
        /*to overcome p16 getting deleted in if() condition
        comparing with nullptr won't work
        cause p16= nullptr, but m_ptrShared is diff ptr and won't know about it */
        //print the reference count here 
        cout << "Reference count=" << m_ptrShared.use_count() << endl;
        cout << "value of m_ptrShared=" << *m_ptrShared << endl;
    }

};