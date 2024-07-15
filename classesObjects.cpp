/* Topic23:OOP : uses objects as fundamental building blocks.
 * program is collection of objects
 * every objects are instance of some class
 * classes are united via inheritance relationship
 * 1. Abstraction: focuses on imp and necessary details of objects.
 * unwanted details are left out.
 * 
 * involves representing essential features without exposing implementation details
 * simplifies complex systems by focusing on high-level concepts and ignoring low-level specifics
 * e.g. represent a person wthout a details (age, weight, DOB, etc.)
 * can not see any internal details
 * 2. Encapsulation: next step of abstraction
 * how the object is internally implemented
 * hides implementation details of class
 * class provide behavior without revealing its implementation
 * internal implementation can be change without user knowledge
 * using access modifier in OO language
 * Encapsulation is the bundling of data (attributes) and methods (functions) 
 * that operate on that data into a single unit (usually a class)
 * 3. Inheritance: allow us to create relationship between classes
 * this creates heirarchy of classes and classes related through "is-a" relation
 * this relation due to same behaior of classes
 * e.g. car "is-a" vehicle.
 * the bahavior & implementation is inherited by children from parent (derived from base class) 
 * 
 * 4. Polymorphism
 * 
 * 
 */

#include <iostream>
#include "classesObjects.h"

using namespace std;

/* 1. Abstraction: We define an abstract class Shape with a pure virtual function draw().
 * The Circle class inherits from Shape and provides a concrete implementation of draw().
 * Users can create specific shapes (like circles) without knowing the internal details of drawing. 
 * 
 */
/*
//abstract class
class Shape
{
public:
	virtual void draw() = 0; // pure virtual function 
};

//derived class (concrete implementation)

 * can work as below method definition as well
class Circle
{
public:
	void draw() override
	{
		cout << "Draw a circle!" << endl;
	}
	
};

void Circle::draw() override
{
	cout << "Draw a circle!" << endl;
}
*/
//Topic24, 27, 28: constr., this-> ptr, static member variable
//constructor: default constructor
int Car::totalCarObj = 0; //Topic28: static member variable, init/default init
//Default Constructor

Car::Car()
{
	++totalCarObj;
	fuel=0;
	speed=0;
	passengers=0;
	std::cout << "\nDefault Constr. Car() gets called!" << endl;
}
/* Delegate Constructor can be used as Default constr
 * Car::Car:Car(0){ std::cout << "\nDefault Delegate Constr. Car() gets called!" << endl; }
 */
 
/*/user defined/ parameterized constructor: default constructor 
Car::Car(float amount)
{
	fuel = amount;
	speed=0;
	passengers=0;
}
*/
//Topic32: Delegating Constr.
Car::Car(float amount):Car(amount, 0)
{
	std::cout << "\nTopic32, Car() Delegating Constr. gets called!" << endl;
}

//Topic31:copy constructor
Car::Car(const Car &carObjCopyConstr)
{
	m_pInt = new int (*carObjCopyConstr.m_pInt);
}

int Car::getValue()const
{
	cout << "value for *m_pInt using copy constr=";
	//if (m_pInt) 
	//{
		return *m_pInt;
	//}
	/*else
	{
		// Handle the case when m_pInt is nullptr
		// (e.g., return a default value or throw an exception)
		// ...
		//m_pInt= nullptr; -> m_pInt is const, we can not modified
	}*/
}
void Car::setValue(int value)
{
	*m_pInt=value;
}
//Topic32: Delegating Constr
Car::Car(float amount, int passeng)
{
	/* below line below repeated in few of other constr
	 * this is source of bug, in one of constr some init may skip
	 * C++11 concept, that common init code keep in Deleg-constr and 
	 * other constr will delegates the call to this constr
	 * 
	 */
	++totalCarObj;
	fuel = amount;
	passengers = passeng;
	speed = 0;
}

