#pragma once
#include <iostream>

using namespace std;


class Animal
{
    public:
    void Eat();
    // {
    //     cout << "Eating Animal!" << endl;
    // }
    void Run();
    // {
    //     cout << "Running Animal!" << endl;
    // }
    void Speak();
    // {
    //     cout << "Speking Animal!" << endl;
    // }
};

class Dog: public Animal
{
    public:
    void Eat();
    void Speak();

};