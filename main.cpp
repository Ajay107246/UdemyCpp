/*
 * This is multi line comment 
 * Author: Ajay Shimpi
 * Loc: MUC-DE
 * Date: 06.07.2024
 * 
 * NOTE: C++ can be used to program in multiple paradigms, 
 * so it is not only object oriented, but imperative & generic language as well
 * cmd: g++ -Ofast -std=c++11 main.cpp classesObjects.cpp classesObjects.h -o FirstProject
 */
 
/* Header gaurds, this can prevent to include headers multiple times in single source file
 * multiple included headers in single source file cause -> redeclaration error
 */

//standard headers	
#include <iostream>
#include <cstring>
#include <cstdio>
#include <typeinfo>
#include <bitset>

//user defined headers
#include "classesObjects.h"
#include "binaryOperations.h"
//#include "moveSemantic.h"	//error: segmentation fault at *m_pMoveInt
#include "moveFuntion.h"
#include "memManagement.h"	//Topic27, mem-mangt, smart-ptr


//Topic18: inline function: MACRO
#define sumMacro(x,y) x+y
#define sqMacro(x) x*x

/* Topic20: Namespace
 * Declarative region to declare types
 * types are not visible outside the namespace
 * Standard library is in std namespace
 * prevent name clashes
 */
using namespace std;

/* Flags and Port PIN */
bool isSet_GPS_PIN;

namespace avg
{
	float Calculate(float x, float y)
	{
		return (x+y)/2;
	}
}

namespace basic
{
	template <typename T>
	T Calculate(T x, T y)
	{
		return (x+y);
	}
}

//nested namespace
namespace Sort{
	void mergeSort()
	{
		cout <<  "Sort::mergeSort()" << endl;
	}
	void quickSort()
	{
		cout <<  "Sort::quickSort()" << endl;
	}
	void insertionSort()
	{
		cout <<  "Sort::insertionSort()" << endl;
	}
	namespace Compare
	{
		void Less()
		{
			cout <<  "Sort::Compare::Less()" << endl;
		}
		void Greater()
		{
			cout <<  "Sort::Compare::Greater()" << endl;
		}
	}
}

/* below namespace without name
 * function inside it, can be accesseable directly
 */
namespace
{
	void namespaceWithoutName()
	{
		cout <<  "::namespaceWithoutName()" << endl;
	}
}

/* cout object is present in 'namespace std'
 * namespace is way to wrap the types,so that they are not visible outside
 * to access the types inside the namespece we need declarative -> 'using namespace std;'
 * Cout object is accessible to us!
 * 
 * Can be used without adding declarative in file, as
 * std::cout << endl;
 * std -> name of namespace
 * :: -> scope resolution operator and 
 * cout -> is member if that namespace
 */
 
 /* Topic7: void AddVal(int *a, int *b, int *result); 
  * Add two numbers and return the sum through the third pointer argument
  */
void Add(int *a, int *b, int* result)
{
	*result=*a+*b;
}
  
/* Topic7: void swapPtr(int *a, int *b)
 * Swap the value of two integers
 */ 
void swapPtr(int *a, int *b)
{
   int tmp = *a;
   *a= *b;
   *b = tmp;
}
   
//Topic7:
void Factorial(int *a, int *factResult)
{
   *factResult = 1;
   for(int i =2; i <= *a; ++i)
   {
	   *factResult *=i;
   }
}
   
/* Topic9: 
 * void swapRef(int &a, int &b) ;
 * Swap two numbers through reference arguments
 */
void swapRef(int &a, int &b)
{
   int tmp = a;
   a= b;
   b = tmp;
}
	  
/* Topic10:
 * swap() function, with args pass by Value
 * swapPassbyVal(val1, val2);
 */
void swapPassbyVal(int val1,int val2)
{
	int tmp= val1;
	val1 = val2;
	val2 = tmp;
}
	
//Topic11: with ptr
void printPtr(const int *ptr)
{
	if(ptr!=nullptr)
	cout << "value using const *ptr=" << *ptr << endl;
		
	/* Topic12-a: use const int *ptr in arguement 
	 * so that it can not be modifiable in this scope
	 * //*ptr = 90;
	 * above statement will failed due const int *ptr in arg
	 */
}
	
// Topic11: with reference
void printRef(const int &ref)
{
	//if(ptr!=nullptr) wont work, ref is not ptr
	cout << "value using &ref=" << ref << endl;
		
	/* Topic12-b: use const int &ref in arguement 
	 * so that it can not be modifiable in this scope
	 * //ref = 90;
	 * above statement will failed due const int &ref in arg
	 */
}	
// Topic13, Topic18, Topic19: sum function
int Sum(int a, int b)
{
	return a+b;
}
//Topic19: function pointer
void endMessage()
{
	cout << "!End of Program!" << endl;
}
	
/* Topic15: Function Overloading: multiple function
 * with same name but different number of arguments
 */
int SumOverload(int a, int b)
{
	return a+b;
}

double SumOverload(double a, double b)
{
	return a+b;		
}

double SumOverload(double a, double b, double c)
{
	return a+b+c;		
}

char SumOverload(char a, char b)
{
	return a+b;
}

void printOverload(int *ptr)
{
	if(ptr!=nullptr)
		cout << "value using *ptr=" << *ptr << endl;
}

void printOverload(const int *ptr)
{
	if(ptr!=nullptr)
		cout << "value using const *ptr=" << *ptr << endl;
	/* Topic12-a: use const int *ptr in arguement 
	 * so that it can not be modifiable in this scope
	 * //*ptr = 90;
	 * above statement will failed due const int *ptr in arg
	 */
}
	
/* Topic17: Default Function Argument
 * even if we pass onearg while calling the function, it has 5 arg indefinition
 * but only one is taken as input, and other are passed via arguement
 */
void CreateWindow(const char * title, int x= -1, int y= -1, int wid = -1, int height= -1)
{
	cout << "title=" << title << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "wid=" << wid << endl;
	cout << "height=" << height << endl;
}
	

/* Topic22: 2D array using array of pointers
 * using new and delete operators
 */
void twoData()
{
	int *ptr51 = new int[3];	//arr of int ptr
	int *ptr52 = new int[3];
	
	/* ptr to ptr, allow to create 1D arr of int ptr
	 * each elements 
	 */
	int **pData = new int *[2];
	pData[0] = ptr51;
	pData[1] = ptr52;
		
	pData[0][1] = 2; //2nd element of 1st row/raw1-column2
	//we need to delete in same sequence how we allocated memory
	delete []ptr51; // delete pData[0]
	delete []ptr52; // delete pData[1]
	//no. of delete should match number if new calls
	delete []pData;
}

/* Topic34: L-value & R-value
 */
//return R-value, which is temporary
int AddVal(int x, int y)
{
	return (x+y);
}

//return L-value, value wil assign to return value of function
int & Transform(int &x)
{
	x*=x;
	return x;
}

//Topic24, L-val & const L-vale reference
void Print(int &x)
{
	cout << "L-value reference: Print(int &x)" << endl;
}

//if R-value reference function is no present, this function will get call for Print(3)
void Print(const int &x)
{
	cout << "const L-value reference: Print(int &x)" << endl;
}

//R-value reference, in overloading the temporaries always binding to R-value reference, Print(3)
/*void Print(int &&x)
{
	cout << "R-value reference: Print(int &&x)" << endl;
}*/

