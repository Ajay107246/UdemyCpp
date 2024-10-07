#include "../header/lambdaExpressions.hpp"

void all_lambda_expressions_methods()
{
    /*
        74-1, simple lambda expression
        [] introducer, () args
        inside body simple cout statement
        whole part is anonymous function objects and to invoke the overloaded function call operator of this anonymous function object
        at end function call () operator can be use

        lambda expression is internally implemented as function object that compiler creates a class and overloads the function call operator in it
        function call operator will contain the implementation body of lambda expression

        since class name is unknown that compiler internally uses, instance of lambda expression can get thorugh auto keyword

    */
    [](){
        std::cout << "74-1, Welcome to lambda expressions!" << std::endl;
    }();    //() - invoked the lambda expression

    /*
        output:
        Topic74, lambda expression in C++11
        74-1, Welcome to lambda expressions!
    */
}