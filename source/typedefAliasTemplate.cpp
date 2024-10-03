#include "../header/typedefAliasTemplate.hpp"

const char *getErrorMessage(int)
{
    return "Empty";
}

void showError(const char *(*pfn)(int))
{
}

typedef std::vector<std::list<std::string>> Names;
// template param such as Player
// template<typedef T>   //70-1
// using Names = std::vector<std::list<T>>; //70-1
using Names = std::vector<std::list<std::string>>;  //70-2, permanant bind with str


void all_typedefAliasTemplate_methods()
{
    /*
        typedef with template
        //std::vector<std::list<std::string>> : create a typedef
        
        disadvantage:
        typedef cannot be templatized.
        meaning: if want to use Names in other context.
        e.g. create a vector of list of players, I cannot templatize this with template param such as Player.
        Names<Player> names;    //cannot templatize

        BUT, using type aliases, we can achieve this.
        want to use type in different contexts but we should be able to templatize type at 'std::string'
        can use alias templates
        NOTE: see above
        
        when using Names, can be used in context of Names for any entity
        it could be string, Name<Names>

        you may permanantly bind a type in list
        if string :
        change -> using Names = std::vector<std::list<T>>;  -> using Names = std::vector<std::list<std::string>>;  //70-2, permanant bind with str
        remove -> // template<typedef T>   //70-1
        
        alias template have clear advantages over typedef
    */        
    Names names;
    // Names<std::string> names;    //70-1
    // Names<Names<std::string>> nnames;  //70-1
    Names nnames;
    PFN pfn = getErrorMessage;
    showError(pfn);   
}
