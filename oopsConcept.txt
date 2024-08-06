#include <iostream>
#include "oopsConcept.h"

using namespace std;

void Animal::Eat()
{
    cout << "Eating Animal!" << endl;
}

void Animal::Run()
{
    cout << "Running Animal!" << endl;
}

void Animal::Speak()
{
    cout << "Speaking Animal!" << endl;
}

void Dog::Eat()
{
    cout << "Dog eats meat!" << endl;
}

void Dog::Speak()
{
    cout << "Dog barks loudly!" << endl;
}
