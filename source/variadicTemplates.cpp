#include "../header/variadicTemplates.hpp"


void all_variadicTemplates_method()
{
    PrintInitList({1,2,3,4,5}); //using initializer_lists
    
    PrintVariadic(1, 2.5, 3, '4');    //using variadic template with any number of type and args
    cout << endl;
}