/* Topic35: copy and move sementics

Car Addvalue(const Car &aInt, const Car &bInt)
{
	Car temp;
	temp.setValue(aInt.getValue() + bInt.getValue());
	return temp;
}


Car::Car(Car &&movObj)
{
	cout << "\nTopic35, move sementics!" << endl;
	//shallow copy : copy addr
	m_pInt = movObj.m_pInt;
	//here we stollen the resources, now assigned nullptr to movObj-ptr
	//this way if other obj is destroyed, its destructor won't crash
	//call to delete destructor will be ignored at runtime, that would delete nullptr
	
	movObj.m_pInt = nullptr;	
}
*/

// Destructor, gets called at end of main()
Car::~Car()
{
	--totalCarObj;
	std::cout << "\n~Car() gets called!" << endl;
}
void Car::fillFuel(float amount)
{
	fuel = amount;	
}
void Car::accelerate()
{
	this->speed++;	//Topic27: this ptr
	this->fuel-= 0.5f;
}

/* Topic27: this-> to know why it is needed/where to use
 * to identify the difference between local and member variables
 * function Foo() that accept the car obj, could be reference / ptr
 * void Foo(const Car &car)
 * {
 * }
 * void Car::addPassengers(int passengers)
 * {
 *     this->passengers = passengers ; //lval is indicated as member variable by this-> ptr
 * 	   Foo(*this); //derefence
 * }
 * other e.g. prefix form of incre/decrement operator, and asssignment operator
 */
 
void Car::brake()
{
	speed = 0;
}
void Car::addPassengers(int count)
{
	passengers = count;
}
void Car::dashboard() 
{
	std::cout << "Fuel= " << fuel << endl;
	/*
	 * lea ecx,[car] <--- load effective addr, take addr of car obj and put it in ecx regr.
	 * wherever this ptr is used, compiler move the addr ecx to [this]
	 */
	std::cout << "Passengers= " << passengers << endl;
	std::cout << "Speed= " << speed << endl;
	//Topic28: static member variable;
	std::cout << "Topic28, totalCarObj= " << totalCarObj << endl;
}

//Topic30: Const Member Function (CMF)
void Car::showTotalObj()/*const*/ 
{
		std::cout << "Topic29, totalCarObj= " << totalCarObj << endl;
}

/* Topic25: Structures
 * creates a userdefined type thorugh keywordL struct
 * similar to class, by default is public.
 * to represent abstrct type: point, vector3D
 * implementing function objects (used as call back STL library)
 */
 //std::cout << "\nTopic25, Struct in c++!" << endl;
 struct point
 {
	 int x = 0;
	 int y;	// by default public, can access easily
 };
 //function args
 //void drawLine(int x1, int y1, int x2, int y2)
 void drawLine(point start, point end)
 {
	std::cout << "start=" << start.x << endl;
 }

/* Topic26:Non Static data member initializers
 * easy way of initializing the class members with values during declaration
 * syntax:
 * class Class{
 *   <type1> <var1> {<initializers>};
 *   <type2> <var2> = <initializers>;
 * };
 * ensures that the members are initialized with valid values
 * can be used to initialized any types (var, ptr, arr, etc)
 * compiler auto generates initialization code, inserted to constr
 * initialization in used defined constr. take precedence.
 */

vehicle::vehicle()
{
	std::cout << "\nvehicle() gets called!" << endl;
}
//user defined/ parameterized constructor: default constructor 
vehicle::vehicle(int numCar)
{
	Car = numCar;
}

//printVehicle()
void vehicle::printVehicle()
{
	std::cout << "Car= " << Car << endl;
	std::cout << "Truck= " << Truck << endl;
	std::cout << "Bus= " << Bus << endl;
	int siz = sizeof(arr)/sizeof(arr[0]);
	cout << "Arr[5]=";// << endl; 
	for(int i =0; i< siz ; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
	//cout << "*ptr=" << *ptr << endl;
}

/* Topic33: Default & Deleted Function
 * 
 */
void Integer::getValue()
{
	std::cout << "Topic33, Integer::getValue()= " << m_value << endl;
}

void Integer::setValue(int val)
{
	m_value = val;
}




/*
int main()
{
	cout << "Main function started...!" << endl;
	
	//Topic23: Abstract Class
	Circle circleOcj;
	circleObj.draw(); // call overridden draw() function

	cout << atext("Main function End...!") << endl;
	
}*/


