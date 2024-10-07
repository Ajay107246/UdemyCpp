#pragma once
#ifndef LAMBDAEXPRESSIONS__H    
#define LAMBDAEXPRESSIONS__H    

#include <iostream>
#include<typeinfo>  //74-3: type for fnLambda
#include<cxxabi.h>

/*
    description: 
    introduced in c++11,in way that few replacement in functionality of function objects
    it defines anonymous function objects
    its syntactic shortcut for a function objects
    
    creating function object without creating class/struct and having to overload function call operator
    it can be passed as an arg to function that accepts function object
    it behaves just like a function, can *//*accept param and return values*//*

    typically, encapsulates a few lines of code
    meaning: function object with few lines of code easily replaced by landa expression
    internally implemented as nameless function object.
    when it invoked, behaves like normal function
    *//*compiler auto implements the lambda expression as class with function call operator overloaded*//*
    if want to provide a name to the lambda expression -> create a variable using auto and assign lambda expression to it.
    e.g. syntax:
    [](<args>)<mutable><excp specification> -> <return type>
    {
    }();

    []                      lambda introducer, signifies start of lambda expression, contains a capture clause
    (<args>)                optional
    <mutable>               optional, specifications called mutable, since lambda expression behaves like a function, can optionally specify an exception specification
    <excp specification> 
    <return type>           To specify return type of lambda expression, trailing return type syntax        
    {}                      body of lambda expression
    ()                      to invoke lambda expression
    check source, all_lambda_expressions_methods() for more implementation details 

    
*/ 
void all_lambda_expressions_methods();
#endif //LAMBDAEXPRESSIONS__H    
#pragma endregion