/*Topic42, learn smart_ptr -> weak_ptr*/
/*void learnWeakPtr()
{
    printerWeak prnWeak;
    int numWeak{};
    cout<< "weak_ptr, Enter the <15 or >15 here=" << endl;
    cin >> numWeak;
    shared_ptr<int> pPtrShared{new int {numWeak}};
    prnWeak.setPtrValueWeak(pPtrShared);
    if (*pPtrShared>15)
    {
        pPtrShared = nullptr;
    }
    prnWeak.printWeakPtr();
}*/

int main()
{
	
	/* topic1: when we want to print something on screen,
	 * that we need to insert into cout using << operator 'Insertion'
	 * below we have cascaded theinsertion operator
	 * 
	 * endl - is manupulator and affect the output
	 * 
	 * If you miss " while printing message "This is ... << endl;
	 * this will throw a compiler error : literal operator " not found at line ## 
	 * here, error: missing terminating " character (varries depend on tools like VS2015, etc)
	 */
	 
	std::cout << "\nTopic1:" << endl;
	cout << "This is first program using 'namespace std' " << "to access object cout!" << endl;
	
	/* Topic2: Primitive types:
	 * Arithmatic -> integral and floating point
	 * integral -> bool, char, wchar_t, char16_t, char32_t, short, int, long
	 * floating point -> float, double
	 * void -> special type used with pointer and functions. 
	 *
	 * Modifiers: to modify/change meaning of type (only on integral, not floating points)
	 * signed, unsigned, short, long. 
	 * all the types can be qualified with qualifiers
	 * const, volatile, static
	 * 
	 * All types occupy memory and can hold range of values
	 * e.g. 32 bit platform , INT requires 32 bit/ 4 bytes of memory.
	 */
	 
	std::cout << "\nTopic2:" << endl;
	std::cout << "Primitive types in c++!" << std::endl;
	 
	/* Topic3: variable declaration:
	 * Variable a is declared and initialized with value 0
	 * Variable b is only declared, but not initialized.
	 * Initializer is not always required
	 * But some compiler will not allow uninitialized var,and may throw a bug.
	 * But, if we do not initialized it compiler will assign junk value.
	 * output value contain: 
	 * A: 0    B: 8.99964e-039
	 */
	//Scaler types
	std::cout << "\nTopic3:" << endl;
	int a = 0;
	/* Uniform initialization is preferable for initializing variables because
	 * It automatically initializes the variable to 0 (or pointers to nullptr),
	 * thereby preventing runtime bugs
	 * It default-initializes when no initializer is specified 
	 */
	int c {11}; //uniform initialization
	float b;
	float fl = 1.283f;	//f is optional here.
	bool flag = false; // can be false(0), true(1)
	double db = 521.556;
	
	//Vector types
	int arr[5];
	int arr2[5] = {1,2,3,4,5};
	//output value: A = 0    B= 8.99964e-039
	std::cout << "A= " << a << "\tB= " << b;// << endl;
	std::cout << "\nFlag=" << flag << "\tfl= " << fl << std::endl;
	
	/* Topic4: Uniform initialization:
	 */
	std::cout << "\nTopic4:" << endl;
	int a1; //uninitilized
	int a2 = 0; //copy initialization
	int a3(5); //direct initialization
	std::string str1;
	std::string str2("C++"); //direct initialization
	std::cout << "value of a3=" << a3 << endl;
	std::cout << "value of str2=" << str2 << endl;
	   
	char d1[5]; //uninitilized
	char d2[5] = {'\0'}; //copy initialization
	char d3[8] = {1,2,3,4,5}; //aggregate initialization
	char d4[8] = {"asbcd"};	//copy initialization
	   
	int b1{}; //value initialization
	//int b2(); // most vexing parse
	int b3 {5}; //direct initialization
	   
	char e1[8]{};
	char e2[8]{"Hello"};
	   
	int *p = new int{};
	
	char *p1 = new char[8]{};
	//char *p2 = new char[6]{"Hello"}; // error: invalid conversion from 'const char*' to 'char' [-fpermissive]
	//delete[] p2;
	strcpy(p1, "Hello");
	   
	/* 1. value initialization => T obj{};
	 * 2. direct initialization => T obj{val};
	 * 3. copy initialization => T obj = val; //(try to avoid)
	 */
	  
	/* Topic5: Pointer: points to another type
	 * holds memory address of another variable
	 * use for indirect access to other variable 
	 * not to be initialized during, but recommend to initialized it.
	 * ptr declared with * and get address of operate using & (applied to any variable)
	 */
	std::cout << "\nTopic5:" << endl;
	int * ptr;
	int *ptr1, p12; //p12 is normal integer but not a pointer
	p12 =10;
	int *ptr2 = &p12;
	//float *ptr3 = &p12; //error: cannot convert 'int*' to 'float*' in initialization
	   
	/* void pointer can points to any type of variable.
	 */
	void *ptr4 = &p12;
	   
	std::cout << "Address of ptr: " << ptr << std::endl;
	std::cout << "Address of ptr1: " << ptr1 << std::endl;
	std::cout << "Address of p21: " << &p12 << std::endl;
	std::cout << "Address of ptr2: " << ptr2 << std::endl;
	std::cout << "Address of ptr4: " << ptr4 << std::endl;
	   
	/* Topic6: Dereference Operator
	 * to access all value stored at pointer using *
	 * allows indirect read/write on the variable through pointer.
	 */
	std::cout << "\nTopic6:" << endl;
	int x = 5;
	int *ptr5 = &x;
	*ptr5 = 10; //Assign 10 to addr of x
	int x1 = *ptr5; //read the value from addr of x
	
	cout << "value of x= " << x << endl;
	cout << "value of *ptr5= " << *ptr5 << endl;
	cout << "value of  x1= " << x1 << endl;
	
	void *ptr6 = nullptr;
	cout << "nullptr ptr6=" << ptr6 << endl;
	/*read violation at runtime
	 * cout << "\n nullptr *ptr6=" << *ptr6 << endl; //error: 'void*' is not a pointer-to-object type
	 *
	 * int *ptr7 = nullptr;
	 * cout << "\n nullptr *ptr7=" << *ptr7 << endl;
	 * *ptr7 = 10; // cannot write value to the nullptr -> write violation at runtime
	 */
		
	/*Topic7: void AddVal(int *a, int *b, int *result); 
	 * Add two numbers and return the sum through the third pointer argument
	 */
	std::cout << "\nTopic7:" << endl;
	int num1 =7, num2=5, sumResult;
	std::cout<< "before swapPtr,\tnum1=" << num1 << "\tnum2=" << num2 << endl;
	Add(&num1, &num2, &sumResult);
	cout<< "sumResult=" << sumResult << endl;
	 
	//swapPtr the value of two integers
	swapPtr(&num1, &num2);
	std::cout<< "after swapPtr,\tnum1=" << num1 << "\tnum2=" << num2 << endl;
	
	int factResult;
	//Factorial(int *a, int *result)
	Factorial(&num2, &factResult);
	std::cout<< "factResult=" << factResult << endl;
		
	/* Topic8: Reference Type:
	 * Define an alias/alternative name to variable 
	 * created with & operator during declaration
	 * without initializer ref can not be created
	 * always need an initializer (referent)
	 * referent should be an variable
	 * can used to modify variable indirectly (like pointers)
	 * Reference is NOT a new variable but it is just a new name.
	 * No memories allocated to reference.
	 */
	std::cout << "\nTopic8:" << endl;
	int ff = 10;
	int &ref = ff; // c is referent, and ref is alias
	int dd = 15;
	ref = dd;
		 
	std::cout<< "Reference Type=> " << endl;
	std::cout<< "ff=" << ff << endl;
	std::cout<< "dd=" << dd << endl;
	std::cout<< "ref=" << ref << endl;
		 
	/* Topic9: Swap two numbers through reference arguments
	 * error: invalid conversion from 'int*' to 'int' [-fpermissive] swapRef(&num1, &num2);
	 * error: cannot bind rvalue '(int)(& num1)' to 'int&' swapRef(&num1, &num2);
	 * 
	 * NOTE: similarly we can define AddRef() & FactorialRef 
	 * //Add two numbers and return the result through a reference parameter
	 * void AddRef(int a,int b, int &result) ;    
	 * //Find factorial of a number and return that through a reference parameter
	 * void Factorial(int a, int &result) ;
	 */
	std::cout << "\nTopic9:" << endl;
	swapRef(num1, num2);
	std::cout<< "after swapRef:\nnum1=" << num1 << endl;
	std::cout<< "num2=" << num2 << endl;
	
	/* Topic10: pass by value and pass by Ref (Topic9-> for Ref) 
	 */
	std::cout << "\nTopic10:" << endl;
	int val1 = 2, val2= 5;
	swapPassbyVal(val1, val2); 
	
	/* actual swap functionality does not work here
	 * val1 and val2 remain unchanged
	 * here we need to use swapPtr() / swapPassbyVal()
	 */
	std::cout<< "swapPassbyVal:\nval1=" << val1 << endl;
	std::cout<< "val2=" << val2 << endl;
	
	/* Topic11: understand pointer
	 */
	std::cout << "\nTopic11:" << endl;
	int val3=6;
	printPtr(&val3); //print => 6
	printPtr(nullptr);	//program will crash at runtime
		 
	//using print value using pass by ref 
	printRef(val2);	//always have valid value, but ptr does not have (chk for nullptr)
	
	/* error: invalid initialization of non-const reference of type 'int&' 
	 * from an rvalue of type 'std::nullptr_t'
	 * printRef(nullptr);
	 */
	
	/* Topic12: const keyword
	 * creates a variable that is constant
	 * value can not be modified
	 * attempt to modify cause compiler error
	 * qualified to declaration, but always need initializer
	 * replace c macros
	 * commonly used with refs
	 * .e.g. const <type> <variable> {initializer}
	 * const float PI {3.141f}
	 * valid for only scope in which it is declared/initialized
	 */
	 
	float const PI = 3.14159f;
	cout << "Value of PI=" << PI << endl;
	
	/* PI= 3.159f;
	 * error: assignment of read-only variable 'PI'
	 * cout << "Value of PI=" << PI << endl;
	 *
	 * ptr assign to const should also be const ptr
	 * const float *ptr = &PI; //"ptr is pointer to INT of type const"
	 * means *ptr is const, but ptr is not.
	 * if *ptr =1; -> error: expression must be modifiable lvalue
	 * const'ness of original variable is unchange/preserved.
	 * ptr = &val3;
	 * *ptr=10; // not allowed!
	 */ 
	 
	//Try to modify x1 & x2 and see the compilation output
	std::cout << "\nTopic12:" << endl;
	int xy1 = 15 ;
	cout << "Value of xy1=" << xy1 << endl;

	const int MAX = 12 ;
	cout << "Value of MAX=" << MAX << endl;
	int &ref_x1 = xy1 ;
	cout << "Value of (&ref_x1=xy1)=>" << ref_x1 << endl;

	const int &ref_x2 = xy1 ;
	cout << "Value of (&ref_x2=xy1)=>" << ref_x2 << endl;

	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int *ptr11 = &xy1 ;
	cout << "Value of (*ptr11=&xy1)=>" << *ptr11 << endl;

	int *const ptr12 = &xy1 ;	//constant pointer to the integer variable
	cout << "Value of (s*ptr12=&xy1)=>" << *ptr12 << endl;

	const int * const ptr13 = &xy1 ;
	cout << "Value of (*ptr13=&xy1)=>" << *ptr13 << endl;

	//Find which declarations are valid. If invalid, correct the declaration
	const int *ptr14 = &MAX ;
	cout << "Value of (*ptr14=&MAX)=>" << *ptr14 << endl;
	
	/*error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
	 * int *ptr15 = &MAX ;
	 * cout << "Value of *ptr15=" << *ptr15 << endl;
	 */
	
	const int &r1 = ref_x1 ;
	cout << "Value of (&r1 = ref_x1)=>" << r1 << endl;

	/* error: binding 'const int' to reference of type 'int&' discards qualifiers
	 * int &r2 = ref_x2 ;
	 * cout << "Value of r2=" << r2 << endl;
	 */
	
	/* error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
	 * int *&p_ref1 = ptr11 ;
	 * cout << "Value of *&p_ref1=" << *&p_ref1 << endl;
	 */

	/* error: cannot bind rvalue '(int*)ptr11' to 'int*&'
	 * error: invalid initialization of non-const reference 
	 * of type 'const int*&' from an rvalue of type 'const int*'
	 * const int*&p_ref2 = ptr2 ;
	 */
	
	/* Topic13: auto keyword:
	 * indicate storage class of c pre-C++11
	 * Allows compiler to automatically infer the type from initializer
	 * initializer is important
	 * syntax: auto <identifier> = <initializer>
	 * <initializer> => could be an expression, literal, mathematical expression/
	 * function call that returna a value.
	 * NOTE: useful when work with lymbda expression & template
	 */
	 
	auto ia = 10;
	auto ib = 5;
	auto isum = ia + ib;
	auto isum1 = isum + 4.9f;
	std::cout << "\nTopic13, autoKeyword:" << endl;
	cout << "Value of [isum1 = (isum + 4.9f)]=>" << isum1 << endl;
	auto SumResult = Sum(isum1, ib);
	cout << "Value of int SumResult(isum1,ib)=>" << SumResult << endl;

	/* declaring const int id and
	 * assigning it to another auto ie => this won't be const anymore
	 * that means qualifier of int (const), is discarded for auto ie
	 * so, to overcome, declared const auto ie.
	 * similarly with reference auto &ifv = id; => this is also const 
	 * indirectly with use of & for new variable
	 */
	
	const int id = 9;	// id is INT type const variable, value can not be changed 
	auto ie = id;	// ie is not const here, value can be changed
	auto &ifv = id;	// ifv is const here.
	auto ptr21 = &id;	// pointer ptr21 is const here(const int *ptr21)
	
	/* type of list => std::initializer_list<int> list
	 * comma separated elements should be right side of assignment operator.
	 */
	auto list = {1,2,3,4,5}; 	
	
	/* this won't work
	 * auto list {1,2,3,4,5}; 
	 * below wil work->
	 * auto list {1}; //type int list
	 */
	 
	/* Topic14: range based for loop:
	 * standard for(int i; i < range; ++i)
	 * index, termination expression, in/decrement index
	 * Range based for() does not require this
	 * each iteration return container of element
	 * can be used with any obj that behaves like range
	 * syntax:
	 * for(variable declaration: range){statements;}
	 */	
	int arr1[] = {1,2,3,4,5};
	/* normal practice: for(int x: arr)
	 * can be an issue => for(auto &x: arr)
	 * this can allow to modify x value in loop,x=3, all values=3
	 * for(auto x: {1,2,3,4,5}){} => can also work
	 */
	
	/*for(const auto &x: arr1)	//to overcome above issue, declared as const auto
	{
		cout << x << " " << endl;
	}*/
	
	/* iterate through ptr syntax
	 * if you forget to add argument -> std::begin(ARR1),
	 * it will throw an error for initializer list.
	 * with note: candidate expects 1 argument, 0 provided 
	 * begin() & end() will not work with ptr to array 
	 * e.g. auto range = arr1;
	 */
	std::cout << "\nTopic14, rangeBASedForLoop:" << endl;
	int *begin = std::begin(arr1); //&arr1[0]; similar to container
	int *end = std::end(arr1); //&arr1[5];
	while(begin!=end)
	{
		std::cout << *begin << " " << endl; 
		++begin;	//fi you do not increment condition, loop infinite with 1st value of arr1
	}
	
	/* range based for(auro x: arr1){}
	 * auto &&range = arr1; //type of range= arr1
	 * auto begin = std::begin(arr1);
	 * auto end = std::end(arr1);
	 * for(;begin!=end;++begin){auto v = *begin;} =>
	 * this is how RBA works
	 * in c++17 begin() & end() need not be of same type
	 */
	
	/* Topic15: Function Overloading:
	 * multiple number of function with same name but different number of arguments
	 * or same number number of argument with different type
	 * ptr & reference, qualifier participate in overload.
	 * return type is ignored
	 * Different implementation of same same behaviour (behaviour with have same name)
	 * This is resolved at compiler time, ==>> static polymorphism
	 * Name Mangling => generate unique name for functions by compiler
	 * allows linker to link the call with correct overloaded function
	 * NOTE:
	 * might not work with type 'auto'
	 * if same no of arg with same type => 
	 * error: void func(int) already has a body!
	 * :433:32: error: call of overloaded 'Sum(float&, int&)' is ambiguous
	 * auto SumResult = Sum(isum1, ib);
	 * 
	 * This type checks will be done by compiler at time of expansion of code
	 */
	std::cout << "\nTopic15, OveloadFunction:" << endl;
	double result2Double = SumOverload(3.1,6.3);
	std::cout << "result2Double="<< result2Double << endl; 
	cout << "type of value,result2Double=> " << typeid(result2Double).name() << endl;
	
	double result3Double = SumOverload(3.1,6.3, 1.6);
	std::cout << "\nresult3Double="<< result3Double << endl; 
	cout << "type of value,result3Double=> " << typeid(result3Double).name() << endl;
	
	auto resInt = SumOverload(3,9);
	std::cout << "\nresInt="<< resInt << endl;
	cout << "type of value,resInt=> " << typeid(resInt).name() << endl;
	auto charRes = SumOverload('a','b');
	std::cout << "\ncharRes="<< charRes << endl;
	cout << "type of value,charRes=> " << typeid(charRes).name() << endl;
	
	cout << endl;
	const int var31 = 10;
	int var32 = 11;
	printOverload(&var32);
	printOverload(&var31);
	//cout << endl;
	
	/* Topic16: extern 'c'
	 * compiler directive applied to global functions and variables
	 * suppresses name mangling if type on which it is applied.
	 * allow c++ function to be called from c / other languages.
	 * Apply on function declaration & definitions.
	 * In.h file 
	 * extern "c" <functio declarations>;
	 * In.cpp file
	 * extern "c" <function definition>{}
	 * 
	 * NOTE:
	 * polymorphic overloaded function can mapped in map file by linker
	 * in VS2015: project property->Linker->Debugging->Generate Mapfile->choose YES
	 * in CodeLite: Project->setting->c++ compiler option->add /enter text: 
	 * -O3;-w;-pedantic;-Wall;-gdwarf-2;-O0;-Wl,-Map=output.map
	 * e.g. extern "c" void printExtern(int *x){return 0;}
	 * this function _printExtern gets added in .map file with address.
	 * to work on this we need to declared function in .h file
	 * move definition in another .cpp file
	 * if you do not use extern "C", it will not be linked, and there will be linker error
	 * but you can #include ".h" header in your source file in your source file
     * to use those function. 
	 */
	 
	/* Topic17: Default Function Argument
	 * even if we pass onearg while calling the function, it has 5 arg indefinition
	 * but only one is taken as input, and other are passed via arguement
	 */
	std::cout << "\nTopic17, DefaultFunctionArg:" << endl;
	CreateWindow("Notepad"); //has >1 args but take default value as argument
	std::cout << "Trial1 with arg as input to function:" << endl;
	CreateWindow("Notepad", 10, 20);	// use & print input from function arg here
	
	/* Topic18: inline function:
	 * using normal function, 
	 * overhead means jumping from funCall to actual function definition
	 * after execution is finished at definition, it has to know, where it has to return?
	 * so, it has to store return addr.
	 * Also has to allocate stack memory for input variables (2 , 3)
	 * Some kind of complex Application is overhead is not negligible.
	 * 
	 * use keyword inline
	 * These fun are defined in header file
	 * inline request compiler to replace call with function body.
	 * overhead of function is avoided, stack mem for arguement is not required.
	 * no need to save return value, improve performance of code. 
	 */ 
	std::cout << "\nTopic18, Inline:" << endl;
	//funCall overhead associated with it
	int sumInline = Sum(2,3);
	std::cout << "sumInline(2,3)=" << sumInline << endl;
	
	/* we can use MACROS instead!
	 * problem with MACROs, it works with text substitution
	 * sqInlineMacro(vall_9+1) => will not give correct output(bug)
	 */
	int sumInlineMacro = sumMacro(7,3);
	std::cout << "sumInlineMacro(7,3)=" << sumInlineMacro << endl;
	
	int vall= 9;
	int sqInlineMacro = sqMacro(vall);//
	std::cout << "sqInlineMacro(vall+1)=" << sqInlineMacro << endl;
	int sqInlineMacroInvalid = sqMacro(vall+1); //bug with MACRO
	std::cout << "sqInlineMacro(vall_9+1)=" << sqInlineMacroInvalid << endl;
	
	int _vall = 5;
	int sqInlineRes = Square(_vall+1);
	std::cout << "Square(_vall5+1)=" << sqInlineRes << endl;
	
	/* Topic19: Function Pointer
	 * ptr that holds the addr of function
	 * type is same as signature of function (return type & args)
	 * can used to invoke the function even name is not known
	 * syntax: <ret> (*fptr)(arg) = &function
	 * e.g. int (*ptrAdd)(int, int) = &Add; //int Add(int, int)
	 * when function to be invoked is not known at compiler time.
	 */
	//int Sum(int a, int b)
	std::cout << "\nTopic19, Function pointer:" << endl;
	int (*Psum)(int, int) = Sum; // &Sum;
	int sumPtrFun = (*Psum)(3,10);
	std::cout << "(*Psum)(3,10)=" << sumPtrFun << endl;
	int sumPtrFun1 = Psum(3,10);
	std::cout << "Psum(3,10)=" << sumPtrFun1 << endl;
	
	/* Topic20: Namespace
	 * function and variable declared/defined in namespace can be used
	 * by invoking namespace with it.
	 * if not invoke, error: 'Calculate' was not declared in this scope
	 */
	std::cout << "\nTopic20, Namespace:" << endl;
	
	/* using namespace avg; //this can be used
	 * but in case of overloading with same function in other namespace
	 * compiler can not able to choose which function to call?
	 * so, we need use full qualified namespace with function
	 */ 
	float avgNamespaceAvg = avg::Calculate(3.5, 6.5);
	std::cout << "avg::Calculate(3.5, 6.5)=>" << avgNamespaceAvg << endl;
	
	//int ee1 = 5, ee2 = 7;
	int basicNamespaceTSum = basic::Calculate<int>(3, 11);
	std::cout << "basic::Calculate<int>(ee1, ee2)=>" << basicNamespaceTSum << endl;
	
	std::cout << "\nnestedNamespace:" << endl;
	Sort::mergeSort();
	Sort::quickSort();
	Sort::insertionSort();
	
	Sort::Compare::Less();
	Sort::Compare::Greater();
	
	::namespaceWithoutName(); //calling with/without :: scope resolution operator is also fine
	
	/* Topic21: Memory Management
	 * Stack: allocated auto for local variable at runtime.
	 * Data section: allocated for global and static data
	 * Heap: allocated at runtime
	 * All memory is taken from process addres space.
	 * when prgram start running, process addr space get created
	 * runtime memory allocation => dynamic memory allocation (Heap area)
	 * 
	 * malloc: allocate raw memory on heap, it accept the size and return ptr to allocated memory
	 * it is function
	 * it does not initialized the memory, it just return raw memory
	 * can not call constructor, hence can not create object.
	 * calloc: allocate memory on heap and initialized it to zero
	 * 
	 * relloc: allocate larger chunk of memory for an existing allocation
	 * free: deallocates/release the memory allocated thr above functions
	 */
	std::cout << "\nTopic21, Dynamic memory allocation:" << endl;
	/* below will work in C, but not in C++
	 * error: invalid conversion from 'void*' to 'int*' [-fpermissive]
	 * int *ptr91 = malloc(sizeof(int));
	 * in C++ implicite conversion does not allow, manually typecast
	 */ 
	int *ptr41 = (int*)malloc(sizeof(int)); 	//c style
	//int *ptr41 = (int*)malloc(5 * sizeof(int));  //allocates memory for array of/5 integer
	*ptr41 = 41;
	cout << "malloc, *ptr41=" << *ptr41 << endl;
	if (ptr41 == nullptr)
	{
		cout << "Failed to malloc, ptr41!" << endl;
		return -1;
	}		
	/*error: invalid conversion from 'int' to 'void*' [-fpermissive]
	 * free(*ptr91);
	 * Make sure to use address not referenced ptr variable to free memory
	 * once *ptr91 is updated and  used, it became dangling pointer
	 * which points to invalid address
	 * 
	 * NOTE: IF we foget to call free(),
	 * it can not be freed, this leads to memory leak issue
	 * you loose the addr to memory that you allocated,  no longer release that memory.  
	 */
	free(ptr41);
	ptr41 = nullptr;	//safe
	//free(ptr91); program will crash if we repeat free(ptr91)
	
	int *ptr42 = (int*)calloc(1, sizeof(int)); 
	//int *ptr42 = (int*)calloc(5, sizeof(int));  //allocates memory for array of/ 5 integer
	cout << "calloc, *ptr42(init with zero)=" << *ptr42 << endl;
	if (ptr42 == nullptr)
	{
		cout << "Failed to calloc ptr42!" << endl;
		return -1;
	}
	
	/* Topic21: mem-manage in c++
	 * c++ provide two operators for DyMemAll
	 * new: allocates memory on heap (operator)
	 * ascertained size from type
	 * can initiailzed memory.
	 * can call constructor
	 * returns correct types of pointer
	 * can be customized through overloading 
	 * if failed to allocation of memory, it throws an exception
	 * 
	 * delete: deallocates memory on heap
	 * syntax:
	 * <type> *<variable> = new <type> (optional args);
	 * uninitialized memory.
	 */
	cout << "Topic21: Memory Management in c++!" << endl;
	int *ptr43 = new int(5); //allocates mem for INT pointer, by int mentioned nect to new
	cout << "initialized new, [*ptr43 = new int]=" << *ptr43 << endl;
	*ptr43 = 43;
	cout << "updated new, [*ptr43 = new int]=" << *ptr43 << endl;
	
	delete ptr43;
	//need to update to nullptr, since it still points to addr, (dangling ptr)
	ptr43 = nullptr;
	
	/* Topic22:  new for Array
	 * new[], delete[]
	 * syntax:
	 * <type> *<variable> = new <type>[];
	 * delete[] <variable>;
	 */
	std::cout << "\nTopic22, Dynamic Array allocation (new[]):" << endl;
	int *ptr44 = new int[5]{1,2,3,4,5};
	
	//cout << "ptr44="; // << endl;
	for(int i = 0; i < sizeof(ptr44); ++i)
	{
		ptr44[i] = i; 
	}
	/*for(int i ; i < sizeof(ptr44); ++i)
	{
		cout << "\t" << ptr[i] << endl;
	}*/
	delete []ptr44; //do not forget to add [] since it is an array.
	ptr44= nullptr;
	
	//allocate 1 extra byte for null terminating char at end
	char *ptr45 = new char[5];
	strcpy(ptr45, "C++");
	cout << "before, ptr45_string_arr=" << ptr45 << endl; 
	
	//strcpy_s(ptr45, sizeof(ptr45), "ADC"); //can be used, with <cstring> header
	//cout << "after, ptr45_string_arr=" << ptr45 << endl; 
	
	/* 2D array
	 * int data[2][3];
	 * access data [0][1]
	 * in memory -> 1,2,3,4,5,6
	 * 
	 */
	cout << "\nTopic22/24, OOP:Class & Objects in c++!" << endl;
	
	//Topic23: Abstract Class
	Circle circleObj;
	circleObj.draw(); // call overridden draw() function from Circle
	
	//Square sq;
    //sq.draw();	// call overridden draw() function from Square
	
	/* Topic24: classes
	 * blueprint/template/recipe 
	 * every obj is instantiated and can have multiple instances.
	 * obj are independent
	 * syntax:
	 * class <name> {
	 * //members are private by default
	 * <modifiers>:
	 * <member variables>
	 * <member function>
	 * }
	 */
	Car::showTotalObj();
	Car carObj(8.5); // since parameterized constr., we need to provide a value for param fuel
	//carObj.fillFuel(9.5);
	int accel=4;
	
	while(accel!=0)
	{
		carObj.accelerate();
		--accel;
	}
	carObj.dashboard();
	
	/* Topic26: Non static data member initializer
	 * 
	 */
	cout << "\nTopic26, non static data member initializer c++!" << endl;
	vehicle vehObj;
	std::cout << "\nInitialized non static data member from its own values:" << endl;
	vehObj.printVehicle();
	std::cout << "\nInitialized non static data member from args to object:" << endl;
	vehicle vehObjParamConstr(5);
	vehObjParamConstr.printVehicle();
	
	/* Topic27: this pointer
	 * hidden pointer passed to member function
	 * points to obj that invoked the member function
	 * provided as a keyword that is meaningful only in mem-function
	 * can be used to access mem- inside the member function
	 * 
	 * can not assign any addr to this pointer. as it is constant
	 * asm instruction:
	 * lea ecx,[car] <--- load effective addr, take addr of car obj and put it in ecx regr.
	 * wherever this ptr is used, compiler move the addr ecx to [this]
	 * 
	 * this -> to access the members of class, and compiler use it implicitly
	 */
	 
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
	
	/* Topic28: Static member variables
	 * member variable that qualified with keyword static.
	 * not a part of obj, but belongs to class
	 * only one copy exist
	 * shared between all the obj
	 * only declared in class, but not init inside class
	 * to init SMV, they have to defined outside class
	 * if initializer is not specified, the default value of type is assigned.
	 * e.g. Car.h
	 * class Class{ static int totalCars;}
	 * Car.cpp
	 * int Car::totalCars; //= 10; or default init to 0
	 */
	
	cout << "\nTopic28, Car total Obj count!" << endl;
	Car C1, C2, C3;
	
	carObj.dashboard();
	
	/* Topic29: static member function
	 * what if we dont have obj of carObj
	 * how do we know the counter of cars/obj
	 * for this we need static member function (SMF) belongs to class
	 * SMF are with keyword static declard only in the declaration.
	 * belongs to class not the obj.
	 * don't receive this pointer
	 * so, cannot access non-stat members of class from SMF
	 * SMF can be invoked through class name /its obj
	 */
	Car::showTotalObj()/*const*/;	//Topic30: Const Member Function (CMF) with const qualifier

	
	/* Topic30: Const Member Function (CMF)
	 * CMF qualified with const keyword
	 * required in declaration and definition
	 * such function can't change the value of variable
	 * usedful for readonlz function
	 * create const obj that can create only CMF.
	 * readonly obj allow to read the state of an object only through CMF
	 * 
	 * what function can qualified with const keyword?
	 * all the mem-function that do not modify the state of objects (e.g. values)
	 * e.g. void Car::dashboard() const();
	 * void Car::dashboard() const(){ //fuel++ : not allow, since it is modify state of obj.}
	 * this->fuel++ actually appies to this-> ptr
	 */
	 const Car c4(4); // NOTE: need to defined const MF seperately
	
	/* Topic31:copy constructor
	 * used to create a copy of an object
	 * copy is created by copying values of member variables into another object
	 * compiler synthesized automatically
	 * default implementation copies values
	 * user defined implementation required for pointer members (ptr as mem of class)
	 * Q: how do we know which class required user-defined copy constr and assignment operator?
	 * if user has implemented below 3 function, should be implemented all other functions:
	 * Destructor, Copy Constr, Copy assignment operator
	 * 
	 * This is due to some allocation of resource in constructor
	 * desctructor will free the resource
	 * copy constr. and assignemnt operator will perform a deep copy
	 * NOT implementing user defined operations leads to memory leak / shallow copy
	 */
	cout << "\nTopic31, Copy Constructor!" << endl;
	int *ptr61 = new int(5);
	/* Shallow copy:
	 * only copies address, making change in ptr61/62, 
	 * all other ptr will be reflected that holds same address.
	 */	
	int *ptr62 = ptr61;
	
	Car CarObjCopyConstr;
	/*
	//NOTE: to run this, comment line of code from main Topic35, MoveSema below
	Car CarObjCopyConstr1(CarObjCopyConstr);
	CarObjCopyConstr.setValue(9);
	cout << CarObjCopyConstr.getValue() << endl;
	*/

	/* deep copy:
	 * allocate new memory and copy value at the address. 
	 */
	int *ptr63 = new int (*ptr61); //user-defined copy constr.
	
	/* Topic32: Delegating constructor  
	 * Allows constr to invoke other constr
	 * useful when multiple constr present in class, all constr have do common initialization
	 * using Deleg-constr replace the common initialization
	 * reduce duplicate initialization code in multiple constr
	 * e.g.
	 * class Class{
	 * Class():Class(v1,v2);
	 * Class(a1,a2){// initialization code
	 * 
	 * code form constr will be repeated in few of other constr
	 * this is source of bug, in one of constr some init may skip
	 * C++11 concept, that common init code keep in Deleg-constr and 
	 * other constr will delegates the call to this constr
	 */ 
	 //check line#82/95 form classesObjects.cpp
	 
	/* Topic33: Default/Deleted Function
	 * default keyword with destructor, copy constr, assignments operator.
	 * can used with function, that can be synthesized by compiler.
	 * 
	 */
	Integer intObj;
	Integer intObj1(intObj);
	intObj.getValue();
	intObj.setValue(7);
	intObj.getValue();
	/* it will work and give warning, but accept the input val as INT, nit float
	 * since setValue is not yet defined with delete keyword
	 * it expect to check function setValue which accept float ass an args.
	 * this will failed since, it attempt to reference a deleted function.
	 * 
	 */
	//intObj.setValue(7.9); //error with delete keyword for copy constr.
	intObj.getValue();
	
	/* Topic34, L& R-value:
	 * L-value: has a name, All variable, can assigned values,
	 * persist beyond the expression, function that return by reference return L-vaues
	 * we can create L-value reference (C++11)-> ref to L-value
	 * 
	 * R-value:doesn"t have a name, tempo value, cannot assign values,
	 * doesn't persist beyond the expression, function that return by value return R-vaues
	 * we can create R-value reference (C++11)-> ref to R-value.
	 * to implements move sementics.
	 * reference created to temporary, represent temp value.
	 * created with && operator, cannot point to L-value
	 * R-value references always bind to temporaries
	 * 
	 * e.g. int x= 5;
	 * x is L-value, and 5 is R-value
	 * some expression returns L & some returns R-value
	 */
	cout << "\nTopic34,R-value & L-value reference!" << endl;
	int x11=1, y11=2, z11=3;
	int resultVal = (x11+y11) * z11; //expression return R-vaues
	
	//expression return L-vaues
	++x = 6;
	
	//R-value reference
	int &&r51=10;
	int &&r52=Sum(5,8);	//expression return R-vaues
	int &&r53=7+2;	//expression return temporary
	
	int xx1=10;
	//main.cpp:1171:13: error: cannot bind 'int' lvalue to 'int&&'
	//int &&r54= xx1;
	
	int &r55=Transform(xx1);
	const int &r56 = 3;	//allow us to detect temporaries and expression
 
	//overload function based on R-val & L-val reference
	Print(xx1);	//L-value, L-value reference function
	Print(3);	//R-value, 3 is temporary: const L-value ref
	
	/* Topic35: move sementics
	 * Copy semantic: 
	 obj1, v (value type with value), ptr (ptr hold the addr, 0x104 =5) ->
	 obj2, v,(value type with value), ptr (ptr hold the addr, 0x204 =5) -> deep copy for ptr, and new memory allocation
	 * Move semantic: 
	 obj1, v (value type with value), ptr (ptr hold the addr, 0x104 =5) -> if obj1 tempo obj,created as execution of expression
	 and we want its state in some other obj. instead of deep copy, we can have obj2 ptr -> points to same addr of obj-ptr.
	 this is like shallow copy, and cause problem as one of obj is destroyed and frees mem in destructor, other ptr become dangling
	 to overcome , we will assign obj1 -> ptr -> 0x00 nullptr. so when obj1 destroyed its destructor will call delete on nullptr 
	 and this is ignored by runtime, this is how resources are stollen/moved from obj1 -> obj2. (which is faster).
	 obj2, v,(value type with value), ptr (ptr hold the addr, 0x204 =5) -> deep copy for ptr, and new memory allocation
	 How to copy / move semantics ??
	 move: an expression yeilds temporaries and copied to other obj, this invokes copy constr. by default with args.
	 we can detect temporary by implementing a constr accpets R-value reference. -> 'move constr'
	 e.g. -> classesObject.cpp & .h
	 error:
	 error: passing 'const Integer' as 'this' argument discards qualifiers [-fpermissive]
  	 312 |         temp.setValue(a.getValue() + b.this->getValue());
	 error: expected unqualified-id before 'this'
  	 312 |         temp.setValue(a.getValue() + b.this->getValue());
	  error: no matching function for call to 'Integer::Integer(int)'
 	1228 |         Integer aInt(1), bInt(4);
	1228:32: error: no matching function for call to 'Integer::Integer(int)'
 	1228 |         Integer aInt(1), bInt(4);
	 
	//Segmentaiton fault at get/SetValueMov() for *m_pMoveInt
	MoveSema aInt(1), bInt(4);
	aInt.setValueMov(Addvalue(aInt,bInt).getValueMov());
	
	Number nn1{1};
	auto nn2{nn1};
	nn2 = nn1;	//assignment operator of number class

	//createNumber returns R-value, compiler will choose move constr for Number
	//but, Number class doesn't contains move constr, 
	//so compiler will synthesized move constr from MoveSema class
	auto nn3{createNumber(3)};	
	//compiler will synthesized move assignment from MoveSema class
	nn3 = createNumber(3);
	*/

	/*Topic36, std:;move Function*/
	cout << "\nTopic36, std::move Function" << endl;
	moveFunction m1(1);	// param constr get called
	auto m2{m1};	//Function overload choose copy constr, param type is L-value
	/*
	to force the compiler to use the move constr,
	typcast on m1/object which is to be moved(instead of getting copy)
	typecast can be static value to R-value reference.
	compiler invoke move constr instead of copy
	*/
	auto m3{static_cast<moveFunction&&>(m1)};	//not readabel and intent clearly

	/* to avoid ambinuety, and provide 
	why std::move is required?
	after performing any operation , m1.setValueMoveFun(3);
	no longer needed this state, but required in some other object
	*/
	//m1.setValueMoveFun(3); const var, can't be modified
	auto m4{move(m1)};
	//m1 obj is in unspecified state, and you can reinit and use it again
	//instead of re-init, if used, program may crash
	m1.setValueMoveFun(5);
	cout << m1.getValueMoveFun() << endl;

	/*NOTE:some objects are non-copyable, but 
	they can be moved through std::move. e.g. std::unique_ptr, std::thread
	*/

	/* Topic37, mem-management, Smart pointer*/
	cout << "\nTopic37, mem-management, Smart pointer" << endl;
	operate(5);	// check memMamangement.cpp/.h

	/*Topic38, mem-management unique_ptr-> line #42 from operate(5)->ememManagement.cpp*/
	/*Topic39, mem-management shared_ptr*/
	cout << "\nTopic38, 39, mem-management shared_ptr in c++!" << endl;
	cout << "Topic39, mem-management sharing normal ponter object in c++!" << endl;
	
	Project *prj = new Project{};
	prj->setName("1.Video Coder");
	Employee *emp1 = new Employee{};
	emp1->setProject(prj);
	Employee *emp2 = new Employee{};
	emp2->setProject(prj);
	Employee *emp3 = new Employee{};
	emp3->setProject(prj);

	showEmpInfo(emp1);
	showEmpInfo(emp2);
	showEmpInfo(emp3);
	prj->setProjectDetail();

	/* Output: 
		Employee Project Details=[Project Name], 1.Video Coder
		Employee Project Details=[Project Name], 1.Video Coder
		Employee Project Details=[Project Name], 1.Video Coder
		[Project Name], 1.Video Coder
	*/

	/*can not add the ~desctuctor() in Project and Employee class
	since Project *m_pProject{} is sharing between different Employee instances, so
	Employee instances do not owns this pointer, i.e. ~Employee() do not delete instance of project*/
	delete prj;	//delete not needed when uniue_ptr is used
	delete emp1;
	delete emp2;
	delete emp3;
	
	cout << "Topic, sharing pointer, unique_ptr<>!" << endl;
	//prjUnique ptr is shared unique_ptr, there is problem with prjUnique which become empty after eUnique1
	// and later we can not use it, cause as soon as it give to eUnique1, it looses its state.
	cout << "Topic40, smart pointer, shared_ptr<>!" << endl;
	shared_ptr<Project> prjShared {new Project{}}; 
	prjShared->setName(" shared_ptr<>, Video Coder");
	shared_ptr<Employee> eShared1 {new Employee{}};
	eShared1->setProjectShared(prjShared);
	shared_ptr<Employee> eShared2 {new Employee{}};
	eShared2->setProjectShared(prjShared);
	shared_ptr<Employee> eShared3 {new Employee{}};
	eShared3->setProjectShared(prjShared);
	
	// showEmpInfoUnique(eUnique1);
	// showEmpInfoUnique(eUnique2);
	// showEmpInfoUnique(eUnique3);
	prjShared->setProjectDetail(); // after above problem occurred, code will crash here.
	
	/*Topic40, smart_ptr : shared_ptr*/
	/*shared_ptr allows sharing of underline ptr to other objects
	shared_ptr supports copy (copy assignment)
	even project wil have multiple employees, creating array/list of unique_ptr of Employee -> won't work
	when create instance of Employee ->it should be a shared_ptr.
	inside shared_ptr, ref count is maintained and shared between all copies
	we can check count of ref created through function

	NOTE: when all shared_ptr are destroyed by destructor, then reference count =0, then undeline pointer gets deleted
	if one of shared_ptr destroyed, internally it will destroy shared_ptr -> prjShared
	in destructor of shared_ptr, reference count will be decremented by one.
	if result will not zero, then destructor won't do anything
	*/
	//replace all above unique_ptr -> shared_ptr
	cout << "shared_ptr, prjShared reference count=" << prjShared.use_count() << endl;

	//shared_ptr contains same method what unique_ptr has
	if(eShared3)
	{
		//valid ptr
	}
	else
	{
		//not valid ptr
	}
	//underline obj can destroy reset() like unique_ptr
	eShared3.reset();	//this will just decrement the referenec count by 1, but not desrtoy until ref count =0 
	//below, smart_ptr decrement ref count, if ref count=0, delete underline ptr, otherwise do nothing
	//take ownership of new ptr Emplyee{}, ref cnt= 1 for eShared2 ptr
	eShared2.reset(new Employee{});

	/*Topic41, Smart_ptr -> weak_ptr*/
	//drawback of normal and shared_ptr (with respect to reference counter)
	cout << "Topic41, smart pointer (reference count), shared_ptr<>!" << endl;
	Printer prn;
	int numb {};
	cout<< "Enter the <10 or >10 here=" << endl;
	cin >> numb;
	//int *p16 = new int{numb};	//Topic41-1, allocate mem for the number
	shared_ptr<int> p16{new int{numb}}; //Topic41-2
	//Topic41-2, when we pass shared_ptrp16 to setPtrValue -> refernce cnt become 2
	prn.setPtrValue(p16);	//prn obj assign here, to p16
	//add few more conditions to *p16
	if (*p16 > 10)
	{
		/* p16 may get deleted here
		mem addr m_ptrShared has get deleted
		m_ptrShared points to invalid memory*/
		//delete p16;	//Topic41-1, normal ptr, if p16 value is more than 10, we can delete ptr p16
		/*Topic41-1 & 41-2, after returning from setPtrValue -> reference cnt become 
		//41-2, so underline memory won't get deleted
		if Printer prn pointer destroyed late, then memory allocated to shared_ptr p16, remained in use.
		not deleted in below line
		NOTE --> we need the mechanism where p16 ptr is destroyed, then m_ptrShared ptr should know that 
		underline memory has been released
		So, we need weak_ptr to filfil the gap to know prn about underline ptr are destroyed
		*/
		p16 = nullptr;	//good practice
	}
	/*
	//Topic41-1, if *p16 =11, output:
	value of m_ptrShared=7629248 (junk value)
	
	//Topic41-2, with shared_ptr: 
	Enter the <10 or >10 here=
	8
	Reference count=2 <<------
	value of m_ptrShared=8
	&&&&&&&&&
	shared_ptr, prjShared reference count=4
	Enter the <10 or >10 here=
	11
	Reference count=1 <<------
	value of m_ptrShared=11
	*/
	prn.printPtr();
	// below delete() won't do anything, if don't assign nullptr, this will leads to double delete situation
	//delete p16;	//Topic41-1, normal ptr,

	/*Topic42, weak_ptr:
	e.g.
	1. shared_ptr<int> pShared{new int{5}} -> mem allocated for the integer (value=5)
	shared_ptr pShared -> create control block internally, which contains info about mem-block allocated
	also iit contains, reference count = 1 (for pShared shared_ptr)

	if 
	2. weak_ptr<int> pWeak = pShared; created, which is always init with shared_ptr
	internally points to control block, and has info about reference count also.
	3. pShared.reset(); 	// mem released and shared_ptr destroyed
	in its destructor reference count will decrement by one.
	reference cnt =0, weak_ptr points to same control block
	when ctrl block destroy ? and what is its purpose?
	ctrl block destroyed when weak_ptr is destroyed
	that means you can have multiple weak_ptr pointing to same shared_ptr
	means  multiple weak_ptr pointing to same control blocks
	
	internally control block maintain another reference counter for weak_ptr 
	and ctrl block destroyed when weak cnt =0.
	assume underline ptr need to access through weak_ptr -> can't access directly
	instead expire() internal method has to call here.
	expire() check reference count for weak_ptr 
	
	if reference count=0, expire returns TRUE 
	that means shared_ptr and underline memory no longer available
	else FALSE -> (ref cnt > 0), and shared_ptr still exist.
	there for, we can access underline ptr through the weak_ptr
	we need to use lock(), and lock() will increment reference cnt by one and return shared_ptr
	possible that other shared_ptr might get destroyed.
	even if it is destroyed then reference cnt won't become zero.
	cause we applied lock() using weak_ptr
	after use of this shared_ptr got from lock() method, its destructor will decrement reference cnt
	if reference cnt as usual is zero , then it will free the underline memory
	*/

	//void learnWeakPtr();
	/*
	output1:
	weak_ptr, Enter the <15 or >15 here=14
	value of m_ptrShared=14
	Reference count=2

	output2:
	weak_ptr, Enter the <15 or >15 here=16
	Resource is no longer available!
	*/
	printerWeak prnWeak;
    int numWeak{};
    cout<< "weak_ptr, Enter the <15 or >15 here=" << endl;
    cin >> numWeak;
    shared_ptr<int> pPtrShared{new int {numWeak}};
    prnWeak.setPtrValueWeak(pPtrShared);
    if (*pPtrShared>15)
    {
        pPtrShared = nullptr;
    }
    prnWeak.printWeakPtr();
	
	/*Topic43-1, Circular Reference
	43-1: raw pointer example
	class EmployeeCir;
	1. class Circular -> public: EmployeeCir *m_empCircle
	2. contain constr and Destructor of Circular
	3. class EmployeeCir -> public: Circular  *m_Cirular
	4. contain constr and Destructor of EmployeeCir
	5. main() -> EmployeeCir *empCir, Circular *Cir, 
	6. empCir->m_Circle = Cir; Cir->m_Circle = empCir;
	7. delete empCir, Cir.
	output: both the constr and destructor are call correctly, and there is no mem-leak
	EmployeeCir()
	Circular()
	~EmployeeCir()
	~Circular()
	*/
	//learn about memory leak shared_ptr
	EmployeeCir *empCir = new EmployeeCir{};	//instance of EmployeeCir
	Circular *Cir = new Circular{};	//instance of Circular

	empCir->m_Circular = Cir;	//init pointer empCir and assign it to Cir
	Cir->m_empCir = empCir;	//init pointer Cir and assign it to empCir

	/*
	43-2: Replace raw pointer with shared_ptr
	delete not needed cause of shared_ptr
	delete empCir;	//destroy both ptr
	delete Cir;
	output:
	43-2: Replace raw pointer with shared_ptr
	EmployeeCir()
	Circular()
	EmployeeCir()
	Circular()
	--> No destructor called, cause memory leak here, here we need to prefer the weak_ptr inside one of class
	*/
	shared_ptr<EmployeeCir> empCirShar {new EmployeeCir{}};	//43-2, shared_ptr
	shared_ptr<Circular> CirShar {new Circular{}};	//43-2, shared_ptr

	empCirShar->m_CircularShared = CirShar;
	CirShar->m_empCirShared = empCirShar;

	/*
	Topicxx: Microcontroller, bitwise operation, Register set/clear/reset
	*/
	cout << "\nTopicxx, Microcontroller, bitwise operation in c++!" << endl;
	
	//REG_0{ 0b0000'0000 };	//8 bits in size means room for 8 flags
	cout << "REG_0, init value=" << std::bitset<8>(REG_0) << endl;
	
	/*Bitwise: bit_set*/
	REG_0 |= (1 << 0);	//0 -> index 
	// << "mask0=" << static_cast<int>(mask0) << endl;	//mask0 = 1
	cout << "REG_0, after mask0=" << std::bitset<8>(REG_0) << endl;
	
	REG_0 |= (1 << mask0);
	cout << "REG_0, after mask1=" << std::bitset<8>(REG_0) << endl;
	std::cout << "bit 1 of REG_0 is " << (static_cast<bool>(REG_0 & mask0) ? "on\n" : "off\n") << endl;
	
	/*Bitwise: bit clear*/
	//REG_0 = bit_clear(REG_0, static_cast<int>(mask0));
	REG_0 = bit_clear(REG_0, 0);
	cout << "REG_0, after 0th, bit_clear()=" << std::bitset<8>(REG_0) << endl;
	
	REG_0 |= (mask4 | mask5);
	cout << "REG_0, after SET(mask4 | mask5)=" << std::bitset<8>(REG_0) << endl;

	REG_0 &= ~(mask4 | mask5);
	cout << "REG_0, after CLEAR(mask4 | mask5)=" << std::bitset<8>(REG_0) << endl;

	cout << "I2C_GPS_ANTENNA_PIN, initial value=" << bitset<8>(I2C_GPS_ANTENNA_PIN) << endl;
	isSet_GPS_PIN = bit_check(I2C_GPS_ANTENNA_PIN, 4);//, static_cast<int>(PIN_5));
	cout << "I2C_GPS_ANTENNA_PIN, after bit_check()=" << isSet_GPS_PIN << endl;
	//I2C_GPS_ANTENNA_PIN = bit_set(REG_0, static_cast<int>(PIN_1));

	

	//cout << atext("Main function End...!") << endl;
	/*atexit registers ptr to function internally in C library
	 * atexit invoke function pointer at end of main()
	 */
	std::cout << "\nTopicLast, atexit:" << endl;
	atexit(endMessage);
	cout << "!End of Main()!" <<endl;
	
	return 0;
}