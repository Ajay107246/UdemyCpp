#include "../header/variadicTemplates.hpp"
#include "../header/Integer_forward.hpp"

void all_variadicTemplates_method()
{
    PrintInitList({1,2,3,4,5}); //using initializer_lists
    
    Integer_forward val {1};
    // PrintVariadic(1, 2.5, 3, '4');    //using variadic template with any number of type and args
    PrintVariadic(0, val, Integer_forward {2});    //Integer_forward {2} -> passing as R-value, in recursive call, it became L-value
    cout << endl;
}