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
    unique_ptr<Project> m_pPrejectUnique{}; //unique_ptr<Project>
    public:
    //no constr, cause can add the proj details when Emmployee obj is constructed
    //reallife emp can move to other proj as well
    void setProject(Project *prj);
    void setProjectUnique(unique_ptr<Project> &prjUnique);    //using unique_ptr<Project> &prj

    const Project * getProject()const;
    const unique_ptr<Project>& getProjectUnique()const;  //using  unique_ptr<Project> 
};

void showEmpInfo(Employee *emp);
//void showEmpInfoUnique(unique_ptr<Employee>& empUnique);    //using unique_ptr<Employee> 
void showEmpInfoUnique(const unique_ptr<Employee> & empUnique);