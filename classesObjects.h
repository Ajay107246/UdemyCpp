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
 * 
 * 2. Encapsulation: next step of abstraction
 * how the object is internally implemented
 * hides implementation details of class
 * class provide behavior without revealing its implementation
 * internal implementation can be change without user knowledge
 * using access modifier in OO language
 * Encapsulation is the bundling of data (attributes) and methods (functions) 
 * that operate on that data into a single unit (usually a class)
 * 
 * 3. Inheritance: allow us to create relationship between classes
 * this creates heirarchy of classes and classes related through "is-a" relation
 * this relation due to same behaior of classes
 * e.g. car "is-a" vehicle.
 * the bahavior & implementation is inherited by children from parent (derived from base class) 
 * child /derived class may reuse the behavior with same implementation or
 * provide a different implementation.
 * 
 * Composition: Signifies relationship between objects (has-a/part-of)
 * promotes reuse of an objects. e.g. car has an engine
 * 
 * 4. Polymorphism: many forms
 * represent common behavior of different implementation
 * response of each obj will be different (based on its class/args)
 * e.g. car, person, cycle can "move" differently (common behavior is 'move' and impl. differently)
 * can impl. using function overloading, templates (compile time) & virtual function (runtime)
 * promotes reuse, scalability, extensibility
 * 
 */

#pragma once


#include <iostream>
#include <cstdint>
#include <cstdio>

/*
	Topicxx: BIt masking for Embeded Programming
	A bit mask is a predefined set of bits that is used to select which 
	specific bits will be modified by subsequent operations.
*/

//uint8_t REG_0{ 0b0000'0000 };	//8 bits in size means room for 8 flags
//constexpr uint8_t REG_1 { 0b0000'0000 };

//constexpr uint8_t PIN_1{ 0b0000'0001 };
//constexpr uint8_t PIN_1{ 1 };
constexpr std::uint8_t PIN_0{ 0b0000'0001 }; // represents bit 0

using namespace std;

/* 1. Abstraction: We define an abstract class Shape with a pure virtual function draw().
 * The Circle class inherits from Shape and provides a concrete implementation of draw().
 * Users can create specific shapes (like circles, and Square) without knowing the internal details of drawing. 
 * 
 */

/*Topic18: inline function
 * use keyword inline
 * These functions are defined in header file
 * inline request compiler to replace call with function body.
 * overhead of function is avoided, stack mem for arguement is not required.
 * no need to save return value, improve performance of code. 
 */
inline int Square(int x)
{
	return x * x;
}

/* Topic24: Classes
 * Constructor: It invoked when it is created
 * used for intitialisation
 * doesn"t have any return type, but can accept argument
 * can overloaded.
 * may aquired some resources at time of obj creation
 * Type:
 * default: doesn"t accept any args, automatically invoke when object is created. e.g. Car carObj 
 * auto synthesized by compiler, if no other defined constr. in class
 * 
 * parameterized: used to init obj. with user-defined value, accept 1>= arg,  
 * never synthesized by compiler, blocks auto-generation of default constr.
 * 
 * copy, delegating, inheriting
 * 
 * destructor: method that is auto-invoked when obj is destroyed.
 * release resources may allocated in constr.
 * class can have only one destructor, and can not overloaded.
 * does not have args.
 * if user doesn't provide any desctructor, the compiler will synthesized one if required
 */

//uint8_t bit_clear(uint8_t number, uint8_t n);

class Car{
private:
	float fuel;
	float speed;
	int passengers;
	static int totalCarObj;	//Topic28:static member variable
	int *m_pInt;	//Topic31:copy constructor
public:
	Car();	//default constr.
	Car(float amount);	//parameterized constr.
	Car(float amount, int passeng);	//Topic32: delegating constr.(to avoid multiple init from constr)
	Car(const Car &carObjCopyConstr);	////Topic31: copy constructor, const: to avoid modification in obj
	//move semantic/constr
	Car(Car &&movObj);
	~Car();
	void fillFuel(float amount);
	void accelerate();
	void brake();
	void addPassengers(int count);
	void dashboard();
	static void showTotalObj(); //Topic29: static member function (SMF)
	//Topic31: copy constructor
	int getValue()const;
	void setValue(int value);
};

/*Topic35, Copy and move semantics*/
//Car Addvalue(const Car &, const Car &);
//segmentation fault at return *m_pInt


/* Topic26: non static data member initializer
 */
class vehicle{
private:
	int Car {0};
	int Truck {0};
	int Bus {0};
	int arr[5] ={1,2,3};
	char *ptr{};
public:
	vehicle();
	vehicle(int numCar);
	void printVehicle(); 
};

//abstract class
class Shape
{
public:
	virtual void draw() = 0; // pure virtual function 
};

//derived class (concrete implementation)
class Circle: public Shape
{
public:
	void draw() override {
		cout << "Draw a circle!" << endl;
	}
};

class Square: public Shape
{
public:
	void draw() override {
		cout << "Draw a square!" << endl;
	}	
};

/* Topic33: Default & Deleted Function
 * 
 */
class Integer
{
	int m_value{0};
public:
	Integer() = default;	// default constr
	Integer(const Integer &) = default;	//copy constr.
	/* Delete keyword to prevent compiler to synthesized the copy constr
	 * tell compiler not to synthesized the copy constr.
	 * main.cpp:1117:25: error: use of deleted function 'Integer::Integer(const Integer&)
	 */
	//Integer(const Integer &) = delete;	//error
	
	void getValue();
	void setValue(int val);
	/* main.cpp:1121:21: error: call of overloaded 'setValue(double)' is ambiguous
	 * intObj.setValue(7.9); //it will give warning, but accept the input val as INT, nit float
	 */
	void setValue(float) = delete;	//this will prevent to invoke
};

