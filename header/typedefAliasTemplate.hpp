#pragma once
#ifndef TYPEDEFALIASTEMPLATE__H
#define TYPEDEFALIASTEMPLATE__h

#include <iostream>
#include <vector>
#include <list>

/*
    typedef:
    introduces a name for an existing type
    this name becomes a synonym of that type
    useful to construct shorter or more meaningful names for existing types
    simplifies declaration of some types (e.g. fun ptr & templates)
    implementation details that may change can be encapsulated
    does not introduce a new type; only introduces a new name for existing type
    e,g,
    typedef unsigned int UINTl
    UINT val{};

    typedef long long LLONG;
    LLONG elem{};

    typedef std::vector<std::list<Employee>> Teams;
    Teams testingTeams;
    Teams::iterator it = testingTeams.begin();

    typedef const char *(*ErrorFn)(int);
    ErrorFn pfn = GetErrorMessage;

    Alias:
    creates a name that is synonym of existing type
    does not introduce a new type
    same as a typedef declaration
    created through the 'using' ketword
    e.g.
    using UNIT = unsigned int;
    UINT val{};

    using LLONG = long long;
    LLONG elem{};

    using Teams = std::vector<std::list<Employee>>;
    Teams testingTeams;
    Teams::iterator it = testingTeams.begin();
    
    using ErrorFn = const char *(*)(int);
    ErrorFn pfn = GetErrorMessage;
*/

/*
    getErrorMessage function accepts the error number
    returns string associated with that error number (here, Empty for example)
    
*/
const char * getErrorMessage(int);

/*
    showError function that accepts the function ptr which accepts that int,
    returns const char*
    obviously, we can pass addr of getErrorMessage in showError()
    showError function looks like complex due to usage of function pointer
    reduce the complexity using typedef or alias

*/
//void showError(const char*(*pfn)(int)); //old declaration
// typedef const char * (*PFN)(int);
using PFN = const char *(*)(int);   //alias of function ptr type, this looks natural
void showError(const char*(*pfn)(int));

/*
    use typedef with templates, list of names (check all_typedefAlias... function)

*/
void all_typedefAliasTemplate_methods();


#endif //TYPEDEFALIASTEMPLATE__h
#pragma endregion