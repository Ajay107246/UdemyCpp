#pragma once
#ifndef STATICASSERT__H
#define STATICASSERT__H

#include<iostream>

/*
    DESCIRPTION:
    c provide macro called assert, used to test for expressions
    if the expressions return false, macro internally calls abort, and program terminated

    in c++11, static_assert is new kind of declaration for evaluating expressions
    it accepts an expression and user defined message
    used for testing an expression at compile time
    if the expression return false, the compiler displays specified message and compilation fails
    static_assert commonly used with type traits

    e.g.
    assume the program that find out whether the code is being compiled in 32-bit mode
    prevent compilation of code in different mode than 32
    easy to find size of ptr != 4, means not compiling in 32-bit mode

*/

void all_static_assert_methods();



#endif //STATICASSERT__H
#pragma endregion