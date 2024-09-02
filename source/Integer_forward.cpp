#include "../header/Integer_forward.hpp"

using namespace std;
/*
Purpose: This constructor initializes the Integer_forward object with a default value.
Parameters: None.
Behavior: It allocates memory for an integer and initializes it to 0.
*/
Integer_forward::Integer_forward()
{
    cout << "Integer_forward::Integer_forward()" << endl;
    m_pInt = new int(0);
}

/*
Purpose: This constructor initializes the Integer_forward object with a specific value provided by the user.
Parameters: int value - the value to initialize the integer with.
Behavior: It allocates memory for an integer and initializes it to the provided value
*/
Integer_forward::Integer_forward(int value)
{
    cout << "Integer_forward::Integer_forward(int value)" << endl;
    m_pInt = new int(value);
}

/*
Purpose: This constructor creates a new Integer_forward object as a copy of an existing one.
Parameters: const Integer_forward &obj - a reference to the object to be copied.
Behavior: It allocates memory for a new integer and initializes it with the value of the integer from the obj being copied. 
This ensures a deep copy, meaning the new object has its own separate copy of the integer
*/
Integer_forward::Integer_forward(const Integer_forward &obj)
{
    cout << "Integer_forward::Integer_forward(const Integer_forward &obj)" << endl;
    m_pInt = new int(*obj.m_pInt);
}

/*
Purpose: This constructor transfers ownership of resources from a temporary (rvalue) Integer_forward object to a new one.
Parameters: Integer_forward &&obj - an rvalue reference to the object to be moved.
Behavior: It transfers the pointer m_pInt from obj to the new object and sets obj.m_pInt to nullptr.
This avoids the overhead of copying and ensures that the temporary object does not delete the resource when it goes out of scope.
*/
Integer_forward::Integer_forward(Integer_forward &&obj)
{
    cout << "Integer_forward::Integer_forward(Integer_forward &&obj)" << endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer_forward::getForwardValue() const
{
    return *m_pInt;
}

void Integer_forward::setForwardValue(int value)
{
    *m_pInt = value;
}

/*
Purpose: This destructor cleans up the resources allocated by the Integer_forward object.
Behavior: It deletes the memory allocated for the integer to prevent memory leaks
*/
Integer_forward::~Integer_forward()
{
    cout << "Integer_forward::~Integer_forward()" << endl;
    delete m_pInt;
}
