#include "../header/variadicTemplates.hpp"
#include "../header/Integer_forward.hpp"

void all_variadicTemplates_method()
{
    PrintInitList({1,2,3,4,5}); //using initializer_lists
    cout << endl;

    PrintVariadic(1, 2.5, 3, '4');    //using variadic template with any number of type and args
    cout << endl;
    
    Integer_forward val {1};
    PrintVariadic(0, val, Integer_forward {2});    //Integer_forward {2} -> passing as R-value, in recursive call, it became L-value
    //cout << endl;
    /*
        output:
        Topic66: Variadic Templates and non-typr  in c++(11)
        1 2 3 4 5
        1,2.5,3,4

        Integer_forward::Integer_forward(int value)
        Integer_forward::Integer_forward(int value)
        0,1,2
        Integer_forward::~Integer_forward()
        Integer_forward::~Integer_forward()    
    */
}

//function to stop recursion once num of args = 0 
void PrintVariadic()
{   
    /*  leads to error: 
        multiple definition of `PrintVariadic()'; C:\Users\Shimpi\AppData\Local\Temp\cc5oVYX1.o:G:/CPP/2024/VSCode/UdemyCpp/header/
        variadicTemplates.hpp:31: first defined here
        collect2.exe: error: ld returned 1 exit status
        Build finished with error(s)
        This violates the one-definition rule (ODR) and causes linker error
        [ https://en.cppreference.com/w/cpp/language/definition ]
        
        **solution:**
        this is a non-template function and should not be defined in the header
        so, declared in the header, and defined here in the .cpp file.
        **Alternatively, make it inline to avoid ODR violations, 
    */
    cout << endl; 
}