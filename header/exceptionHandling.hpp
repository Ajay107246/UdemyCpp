#pragma once
#ifndef EXCEPTION_HANDLING_H
#define EXCEPTION_HANDLING_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>


int processRecords(int count);

class AExp{
    public:
    AExp();
    ~AExp();
};
class BExp{
    public:
    BExp();
    ~BExp();
};

class TestExp{
    //AExp *aP{}; //part-3-1, need manual delete using concept RAII-> smart_ptr
    std::unique_ptr<AExp> aP{};
    BExp b{};
    //int *pInt{}; //part-3-1, use smart_ptr
    std::unique_ptr<int> pInt{};
    //char *cP{}; //part-3-1, use string
    std::string pStr;;
    //int *pArr{}; //part-3-1, use vector
    std::vector<int> pArr{};
    public:
    TestExp();
    ~TestExp();
};

/*part-4: noexpect(true/false)
1. SumNoExcept cannot throw an exception
2. can be used specifer noexcept()
3. noexcept(): accept optionally a boolean parameter t/f
4. no param mentioned -> default noexcept(true); meaning: function does not throw an excetion
5. if same func can throw exception -> use param as false -> noexcept(false)
6. this will inform compiler -> this func can throw an exception
7. if this func throw an excetion -> program will immediately terminates
8.


//void TestNoExcept(int x) // (2)default noexcept(false) function; meaning may/not throw an exception
void TestNoExcept(int x) noexcept(true)// (4)
{
    //throw x;
}
//int SumNoExcept(int x, int y)noexcept(false/* (3), true (2)){
int SumNoExcept(int x, int y)noexcept(noexcept(TestNoExcept(x)/*compiler time check spcification of TestNoExcept() this will apply same to SumNoExcept())){
    //error: crach/terminates
    //'throw' will always call 'terminate' [-Wterminate] (1)
    //throw 3;
    //(2) crash, no stack unwinding code
    //declaration of 'TestExp x' shadows a parameter
    //no match for 'operator+' (operand types are 'TestExp' and 'int')
    
    TestNoExcept(x); 
    return x+y;
}

*/
#endif //EXCEPTION_HANDLING_H
