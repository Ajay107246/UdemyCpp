/*
C++11 provided keywords which beneficial 
to put some restriction while working on class & inheritance

1. Final : specifier used with class / method which shouldn't be derived/override into inherited class
2. Override: 
*/
#pragma once
#include <iostream>


class Zip final
{
    public:
    Zip();
    void compress();
    void deCompress();
    void printStatistics();
    ~Zip();
    
};

/*
class FastZip : public Zip{

};
//Error: cannot derive from 'final' base 'Zip' in derived type 'FastZip'

No method adn destructor is virtual
cannot override bahavior in derived class

~Zip() is not virtual:
if child class obj deleted thorugh base class ptr -> 
destructor of base will be invoked, but not destructor of child
-> lead to memory leak or resource leaks
ie. why Zip() should not be inherited!

final keyword can be use to prevent this class to inheriting it.
if you try inherit -> leads to compilation error:
a 'final' class type cannot be used as base class
*/


#pragma region Override
class Document{
    public:
    virtual void serialize(float version);
    /*
        if we don't use virtual keyword, compiler error -> 
        error: 'void Text::serialize(float)' marked 'override', but does not override
    */
};

class Text : public Document
{
private:
    /* data */
public:
    /*void serialize(int version)override;
    
        below is not override function 
        since type is different from method present in base class
        C++11 introduce keyword -> override -> tells compiler that a method is being overridden
        once we used it with method present in derived class,
        compiler will check, same method exist in base class or not...     
        compiler error: 
        'void Text::serialize(int)' marked 'override', but does not override

        cause here type is making problem which is different from what exist in base class
    */
    void serialize(float version)override;//final;  //replace type -> float in definition also
    /*
    to restrict metod to be overridden -> use final speicifer at end of declartion of this method
    */

};

class FastText : public Text
{
    public:
    void serialize(float version)override;
    /*
      if final specifier used in method present in Text class
      serialize() method cannot be override here.
    */
};

