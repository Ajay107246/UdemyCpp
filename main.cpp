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
#include <cstdlib>
#include <string>
//#include <ctype.h>
#include <cctype>
#include <sstream>
#include <complex>
#include <chrono>	//for chrono_literals
#include <initializer_list>
#include <cassert>
#include <vector>
#include <typeinfo>
#include <experimental\filesystem>



//user defined headers
#include "oopsConcept.h"
#include "classesObjects.h"
#include "binaryOperations.h"
//#include "moveSemantic.h"	//error: segmentation fault at *m_pMoveInt
#include "moveFuntion.h"
#include "memManagement.h"	//Topic27, mem-mangt, smart-ptr
//#include "../header/Account.h"
#include "Account.h"
#include "Checking.h"
#include "Saving.h"
#include "Transaction.h"
#include "FinalOverride.h"
#include "abstractClass.h"
#include "diamondClass.h"
//#include "exceptionHandling.hpp"
#include "header/exceptionHandling.hpp"
#include "header/fileHandling.hpp"
#include "header/binFileHandling.hpp"
#include "header/templateEx.hpp"

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
using namespace string_literals;
using namespace std::experimental::filesystem;

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
/*learn shared_ptr Drawback with reference count not becoming = 0*/
void learnSharedPtrDrawback(Printer* prn, int numb)
{
	//int *p16 = new int{numb};	//Topic41-1, allocate mem for the number
	shared_ptr<int> p16{new int{numb}}; //Topic41-2
	//Topic41-2, when we pass shared_ptrp16 to setPtrValue -> refernce cnt become 2
	prn->setPtrValue(p16);	//prn obj assign here, to p16
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
	prn->printPtr();
	// below delete() won't do anything, if don't assign nullptr, this will leads to double delete situation
	//delete p16;	//Topic41-1, normal ptr,
}

/*Topic42, learn smart_ptr -> weak_ptr (w.r.t. to benefits of refernce count)*/
void learnWeakPtr(printerWeak* prnWeak, int numWeak)
{
	cout << "numWeak to check availble/valid or not=" << numWeak << endl;
	shared_ptr<int> pPtrShared{new int {numWeak}};
    prnWeak->setPtrValueWeak(pPtrShared);
    if (*pPtrShared>15)
    {
        pPtrShared = nullptr;
    }
    prnWeak->printWeakPtr();
}

/*Topic44, deleter, custom deleter, function object*/
struct Free{
	//everything will be public, can even use class
	void operator()(int *p)
	{
		free(p);
		cout << "pointer freed from custom deleter, Function object!" << endl;
	}
	//how to invoke deleter, checkout main function topic44
};

/*Topic44, deleter, custom deleter, function object*/
void MallocFree(int *p)
{
	free(p);
	cout << "pointer is freed from custom deleter function!" << endl;
}

void Unique_ptrDeleter()
{
	unique_ptr<int> p17{(int *) malloc(4)};
	*p17 = 200;
   	cout << "\nunique_ptr Deleter, p17=" << *p17 << endl;	//undefined behavior
	/*
	6. above code might end with undefined behavior while managing file stream ptr/handler
	7. resources won't release properly, cause it will delete but not function that will close stream
	8. e.g. we need to manage resource: (int *) malloc(4)
	9. can create custom deleter, which can be global fuction, function object, / lambda expression / any callable
	10. function object: simple function that has a state
	11. fun'obj can created by overloading function call operator
	12. see above main()  

	output:
	unique_ptr with custom deleter, value for *p18=150
	~~~~~
	TopicLast, atexit:
	!End of Main()!
	pointer freed!

	13. we also function as custom deleter
	*/
	//smart_ptr with custom deleter function objects
	//recommend this, when don't contains any attributes
	unique_ptr<int, Free> p18{(int*) malloc(4), Free{}};	// <xx, Free> -> type of delter, Free{} -> obj of this class 
	*p18=150;
	cout << "unique_ptr with custom deleter function Object, value for *p18=" << *p18 << endl;

	unique_ptr<int, void(*)(int*)> p19{(int*) malloc(4), MallocFree};	//type of function ptr -> <xx, void(*)(int*)>; type address of funciton -> MallocFree}
	/* custom deleter function :
	this will increase the sizeof unique_ptr object
	to avoid this prefer use of function obj -> struct Free{};

	output:
	unique_ptr with custom deleter function, value for *p19=175

	!End of Main()!
	pointer is freed from custom deleter function!

	OR
	Topic44, Deleter, p17=200
	unique_ptr with custom deleter -> fun Obj, value for *p18=150
	unique_ptr with custom deleter function, value for *p19=175
	pointer is freed from custom deleter function!
	pointer freed from custom deleter, Function object!
	*/
	*p19 = 175;
	cout << "unique_ptr with custom deleter function, value for *p19=" << *p19 << endl;

}


void Shared_ptrDeleter()
{
	shared_ptr<int> p20{(int*) malloc(4), Free{}};	//no need to mentioned type of deleter
	*p20 = 250;
	cout << "\nshared_ptr with custom deleter function object, value for *p20=" << *p20 << endl;

	shared_ptr<int> p21{(int*) malloc(4), MallocFree};		//no need to mentioned type of deleter as template arg	
	*p21 = 275;
	cout << "shared_ptr with custom deleter function, value for *p21=" << *p21 << endl;

	/* output:
	shared_ptr with custom deleter function object, value for *p20=250
	shared_ptr with custom deleter function, value for *p21=275
	pointer is freed from custom deleter function!
	pointer freed from custom deleter, Function object!
	*/
}

/*Topic46, move function to allocate memory while using smart_ptr*/
class MoveAllocMem
{
	public:
	MoveAllocMem(int x, int y)
	{
		cout << "Move() function with smart_ptr: mem allocation! "<< x << "," << y << endl;
	}
};

/*Topic47, Raw char[]/ string*/
const char * Combine(const char * pFirstChar,const char *pSecondChar)
{
	//char combineStr[20];
	char *combineStr = new char[strlen(pFirstChar) + strlen(pSecondChar)];
	strcpy(combineStr, pFirstChar);
	strcat(combineStr, pSecondChar);

	return combineStr;	
	/* warning: 
	the scope of combineStr is limited to this combine funciton only 
	no guarantee it will return the combineStr to inside main...
	*/
}

void toUpperCase(char* str20){
	for(int i = 0; str20[i]; ++i)
	{
		str20[i] = toupper(str20[i]);
	}
}

void toLowerCase(char* str20){
	for(int i = 0; i<strlen(str20); ++i)
	{
		str20[i] = tolower(str20[i]);
	}
}

/*Topic48, User-defined Literals*/
class Distance 
{
	long double m_kilometers;
	public:
	Distance(long double km) :m_kilometers{km}{

	}
	long double getKm()const
	{
		cout << "Meter Reading: " << m_kilometers << " K.M." << endl;
		return m_kilometers;
	}
	void setKm(long double val)
	{
		m_kilometers = val;
	}
};

/*Topic48, liternals, if distance needs to be printed in miles*/
Distance operator"" _mi(long double val)
{
	return Distance {val * 1.6};
}

/*Topic48, liternals, if distance needs to be printed in metres*/
Distance operator"" _metres(long double valMet)
{
	return Distance {valMet / 1000};
}

/*Topic48, Literals , some more examples
user-defined literals (UDLs) are the way to provide custom literals
that can make code readable and more expressive
*/
constexpr long double operator"" _km(long double valKm){
	return valKm * 1000;
}
constexpr long double operator"" _m(long double valMeter){
	return valMeter;
}
//complex number -> literals
complex<long double> operator"" _i(long double valComplex){
	return complex<long double>(0, valComplex);
}
//string literals
string operator"" _s(const char* valString, size_t){
	return string(valString);
}
//UDLs for binary numbers
unsigned long long operator"" _bin(const char* valBin){
	unsigned long long result = 0;
	while(*valBin){
		result = (result << 1) | (*valBin++ - '0');
	}
	return result;
}
//UDLs for time duration
using namespace std::chrono_literals;

/*Topic49, constexpr : constant expression*/
constexpr int getConstexprNumber()
{
	return 40;
}

constexpr int AddValConstr(int x, int y)
{
	return x+y;
}
//constexpr function can only have one return statement
//this is relax in C++14, but will not work in earlier c++ version
constexpr int maxNum(int x, int y)
{
	if(x>y)
	{
		return x;
	}
	return y;
}

/*Topic50, initializer_list, with template class*/
class Bag
{
	int arr5[10];
	int m_size;
	public:
	//constr -> accept initializer_list as arg
	//this should work with Bag {1,2,3,4};
	Bag(initializer_list<int> values)
	{
		//access elements using iterators
		assert(values.size() < 10);
		auto it = values.begin();	// behaves like ptr to array
		while(it != values.end())
		{
			AddvalArr(*it);
			++it;
		}
	}
	void AddvalArr(int val)
	{
		assert(m_size < 10);
		arr5[m_size++] = val;
	}
	void RemoveElement()
	{
		--m_size;
	}
	//opeartor eubscript->[] overloaded to access elements in array
	int operator [](int index)	
	{
		return arr5[index];
	}
	int getSize()const
	{
		return m_size;
	}
};

/*Topic50, initializer_list used to print simple list*/

void PrintIinitList(initializer_list<int> values)
{
	auto it = values.begin();
	cout << "value in initializer_list=" << endl;
	// while(it!= values.end())
	// {
	// 	cout << *it++ << "\t"; 
	// }
	//range based for loop iterators
	for(auto x: values)
	{
		cout << x << "\t";
	}
}

/* Topic52, Union in C++
1. Dis/Advantage of creating instance of struct inside union
*/
union TestUnion
{
	int x;
	char ch;
	TestUnion():ch{'a'}{
		//cout << __FUNCSIG__ << endl;
		cout << __PCTYPE_FUNC << endl;
	}
	~TestUnion()
	{
		cout << __PCTYPE_FUNC << endl;
	}
};
struct As
{
	As()
	{
		cout << "As()" << endl;
	}
	~As()
	{
		cout << "~As()" << endl;
	}
	As(As&& other)noexcept
	{
		cout << "As&&()" << endl;
	}
	As& operator=(const As& other)noexcept
	{
		cout << "As& operator=()" << endl;
		if (this == &other)
		{
			return *this;
		}
		return *this;
	}
	
	As& operator=(As& other)noexcept
	{
		cout << "As& operator=()" << endl;
		if (this == &other)
		{
			return *this;
		}
		return *this;
	}
};

union UDT
{
	As a;	//union member 'UDT::a' with non-trivial 'As::~As()'
	string strUnion;
	UDT(){}	//cause class/struct has thier user-defined constr/destructr
	~UDT(){}
};

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
	cout << "Topic41-2, smart pointer (drawback reference count), shared_ptr<>!" << endl;
	Printer prn;
	int numberChk {};
	cout<< "Enter the <10 or >10 here=" << endl;
	//cin >> numb;
	numberChk = 9;
	learnSharedPtrDrawback(&prn, numberChk);
	numberChk = 11;
	learnSharedPtrDrawback(&prn, numberChk);

	/*
	//int *p16 = new int{numb};	//Topic41-1, allocate mem for the number
	shared_ptr<int> p16{new int{numb}}; //Topic41-2
	//Topic41-2, when we pass shared_ptr p16 to setPtrValue -> refernce cnt become 2
	prn.setPtrValue(p16);	//prn obj assign here, to p16
	//add few more conditions to *p16
	if (*p16 > 10)
	{
		//  p16 may get deleted here
		// mem addr m_ptrShared has get deleted
		// m_ptrShared points to invalid memory
		// //delete p16;	//Topic41-1, normal ptr, if p16 value is more than 10, we can delete ptr p16
		// Topic41-1 & 41-2, after returning from setPtrValue -> reference cnt become 
		// //41-2, so underline memory won't get deleted
		// if Printer prn pointer destroyed late, then memory allocated to shared_ptr p16, remained in use.
		// not deleted in below line
		// NOTE --> we need the mechanism where p16 ptr is destroyed, then m_ptrShared ptr should know that 
		// underline memory has been released
		// So, we need weak_ptr to filfil the gap to know prn about underline ptr are destroyed
		
		p16 = nullptr;	//good practice
	}
	
	// //Topic41-1, if *p16 =11, output:
	// value of m_ptrShared=7629248 (junk value)
	
	// //Topic41-2, with shared_ptr: 
	// Enter the <10 or >10 here=
	// 8
	// Reference count=2 <<------
	// value of m_ptrShared=8
	// &&&&&&&&&
	// shared_ptr, prjShared reference count=4
	// Enter the <10 or >10 here=
	// 11
	// Reference count=1 <<------
	// value of m_ptrShared=11
	
	prn.printPtr();
	// below delete() won't do anything, if don't assign nullptr, this will leads to double delete situation
	//delete p16;	//Topic41-1, normal ptr,
	*/

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
    cout<< "\nTopic42,weak_ptr, input <15 or >15 here=" << endl;
    //cin >> numWeak;
	/*
	<int> pPtrShared{new int {numWeak}};
    prnWeak.setPtrValueWeak(pPtrShared);
    if (*pPtrShared>15)
    {
        pPtrShared = nullptr;
    }
    prnWeak.printWeakPtr();
	*/
	numWeak = 16;
	learnWeakPtr(&prnWeak, numWeak);
	numWeak = 14;
	learnWeakPtr(&prnWeak, numWeak);
	
	
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
	cout << "\nTopic43-1, learn Circular reference - raw _ptr" << endl;
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
	cout << "Topic43-2, learn Circular reference - shared_ptr (memory leak, with no destructor call)" << endl;
	shared_ptr<EmployeeCir> empCirShar {new EmployeeCir{}};	//43-2, shared_ptr
	shared_ptr<Circular> CirShar {new Circular{}};	//43-2, shared_ptr

	/*43-2, shared_ptr, ref. cnt= 2, underline memory is not release
	after one ptr from class destryed , remained ref. cnt= 1
	this cause memory leak
	*/  
	//empCirShar->m_CircularShared = CirShar;	
	//CirShar->m_empCirShared = empCirShar;	//43-2, shared_ptr, ref. cnt= 2, underline memory is not release

	/*
	43-3: Replace shared_ptr pointer with 
	1. instance of shared_ptr<EmployeeCir> m_empCirShared;
	2. instance of Circular *m_Circular;
	3. both smart_ptr has reference count=1 each
	4. Circular *m_Circular assign into the EmployeeCir -> weak pointer -> weak_ptr<Circular> m_CircularShared;
	5. weak_ptr<Circular> m_CircularShared; -> not increment the ref counter
	6. when use of methods from weak_ptr -> m_CircularShared inside EmployeeCir class,
	7. need to check if weak_ptr is expired /not
	8. if not expire, then apply/use lock().
	9. then use the method
	10. instance of shared_ptr<EmployeeCir> m_empCirShared; -> inside Circular class, -> ++1, reference count 
	11. reference count =2 for EmployeeCir
	12. how it will solve the porblem?
	13. at end of scope, obj of EmployeeCir is destroyed -> reference count -1/ which is become =1
	14. then weak_ptr<Circular> m_CircularShared destroyed, become =0
	15. this will call delete for undeline ptr
	16. Circular ptr will get deleted, then obj is destroyed
	17. then delete will be invoke on EmployeeCir ptr
	18. so there are no memory leak

	NOTE: you can use weak_ptr in either one of / both class

	output:
	Topic43-2, learn Circular reference - shared_ptr (memory leak, with no destructor call)
	EmployeeCir()
	Circular()
	Topic43-3, learn Circular reference - weak_ptr, shared_ptr (No memory leak)

	NOTE: destructor called at end of main()
	TopicLast, atexit:
	!End of Main()!
	~Circular()
	~EmployeeCir()
	*/
	//comment out previous call to pointers 
	//since it will not allow to print together with below calls
	cout << "Topic43-3, learn Circular reference - weak_ptr, shared_ptr (No memory leak)" << endl;
	empCirShar->m_CircularWeak = CirShar;	
	CirShar->m_empCirShared = empCirShar;

	/*Topic44, Deleter
	1. malloc, new -> cals free() and delete to free the memory or resources
	2. smart_ptr calls deleter while release resources automatically
	3. deleter is callback that releases a resource
	4. if there is need to delete different kind of resources, then user-defined deleter should be used
	5. deleter can be any kidn of callable

	you can use smart_ptr to manage any kind of resource, that cannot be released by simple delete call
	*/
	cout << "Topic44, Learn custom deleter function/obj. , with unique_ptr & shared_ptr" << endl;
	Unique_ptrDeleter();
	Shared_ptrDeleter();	//no need to mentioned type of deleter in template argument in shared_ptr<int>


	/*Topic45, Dynamic Array using smart_ptr
	1. unique_ptr calls default deletem and not delete subscript [5]{} 
	2. this leafs to undefined behavior
	3. using smart_ptr -> cannot directly access the elements of dynamic array using array syntax
	4. p22[0] = 10; -> cannot be used, cause this operator doesn't provided by unique_ptr
	5. possible to acces p22.get()[0] = 10;
	6. same thing applicable to shared_ptr

	7. so, don't use  a dynamic array with smart_ptr, cause default deleter will call delete
	8. but writing custom deleter is possible, 
	but it will increase the code size without benefits of subscript operator -> []
	solution -> 
	10. to use partial specialization of unique_ptr for array types

	*/
	//unique_ptr<int> *p22{new int[5]{1,2,3,4,5}}; //calls default deleter and not delete subscript [5]{}, indivual elements not accessable
	//error: cannot convert 'int*' to 'std::unique_ptr<int []>*' in initialization
	//unique_ptr<int[]> *p22{new int[5]{1,2,3,4,5}};	// use subscript []]operator to get access for indivual arr elements, p22[0]
	//error: no match for 'operator=' (operand types are 'std::unique_ptr<int []>' and 'int')
	//p22[2]= 6; //possible cause of <xxx[]> inside unique_ptr, calls correct deletor
	
	//specialization and operator added in c++17
	//may not work with C++11/14 std
	//cannot convert 'int*' to 'std::shared_ptr<int []>*' in initialization
	//<int[]> *p23{new int[5]{1,2,3,4,5}};	
	//no match for 'operator=' (operand types are 'std::shared_ptr<int []>' and 'int')
	//p23[1]= 5;

	/*note: 
	1. ideally to avoide creating dynamic array like above
	2. use container (grow at runtime, e.g. vector<int>, automatically manage growth of array)
	3. if need to create a fix size dynamic array & 
	no need to deal with memory management, use shared_ptr, and unique_ptr
	*/

	/*Topic46, make function:
	1. modern c++ discouranges manual memory management
	2. avoid using new and delete in our code
	3. for smart_ptr, new is usede to allocate memory, and can be avoided
	4. smart_ptr provide a global function that 
	smart_ptr can construct without having manually allocate a memory for undelying resources
	5. those global functions are make() functions for shared_ptr, and unique_ptr
	6. make_unique() factory function, it creates instance of class
	7. accepts arbitary type and number of args.
	8. its a function template and must specify type of object to be construct
	9. no need to suse new operator in code,
	10. can be use to construct dynamic arrays
	11. 

	*/

	//unique_ptr<int> p24{new int{5}}; //can be avoided cause manually allocation of memory
	cout << "\nTopic46, Learn move() function, with unique_ptr & shared_ptr!" << endl;
	auto p25 = make_unique<int>(5);
	auto p26 = make_unique<MoveAllocMem>(3, 7); //MoveAllocMem -> type, (3,7)-> args pass to constr to MoveAllocMem

	auto pArr = make_unique<int[]>(5);	// [] -> empty subscript, and (6) size of array
	pArr[0] =2;

	/*can be done for shared_ptr -> make_shared -> C++20 std
	shared_ptr implemented differently than unique_ptr
	it has store more info regarding underlying ptr inside control blocks.
	allocate mem using one new call
	during destruction, there is only one delete call for underlying resource & contro block
	saves multiple calls to new and delete operator (not applicable to make_unique:does not store any info except ptr)
	*/

	auto p27 = make_shared<int>(5);
	auto p28 = make_shared<MoveAllocMem>(3, 7); //MoveAllocMem -> type, (3,7)-> args pass to constr to MoveAllocMem

	//error: no matching function for call to 'make_shared<int []>(int)'
	//auto pArrShare = make_shared<int[]>(5);	// [] -> empty subscript, and (6) size of array
	//pArr[0] =2;

	/*Topic47, 47-1, Raw string*/
	char firstChar[10] = "Ajay";
	char secondChar[10] ="Shimpi";
	char finalString[20];
	//cout << "Enter First and Second character string (<10 char):" << endl;
	//cin.getline(firstChar, 10);
	//cin.getline(secondChar, 10);

	// return value from Combine has limited scope to itself, and then no value will be return
	/*
	1. const char *pFinalName = new char[strlen(firstChar) + strlen(secondChar)];
	2. here normal char string is null terminated, and required 1 extra byte here.
	3. while allocating pFinalName -> this takes without null char size of 1 byte
	4. there will cause buffer overflow
	5. and without extra 1 byte for null char, this will crash the program in runtime
	6. detects memory has been correpted
	7. so, const char *pFinalName = new char[strlen(firstChar) + strlen(secondChar)+ 1];
	8. this is error prone and cause run time problem.
	9. we need choose std::string librery provided in C++
	*/
	const char *pFinalName = Combine(firstChar, secondChar);	
	
	strcpy(finalString, firstChar);
	strcat(finalString, secondChar);

	cout << "\nTopic47-1, raw char string=" << finalString << endl;
	cout << "Topic47-1, raw char string with ptr =" << pFinalName << endl;
	delete[] pFinalName;

	/*Topic47-2: String class
	std::string -> memory allocation deallocation automatically done by string class
	*/
	string str11 = "Hello";
	string str12 = ("NIce");
	string str13 {"World"};
	string str14;
	str14 = "!";

	cout << "\nTopic47-2, string library!" << endl;
	cout << "All strings="<< str11 << " " << str12 << " " << str13 << str14 << endl;

	string str15 = str11 + " " + str12 + " " + str13;
	cout << "str15= " << str15 << endl;

	char ch = str12[1];
	cout << "ch=str12[1]:" << ch << endl;
	cout << "before, str12=" << ch << endl;
	str12[1] = 'i';	// Modifying the second character of NIce -> Nice
	cout << "after, str12[1] = 'i':" << str12 << endl;

	size_t pos = str15.find("Nice");	//finding substring with its position

	/*
	Maximum Value: std::string::npos is defined as static const size_t npos = -1;. 
	Since size_t is an unsigned type, -1 is converted to the largest possible value for size_t12.
	Usage in Functions: It is often used in functions that deal with 
	string indices to indicate “until the end of the string” or “no match found.” 
	Functions like find, rfind, find_first_of, and find_last_of return std::string::npos 
	when they fail to find the specified substring or character
	*/
	if(pos!=string::npos)
	{
		cout << "Nice occurance found at: " << pos << endl;	 
	}
	else
	{
		cout << "Nice is not found!" << endl;
	}
	size_t pos2 = str15.find("NIce");
	if(pos2!=string::npos)
	{
		cout << "NIce occurance found at: " << pos2 << endl;	 
	}
	else
	{
		cout << "NIce is not found!" << endl;
	}
	//substring extraction
	string str16 {"Hello World!"};
	string str17 = str16.substr(6, 5);
	cout << "Substring from "<< str16 << " is " << str17 << endl;	 

	cout << "Length of string <" << str16 << "> is " << str16.length() << endl;
	if(str11 == str12)
	{
		cout << str1 <<  " and " << str12 << " are equal." << endl;
	}
	else
	{
		cout << str11 <<  " and " << str12 << " are not equal." << endl;
	}
	cout << "Inserting and erasing an element from string!" << endl;
	string str18 = ",";
	//str18 = ',';
	str15.insert(5, str18);
	cout << "str15= " << str15 << " after inserting character/string '" << str18 << "'" << endl;
	
	//string str19 = str15.c_str();
	const char* str19 = str15.c_str();
	cout << "converting " << str15 << " in c_style string using c_str(): " << str19 << endl;


	/*
	output:
	All strings=Hello NIce World!
	str15= Hello NIce World
	ch=str12[1]:I
	before, str12=I
	after, str12[1] = 'i':Nice
	Nice is not found!
	NIce occurance found at: 6
	Substring from Hello World! is World
	Length of string <Hello World!> is 12
	Hello and Nice are not equal.
	Inserting and erasing an element from string!
	str15= Hello, NIce World after inserting character/string ','
	converting Hello, NIce World in c_style string using c_str(): Hello, NIce World
	*/
	char str20[] = "Hello World";
	toUpperCase(str20);
	cout << "str20 in upper case: " << str20 << endl;
	toLowerCase(str20);
	cout << "str20 in lower case: :" << str20 << endl;

	/* TOpic47-3, formatted string
	std::stringstream -> R/W
	std::istringstream -> only read
	std::ostringstream -> only write
	*/
	cout << "Topic47-3, formatted string-> std::stringstream!" << endl;
	
	int a5 {3}, a6{7};
	int sumStream = a5 + a6;
	stringstream ss;
	ss << "Sum of " << a5 << " & " << a6 << " is: " << sumStream << endl;
	//ss return the copy  of buffer as std string object
	string str21 =  ss.str();
	cout << "str21, usage of stringstream:\n" << str21 << endl;

	/*
	this will print as below --->
	Sum of 3 & 7 is: 10
	10
	but it took previous data as well.
	to avoid or remove old string from ss stringstream 
	we need to clear this string, using ss.str("")
	*/
	ss.str("");	// clear previous data/strings
	ss << sumStream;	// this will only take value=10, won't append new string on existing string
	auto sumStream1 = ss.str();	//internally use std::to_string() convert int to string
	cout << "sumStream1, usage of stringstream:\n" << sumStream1 << endl;
	//ss.str(""); -> simply clear the string this accept the string while assinging as string to internal buffer
	
	/* Extract the integer from string:
	*/
	string data1 = "10 11 12 13 str 14 done!";
	cout << "data1:" << data1 << endl;
	int a7; //to store the int from abov edata1 string 
	stringstream extractInt;
	extractInt.str(data1);
	/*while (!extractInt.fail())	//fail()-> check for failed bit, set if stringstream fails to read input
	{
		extractInt >> a7; //>> returns a ref of stringstream obj itself
		cout << "extracted INT from string data1=> " << a7 << endl;
	}
	output:
	data1:10 11 12 13 str 14 done!
	extracted INT from string data1=> 10
	extracted INT from string data1=> 11
	extracted INT from string data1=> 12
	extracted INT from string data1=> 13
	extracted INT from string data1=> 0
	*/
	//instead of doing above condition in while()
	while (extractInt >> a7)	//fail()-> check for failed bit, set if stringstream fails to read input
	{
		cout << "extracted INT from string data1=> " << a7 << endl;
	}
	/*output:
	data1:10 11 12 13 str 14 done!
	extracted INT from string data1=> 10
	extracted INT from string data1=> 11
	extracted INT from string data1=> 12
	extracted INT from string data1=> 13
	*/

	/* assignment:
	The find function in std::string uses a case-sensitive search.
	Write a function that also performs a case insensitive search. 
	Use an enum to decide between case-sensitive and case-insensitive search. 
	The prototype of the function is:
	enum class Case{SENSITIVE, INSENSITIVE};
	
	size_t Find(
	const std::string &source,         //Source string to be searched
	const std::string &search_string,  //The string to search for
	Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
	size_t offset = 0 ) {                //Start the search from this offset
		//Implementation
	
		/*
		return position of the first character 
		of the substring, else std::string::npos
	
	Note that, we don't have direct write access to the raw string inside std::string.
	*/

	/*Topic48, user-defined literals, 
	1. fixed value that appears directly in code
	2. differnet types of literals in c++
	integer, floating points, boolean, char, string
	3. can be modified through prefix, and suffix
	14u, 621l, 9.2f, L"wide string"
	4. C++ allows to define own prefix and suffix for types -> syntactic shortcuts, increase type safety
	5. Temparature Temp{56.7};
	6. internally class can store value in celsius
	7. if we want to store it in fahreinheit, then we can create custom user-defined literals
	8. Temperature Temp {56.7_F};
	9. defined function using operator keyword
	10. <return_type> operator""_ <literal>(<arguments>)
	11. operator"": defines a literal operator function
	12. <return_type>: can be any type including void
	13. _<literal>: always start with _(undescore) followed by name
	14. <arguements>: 
	int- unsign longlong
	floating point - long double
	char - char, wchar_t, char16_t, char32_t
	string- const char *
	
	*/
	cout << "\nTopic48, user-defined literals!" << endl;
	Distance dist{32};
	long double distKim = dist.getKm();
	//cout << "\nKm distance= " << distKim << endl;

	/*
	if we want to return distance in mile instead of km
	Literal operator will create a object of Distance 
	which has been init with value while creating object {32.0_mi}  
	using literals, code can become more expressive and reduce chance of errors
	*/
	Distance distMile{32.0_mi};
	distMile.getKm();
	Distance distMeter{32500.0_metres};
	distMeter.getKm();

	long double distanceMeter = 5.0_km + 300.0_m;
	cout << "1. distanceMeter (str literal)=> " <<  distanceMeter << endl;
	
	/* Error: no match for 'operator+' (operand types are 'double' and 'std::complex<long double>')
	auto complexNum = 3.0 + 4.0_i;
	cout << "2. Complex complexNum (str literal)=> " <<  complexNum << endl;
	*/
	 
	auto myString = "Hello, This is string literals"_s;
	cout << "3. myString (str literal)=> " <<  myString << endl;

	auto binValue = 1011_bin;
	cout << "4. binValue (str literal)=> " <<  binValue  << endl;

	/* Error: 
	no match for 'operator<<' (operand types are 'std::basic_ostream<char>' and 
	'std::chrono::duration<long long int>')
	auto timeDuration = 10s + 25min;
	cout << "5. timeDuration (str literal)=> " <<  timeDuration << endl;
	*/

	/*
	output:
	1. distanceMeter (str literal)=> 5300
	3. myString (str literal)=> Hello, This is string literals
	4. binValue (str literal)=> 11
	*/

	/* 
	output:
	Topic48, user-defined literals!
	Meter Reading: 32 K.M.
	Meter Reading: 51.2 K.M.
	Meter Reading: 32.5 K.M. 
	
	Important points:
	1. custom literals should begin with _
	2. cannot re-define the meaning of in-built literals suffixes
	3. only following types can be suffixed to make a user-defined literals  
	usigned long long, long double, const char*, char
	4. Literal operator functions cannot be member functions 
	*/

	/*Topic49, constexpr: constant expressions 
	1. keyword that represent an expression that is constant
	2. evaluated at compile time
	3. keyword applied to a variable declarations or functions
	4. increse the perfomance of code as computation done at compile time
	5. constexpr <- keyword
	6. if function return a value that can computed at compile time
	   then it can be constexpr <return_type> function()
	7. such function accept and return only literal type (void and scaler types, class: has constexpr constructor)
	*/
	//Behave as constexpr
	constexpr int iConstexpr = getConstexprNumber();
	cout << "\nTopic49, constexpr: constant expresssion" << endl;
	cout << "constexpr i value=> " << iConstexpr << endl;
	int arr3[iConstexpr];
	
	//Behave as constexpr
	const int iConst = getConstexprNumber();
	cout << "const iConst value=> " << iConst << endl;
	int arr4[iConst];
	
	//Behave as normal function, this won't work with const experssion function as R-val
	int iInt = getConstexprNumber();
	cout << "iInt value=> " << iInt << endl;

	constexpr int sumConstr = AddValConstr(3,7); //work
	cout << "sumConstr  value=> " << sumConstr << endl;
	const int num3= 5, num4=4;

	constexpr int maxResult = maxNum(num3, num4);
	cout << "maxNum value=> " << maxResult << endl;

	/*
	Rval should always constexpr when used with constexpr L-val
	should contain only sigle line statement that should return statment
	error: the value of 'iInt' is not usable in a constant expression
	*/
	//constexpr int sumNormal = AddValConstr(iInt,7); //won't work

	/*
	output:
	Topic49, constexpr: constant expresssion
	constexpr i value=> 40
	const iConst value=> 40
	iInt value=> 40
	sumConstr  value=> 10
	maxNum value=> 5
	NOTE: literal types
	void, scaler types (int, float, char), references, etc..
	initialization of const value can be deffered until runtime 
	initialization of constexpr variable must be done at compiletime 
	all constexpr variable are const, but not other wat round 
	*/

	/*Topic50, std::initializer_list
	1. it is lightwieght proxy object that used to store an array of objects.
	2. header: <initializer_list>, create a instance of this class
	3. it is a class template, means need to specify the type of elements.
	4. initializer_list commonly used with container class, that can hold object of other class
	5. purpose: init user-defined objects, ilke array is initialized
	6. constructed automatically from braced list of elements
	auto, ranged based loop, constr, function
	7. not a true container but similar behavior
	8. provides access to its elements through iterator
	*/
	cout << "\nTopic50,initializer_list!" << endl;
	initializer_list<int> data2 = {10,20,30,40,50}; // with auto keyword, brace lilst elements inferred as init list
	//Bag bg;
	/*
	error: runtime error: segmentation fault at assert() / arr5[m_size++] = val; statement
	Bag bg{1,2,3,4};
	// bg.AddvalArr(5);
	// bg.AddvalArr(9);
	// bg.AddvalArr(1);
	// bg.AddvalArr(6);

	for(int i=0; i < bg.getSize(); ++i)
	{
		cout << "arr4 using class= " << bg[i] << endl;
	}*/
	
	PrintIinitList({1,2,3,4,5});
	cout << endl;
	
	//range based for loop iterators
	for(auto x: data2)
	{
		cout << x << "\t";
	}
	cout << endl;

	/*output:
	value in initializer_list=
	1       2       3       4       5
	
	10      20      30      40      50
	*/

	/*Topic51, Dynamic array std::vector, include <vector>
	1. can change its size at runtime as per need
	2. its classs template and can store any type of objects
	3. 

	*/
	cout << "\nTopic51, Vector in c++!" << endl;
	vector<int> data3 {1,2,3};
	cout << "Vector data: " << endl;
	for(auto x: data3)
	{
		cout << x << "\t";
	}
	cout << endl;
	data3.push_back(4);
	data3.push_back(5);
	data3.push_back(6);
	/*
	output:
	Vector data with newly pushed elements:
	1       2       3       4       5       6
	
	with vector.push_back() -> we can add as many elements we wat=nt
	this will get added at end of existing elements
	elements will be stored in contiguous memory locations
	elements can be accessed using subscript [] operator
	operator which is overloaded for vector class


	*/
	cout << "Vector data with newly pushed elements: " << endl;
	for(auto x: data3)
	{
		cout << x << "\t";
	}
	//range based for() loop internally use iterator of the container
	//iterator is ptr like object, used to access inside any container
	cout << endl;
	for(int i =0 ; i< 5 ;++i)
	{
		data3.push_back(i * 10);
	}
	
	//Access
	data3[1] = 100;
	/*for(int i =0; i< data3.size(); ++i)
	{
		cout << data3[i] << "\t";
	}*/
	//or
	cout << "Vector data with updated elements: " << endl;
	for(auto x: data3)
	{
		cout << x << "\t";
	}
	cout << endl;
	/*
	output:
	Vector data with updated elements: 
	1       100     3       4       5       6       0       10      20      30      40
	
	iterator class provides the overloads of many operators
	so it becomes easier to access elements of the containers
	use asterisk, it not only provide read but also write access
	auto it = data3.begin();
	cout << *it; //first elements of vector
	++it;
	--it;
	it  = it+5;	// jump to specific index
	*/

	//delete -> erase()
	//we can use iterator and make access to specific element you want to delete
	auto it = data3.begin();
	cout << "Vector data after deleting " << *it << " elements: " << endl;
	data3.erase(it);
	for(auto x: data3)
	{
		cout << x << "\t";
	}
	cout << endl;

	/*insert to specific positions
	auto it_pos = data3.begin() + 5; -> jump to 5th location
	vector,insert(postion, new_element)
	*/
	auto it_pos = data3.begin() + 5; //jump to 5th location of vector 
	data3.insert(it_pos, 200);
	cout << "Vector data after inserting 200 element at " << *it_pos << " : " << endl;
	for(auto x: data3)
	{
		cout << x << "\t";
	}
	cout << endl;
	
	/*
	output:
	Vector data:
	1       2       3
	Vector data with newly pushed elements:
	1       2       3       4       5       6
	Vector data with updated elements:
	1       100     3       4       5       6       0       10      20      30      40
	Vector data after deleting 1 elements:
	100     3       4       5       6       0       10      20      30      40
	Vector data after inserting 200 element at 200 :
	100     3       4       5       6       200     0       10      20      30      40
	*/

	/*
	Add one more function called FindAll, 
	that returns the starting indices of all the found substrings in a target string.
	Return the indices in a vector. Support case sensitive/insensitive search.
	enum class Case{SENSITIVE, INSENSITIVE};
	
	std::vector<int>
	FindAll(
	const std::string &target,              //Target string to be searched
	const std::string &search_string,       //The string to search for
	Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
	size_t offset = 0) {                    //Start the search from this offset
		//Implementation
	
		
		//Return indices of found strings,
		//else an empty vector
		
	}
	*/

	/*Topic52, Union in C++
	1. ability to store all members in same memory
	2. saves memory space
	3. size = higher data type it holds
	4. no way to know which type it holds and active member
	5. nested union has non-default constr, then it deletes default constr of union
	6. additionally it deletes desctructor also.
	7. from C++11, allowed to have member that contains user-defined constr & destructor
	8. cannot assign obj of user-defined types directly to union members (use new operator)
	9. user-defined types are not destroyed implicitly, have to manually invoke their destructor
	10. union cannot have a base clas, and not inherit from union
	11. cannot contain virtual functions
	12.  
	*/
	cout << "\nTopic52, Union in c++!" << endl;
	TestUnion tUni;
	cout << "sizeof(tUni)= " << sizeof(tUni) << endl;
	cout << "Before int:x set,Char from Union:tUni= " << tUni.ch << endl;
	tUni.x = 100;
	cout << "After int:x set, Char from Union:tUni= " << tUni.ch << endl;

	/*
	Error while creating instance of union which holds another instance of struct
	where struct has its own constr & destructr
	error 1: union member 'UDT::a' with non-trivial 'As::~As()'
  	712 |         As a;
	error 2: error: use of deleted function 'UDT::UDT()' #2606 
	note: 'UDT::UDT()' is implicitly deleted because the default definition would be ill-formed:
  	710 | union UDT

	//default constr of uninon become deleted,
	union -> need to write default constr & destructr manually

	output:
	0x7ffc041ad1a0
	sizeof(tUni)= 4
	Before int:x set,Char from Union:tUni= a
	After int:x set, Char from Union:tUni= d
	*/

	UDT udt;  //struct As has its own default constr & destructr
	
	/* not correct way to create instance of As struct/class
	cause obj created not assigned  which is not exist yet
	*/
	udt.a = As {};	
	//udt.strUnion = "Hello Union"s; //!crash here!, since mem init is not done
	new (&udt.strUnion) string {"Hello Union"};
	cout << "string variable from union= " << udt.strUnion << endl;
	
	new (&udt.a) As{};	//no call to destructor, cause no implicitly destroyed
	udt.a.~As();	//manually need destructor
	/*
	output:
		As()
	As& operator=()
	~As()
	string variable from unino= Hello Union
	As()
	~As()
	
	NOTE: C++17 provides variant library as type safe union
	*/
	
	/*Topic53, OOPS concepts
	1. system made up of objects
	2. obj. is instance of classes
	3. classes and obj are related and collaborate together to form system
	4. in OOP collaboration cn create using composition and inheritence
	5. this create a system allows to create solution for problem doamin.
	6. Composition: obj composed inside another object
	7. represent "has-a" relationship
	8. reuse bahavior
	9. e.g. car 'has-a' engine, and uses its implementation to move
	10. class Car 
	{
		Engine m_Engine;
		void accelerate()
		{
		m_engine.Intake();
		}
	}
	11. Inheritence: Classes inherits feature of other classes
	12. child can reuse and inherit parent class behavior
	13. 'is-a' relation
	14. Animal -> eat, speal, run (Behavior) -> inherit from Animal class 
	syntax:
	class <child_class_name> : <access_modifier> <base_class>
	class Dog : public Animal
	*/
	cout << "\nTopic53, OPPS Concept: Composition, Inheritence!" << endl;
	Dog dg;
	dg.Eat(); dg.Run(); dg.Speak();

	/*
	Here Dog is child or derived class and inherits the behavior of parent/base class: Animal
	so if Dog class does not have its own methods, it will still use method from its parent class
	like creating object/instance of Dog we can call methods from its base/parents Animal class

	if Dog derived class has its own methods, it will call its own instead from parent class.

	output:
	Topic53, OPPS Concept: Composition, Inheritence!
	Dog instance, without its own methods
	Eating Animal!
	Running Animal!
	Speaking Animal!

	Dog instance, with its own methods
	Dog eats meat!
	Running Animal!
	Dog barks loudly!
	*/

	/*Topic53-1, OPPS: Access Specifier
	1. Accessability
	class Base
	{
	private:
		methodA; -> Inaccessable outside class, and accessable from only same class
	public:
		methodB; -> Accessable to outside class as well
	protected:
		methodC; -> Accessable to only its child class/ hierarchy
	}

	2. Access modifier to child class
	class Child : public Base{} - same as base{}

	class Child : private Base{} -> all member => private method A,B,C and only B, C can be accessable to child class

	class Child : protected Base{} -> private methodA(){}, protected methodB(){}, methodC().

	3. if access modifier is not used, then default modifier of child will be used
	4. Object Creation:
	instance of child is created, constr execute from base -> child
	destructor execute reverse order child then base
	base data members will become part of child object
	e.g.
	class A{
	private:
	int x; float y;
	//methods
	}
	class B: public A
	{
	private:
	double z;
	//methods
	}
	data members from A -> x, y -> not accessable from Class B even though they are inherited
	*/
	
	/*manage Bank Account class example
	1. manage account
	2. customer - common operations
	3. bank -> administrative tasks
	4. Accout class -> represent Account
	5. common implementation for all account type
	6. Account -> 
	data members: name, acc_Number, balance, etc
	methods: withdraw(), Deposit(), GetBalance(), AcculateInterest(), GetInterestRate()
	7. Accountclass: Saving{}, Chekcing{} -> might have there own methods for certain operations
	8. 
	*/
	cout << "\nTopic53-1, Bank Accout Program, OOPS concepts!" << endl;
	Account Acc("Bob", 1000);
	try
	{
		cout << "Initial balance: " << Acc.getBalance() << endl;
		Acc.dispositAmount(150);
		cout << "Balance_1 (deposit+150): " << Acc.getBalance() << endl;
		Acc.withdrawAmount(800);
		cout << "Balance_2: (withdraw-800): " << Acc.getBalance() << endl;
		Acc.withdrawAmount(400);	//exception over withdrawn amount
		cout << "Balance_2: (withdraw-400): " << Acc.getBalance() << endl;
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	cout << "Size of class(Account)= " << sizeof(Account) << endl;
	/*
	output:
	Initial balance: 1000
	Balance_1 (deposit+150): 1150
	Balance_2: (withdraw-800): 350
	Error: Insufficient balance! Can not have negative balance!
	Size of class(Account)= 48 (with virtual keyword)
	Size of class(Account)= 40 (without virtual keyword)
	*/

	//Saving Account class -> Saving.cpp & Saving.h
	/*
	Add the Checking class to the hierarchy. 
	It does not have any interest rate, therefore, 
	it will not implement the corresponding member functions.
	The only difference is that the account mandates the balance should not fall below 50. 
	So, you'll have to re-implement the Withdraw function accordingly. 

	You should proceed only after implementing the entire Account hierarchy.
	*/
	cout << "\nTopic53-2, Bank Accout Program, OOPS concepts, Checking{} derived class:minBalance!" << endl;
	Checking Ch("Robin", 500, 50);	//check NOTE in Checking.h 50: Minimum balance amount -> ((m_balance - amount) > m_MinimumBalance)
	Ch.withdrawAmount(480);
	cout << "Bank balance after Checking{}: " << Ch.getBalance() << endl;

	/*
	output:
	Topic53-2, Bank Accout Program, OOPS concepts, Checking{} derived class:minBalance!

	Checking():Invalid Amount!
	Bank balance after Checking{}: 500!
	
	---> if we use throw xx --->
	terminate called after throwing an instance of 'std::runtime_error'
	what():  Insufficient balance! Enter valid Amount!
	*/

	/*Topic53-3, virtual keyword, Transaction class*/
	cout << "\nTopic53-3, virtual keyword, Transaction method on Checking{}" << endl;
	Checking ChTransact("Boby", 1000, 50);
	Transaction(&ChTransact);

	/*
	output:
	!Transaction started!
	Initial balance: 1000
	Interest Rate: 0
	Final Balance: 980
	*/

	//perform Transaction on Saving
	cout << "\nTopic53-4, virtual keyword, Transaction method on Saving{}" << endl;
	Saving SavAcc("Sabby", 100, 0.05f);	//0.05f -> interest rate
	Transaction(&SavAcc);	//!Compiler is not calling getInterestRate() method from saving : outut=0
	
	/*
	!Transaction started!
	Initial balance: 100
	Interest Rate: 0
	Final Balance: 80
	*/
		
	/*Topic54: Polymorphism, 
	1. Different form of functions are implemented
	2. call revoke at compile/runtime
	3. compile time polymorphism / binding: function /operator overloading, templates
	compiler has enough info to decide which function to be invoke
	4. runtime polymosrphism / dynamic binding:  which function should be invoked is not known.
	5. this is implemented using virtual mechanism
	6. compiler will insert some code that decide which code has to be invoked when member functions prefix with virtual keyword
	8. such function called as : polymorohic function
	9. invoke through a base class ptr/reference.

	10. Vtable & VPtr: Account class -> reimplemented methods in child class (Saving) -> prefix with virtual key word
	methods -> accumulateInterest(), getInterest(), withdrawAmount() : Account class
	11. when compiler compiles this class -> generate array of function ptr -> called Virtual table

	12. Vtable : addr of virtual function (non-virtual function do not appear in Vtable)
	13. starting ptr of Vtable -> stored in special member variable -> virtual pointer
	14. this Vptr -> auto. added by compiler as member of class, points to Vtable of corresponding class.
	15. Saving class -> derived class from Account -> methods :accumulateInterest(), getInterest() -> override
	compiler generrate Vtable for Saving class. -> include addr of virtual function in VTable 
	16. No withdrawAmount() function is inherited in Saving class, but normal rules of inheritance will be applied 
	17. it will be present in Saving class Vtable.
	18. if we create a instane of Saving class, virtual ptr si inherited, init with addr of VTable of Saving class
	19. this init take place in constr of Saving class
	20. compiler add this init code in all constr of class in hierarchy
	21. e,g,
	pAccount->Deposit(100); -> non-virtual function , direct invoke of Deposit()
	pAccount-> accumulateInterest() -> virtual function, compiler has to generate extra code:
	a) get the addr of obj 
	b) get vPtr
	c) find the position of function
	d) get addr of the function
	e)  invoke the function
	pAccount->withdrawAmount() -> as steps are taken above (a)~(e), offset (+4) is added to grab the addr of this function
	pAccount->getInterestRate() -> as steps are taken above (a)~(e), offset (+8) is added to grab the addr of this function
	NOTE: this all  information can be seen in Disassembly code form VS Code / in general tooling environment
	this 4 byte will get added to subseqent function as per list of function sequense in Vtable 

	NOTE2: bcause of virtual keyword, size of class get incresed by 4byte (32bit platform) and/ 8 byte of (64byte platform)
	*/

	/*Topic55: 
	final: specifer that is for class & method to restrict derived & override
	override: keyword for method to override in derived class
	
	*/
	//create object of derived classs , assign to ref of base class
	cout << "\nTopic55, final specifier & override keyword!" << endl;
	
	Text tx;
	Document &doc = tx;
	doc.serialize(2.5f);

	/*
	output:
	Topic55, final specifier & override keyword!
	using without override ketword in derived/child class
	Document::serialize(float version)!

	using override ketword in derived/child class
	Text::serialize(int version)!
	*/
	
	/* Topic56: Object Slicing:
	1. situation where compiler will removes some part of an object
	2. occurs where derived class object is assigned to concrete base class object
	3. pass derived class object to function which accept base class object by value
	4. since derived class may content more attributes, the object may required more memory
	5. so, size of derived class bject is more than its base class object
	6. while assigning it to object to base object, some part of memory gets overwritten
	7. lead to memroy corruption
	8. to prevent this, compiler slice this derived class object, effectively removing memory that contains its attributes.
	9. derived class object copied to base class object
	10. e.g. Account a -> name,accNo, bal -> 40Byte
	Savings s -> name,accNo, bal, rate -> 44Byte
	if we do -> a=s; -> when s obj is copying at mem-area of a obj, it will overwrite the part of memoory
	this leads to undefined behavior in program
	to prevent problem, compiler removes some part of savings obj
	size of s can match with a
	This is known as Object Slicing
	-> ensure that if obj is created from base and try to access method from derived class
	that base class obj should be -> ptr / reference.
	
	*/
	cout << "\nTopic56, Object Slicing!" << endl;
	Checking chObj("Sam", 500, 50);
	Account *pAcc = &chObj;	//upcast assign base ptrObj to derived reference


	/*want to get back derived obj from base ptr -> not possible
	error: invalid conversion from 'Account*' to 'Checking*' [-fpermissive]
	Not all account can be Checking accounts
	
	Checking *pCheck = pAcc;
	work until unless manual static_cast<Checking*> is mentioned with pAcc
	*/
	Checking *pCheck = static_cast<Checking*>(pAcc);	//down cast (specify manually)
	Transaction(&chObj);
	
	/*instead of Checking, create obj Saving an pass it to Transaction?*/
	Saving svObj("Sam", 500, 0.05f);	//interestRate= 0.05f
	//Transaction(&svObj);	//undefined behaviour
	
	/*
	output: undefined behaviour
	!Transaction started!
	Initial balance: 500
	Minimum Balanceof Checking: 0
	Interest Rate: 0
	Final Balance: 430
	Solution: we need to check in Transaction class, where pAccount is really pointing to pChecking or not?
	*/
	
	/*
	Topic57: typeid operator (RTTI concept)
	1. it returns the information of typeid as an object of typeinfo class
	2. include header <typeinfo>
	3. type_info : contain certain methods/function -> equlity operator, name(): human readable name of type
	4. RTTI: Run-Time Type Information (RTTI) in C++ is a mechanism that 
	allows you to determine an object’s data type during program execution
	5. 
	*/
	cout << "\nTopic57, Typeid (RTTI concept)! " << endl;
	int m_iTypeInt {};
	float m_fTypeFloat {};
	const type_info &ti = typeid(m_iTypeInt);
	cout << "type name of var-> m_iTypeInt= " << ti.name() << endl;
	const type_info &tf = typeid(m_fTypeFloat);
	cout << "type name of var-> m_fTypeFloat= " << tf.name() << endl;
	
	const type_info &tSv = typeid(svObj);
	cout << "type name of Saving obj-> svObj= " << tSv.name() << endl;
	const type_info &tAcc = typeid(pAcc);	//use only addr, pAcc
	cout << "type name of Account obj-> pAcc= " << tAcc.name() << endl;
	//type of Obj this pAcc ptr pointing at
	const type_info &tAccPtr = typeid(*pAcc);	//use *pAcc, polymorphic type, gether info at runtime
	
	if (tAccPtr == typeid(Checking))
	{
		cout << "Account ptr *pAcc poiting to Saving object." << endl;
	}
	else
	{
		cout << "Account ptr *pAcc NOT poiting to Saving object." << endl;
	}
	cout << "type name of Account ptr poiting to obj -> *pAcc= " << tAccPtr.name() << endl;

	/*
	output:	
	Topic57, Typeid (RTTI concept)!
	type name of var-> m_iTypeInt= i
	type name of var-> m_fTypeFloat= f
	type name of Saving obj-> svObj= 6Saving
	type name of Account obj-> pAcc= P7Account
	Account ptr *pAcc poiting to Saving object.
	type name of Account ptr poiting to obj -> *pAcc= 8Checking
	*/
	//use this typeid() in Transaction class 
	Checking chkObj("Sam", 700, 40);
	Transaction(&chkObj);

	/*
	output:
	!Transaction started!
	Initial balance: 700
	Minimum Balanceof Checking: 40
	Interest Rate: 0
	Final Balance: 630
	*/
	//use it with Saving class
	Saving savObj("Sam", 700, 0.05f);	//interestRate= 0.05f
	Transaction(&savObj);	//won't print the minimumBalance, cause of static_cast<> inside Transaction class

	/*
	output:
	!Transaction started!
	Initial balance: 700
	Interest Rate: 0
	Final Balance: 630
	*/

	/* Topic58: Typeid, over dyanamic_cast<> 
	1. this will check whether type cast can be perfomed or not
	2. if perfomed, it returns type casted pointer, otherwise nullptr
	3. this does the same opeation as above with same output
	*/
	//after replacing static_cast<> to dunami_cast<> in Transaction class
	Saving dynamicSavObj("Dynamic", 900, 0.05f);	//interestRate= 0.05f
	Transaction(&dynamicSavObj);
	Checking dyanamicChkObj("Sam", 900, 70);
	Transaction(&dyanamicChkObj);

	/*
	output:
	!Transaction started!
	Initial balance: 900
	Minimum Balanceof Checking: 70
	Interest Rate: 0
	Final Balance: 830
	*/
	
	/* Topic58-1,dynamic_cast<> can also work with reference, try-catch
	1. referece & -> cannot be a nullptr, 
	2. it will throw exception, bad type_cast
	3. use try{} catch {}
	4. try-catch: 
	5. compiler has to add more information to polymorphic classes
	6. during compile time, compiler create a type info of object as -> type_info
	7. stored along with class in vTable
	8. at runtime, when we use typeid ad dynamic class, these operator query that info from vTable
	9. RTTI impose overhead on the programs (avoided) 
	*/
	Checking tryCatchChkObj("TrysomeCatchChecking", 1000, 90);
	try
	{
		/*
		1. exception throw in runtime
		2. pass reference, work fine and dynamic cast with pAccount object 
		3. it won't work with Saving class object
		*/
		Transaction(tryCatchChkObj);	
	}
	catch(exception &ex)
	{
		/*
		1. cath() -> always accept an exception type
		2. exception is base class of all std exception in std library
		3. what()-> return the message about exception
		*/
		cout << "\nException= " << ex.what() << endl;
	}
	/*
	output:
	!Transaction started!
	Initial balance: 1000
	Minimum Balanceof Checking: 90
	Interest Rate: 0
	Final Balance: 930
	*/
	//Checking and Saving are not compatible, and have no relation
	Saving tryCatchSavObj("TrysomeCatchSaving", 1100, 110);
	try
	{
		/*
		1. exception throw in runtime
		2. pass reference, work fine and dynamic cast with pAccount object 
		3. it won't work with Saving class object
		*/
		Transaction(tryCatchSavObj);	
	}
	catch(exception &ex)
	{
		cout << "Exception= " << ex.what() << endl;
	}

	/*
	ouput:
	!Transaction started!
	Initial balance: 1100
	Exception= std::bad_cast
	*/

	/*Topic 59, Abstract Class, pure virtal functions:
	1. with ony virtual function in base DocumentAbst {} ->
	virtual DocumentAbst::serializeAbst(float version)
	2. with base class DocumentAbst{} with pure virtual function -> 
	output: main.cpp:3106:17: error: cannot declare variable 'xmlabst' to be of abstract type 'XMLAbst' 
	*/
	cout << "\nTopic59, Abstract Class, pure virtal functions! " << endl;
	
	XMLAbst xmlabst;
	writeDoc(&xmlabst);

	/*
	   Topic60: Multiple Inheritance (Diamond problem)
	1. c++ allows inheritance from more than one class simultaneously
	2. known as multiple Inheritance
	3. allows class to reuse/override bahaviours from multiple classes
	4. this can lead to diamond Inheritance (problem)
	5. classes inherits from common classes, forms a diamond shape
	6. e.g.
	base class stream <- ostream <-istream 
	R/W through one class iostream -> istream, ostream
	object of iostream contains instances of its base classes -> stream-istream, stream-ostream (stream x2)
	object of iostream contains instances of (stream x2) -> leads problem

	-> Stream() invoked twice
	-> this could cause undefined results meaning -> when Stream() constr opens the file
	it will open twice a time. check scenario of handling data 
	*/
	cout << "\nTopic60, Multiple Inheritance (Diamond problem)! " << endl;
	ioStream ioStreamObj("out.txt");

	string data4;// = "Ajay";
	/*
	output1:
	constr of Stream{} base class called twice a time -> Stream::Stream(const string &filename)

	Topic60, Multiple Inheritance (Diamond problem)!
	Stream::Stream(const string &filename)
	oStream::oStream(ostream &o, const string &filename):out(o), Stream(filename)
	Stream::Stream(const string &filename)
	iStream::iStream(istream &i, string &filename):in(i), Stream(filename)
	ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename)
	*/

	/*
	for -> ioStreamObj >> data4; 
	error: not accepting const to non-const data4, cause 
	under ioStram {} -> iStream was private by deafult while inherit
	-> class ioStream : public oStream,  iStream
	change -> public 
	-> class ioStream : public oStream, public iStream
	*/
	ioStreamObj >> data4;	//provide input string once run the program: "ajay"
	ioStreamObj << data4;

	/*
	output2:
	Topic60, Multiple Inheritance (Diamond problem)!
	Stream::Stream(const string &filename)
	oStream::oStream(ostream &o, const string &filename):out(o), Stream(filename)
	Stream::Stream(const string &filename)
	iStream::iStream(istream &i, string &filename):in(i), Stream(filename)
	ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename)
	ajay
	ajay
	*/

	/*
	error: request for member 'getFilename' is ambiguous
	ioStreamObj.getFilename() -> inherited twice cause of, Stream() class constr  invoked twice
	since getFilename() also get invoked twice

	resolution->
	to resolve this, there only one object of Stram in iStream
	iStream{} & oStream{} inhert virtually from Stream{} base class
	this ensure that there only one Stream object in iStream{} class

	error: no matching function for call to 'Stream::Stream()'
	resolution: invoke parameterized constr of Stream in ioStream() constr 
	-> ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename), Stream(filename)
	*/

	ioStreamObj << ioStreamObj.getFilename() << endl;		

	/*
	Stream() constr invoke only once
	meaning -> only one instance of Stream{} in iStream object
	
	output3:
	Stream::Stream(const string &filename)
	oStream::oStream(ostream &o, const string &filename):out(o), Stream(filename)
	iStream::iStream(istream &i, string &filename):in(i), Stream(filename)
	ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename)
	diamond
	diamondout.txt
	*/

	/*Topic61: exception handling part-1*/
	cout << "\nTopic61, Topic61-1: exception handling part-1! " << endl;
	/*
	numeric_limits -> gives information about arithmatic types
	max() -> to get very large number to pass that process records
	to deliberatly check malloca can not handle very large number here,
	and crashes the program
	*/
	cout << "std::numeric_limits<int>::max()= " << std::numeric_limits<int>::max() << endl; 
	//processRecords(std::numeric_limits<int>::max());	//here, function does not know anything, and ignoring exception checks

	/*
	output:
	std::numeric_limits<int>::max()= 2147483647
	->> stuck compiler
	or
	std::numeric_limits<int>::max()= 2147483647
	terminate called after throwing an instance of 'std::runtime_error'
	what():  failed to allocate a very large memory
	*/

	/*
	Exception handling:
	1. Mechanism to handles the error in program that occurs at runtime
	2. these errors called as exceptions
	3. exist outside the normal functioning of program
	4. requires immediate handling by program
	5. if not handled, program crashes
	6. cannot be ignored, unline in c progrm

	Mechanism:
	1. try{}: creates a scope/block & exeption causing code appears here
	2. can contain other try-catch statements
	3. throw: throws an exceptions from try block
	4. exception is object i.e. constructed in throw statement
	5. it never return wherever it throws
	6. this will immediately jump to cathc{} handler
	7. catch: handler that catches exception object
	8. should appear just after try block
	9. multiple catch block can exist
	*/

	try
	{
		processRecords(10);//std::numeric_limits<int>::max());
	}
	/*catch (exception &ex)
	{
		cout << "catch exception: " << ex.what() << endl;
	}*/
	
	//If below separate catch blocks are used, then program runs as expected.
	catch (runtime_error & ex)
	{
		cout << "catch block1: " << ex.what() << endl;
	}
	catch (out_of_range &ex)
	{
		cout << "catch block2: " << ex.what() << endl;
	}
	catch (bad_alloc &ex)
	{
		cout << "catch block3: " << ex.what() << endl;
	}

	/*
	output:
	Topic61, Topic61-1: exception handling part-1!
    std::numeric_limits<int>::max()= 2147483647
    testStk():constr. Acquire resource !
    testHeapPtr():constr. Acquire resource ! 61-5: !destructor won't get called cause of early exception! 
    testHeapPtr():constr. Acquire resource !
    ~testHeapPtr():destructor, Release resource! -> !destructor gets called cause use of smart_ptr (auto deallocation of memory)! 
    ~testStk():destructor, Release resource!
    catch exception: Count should be greater than 10
	
	*/

	/* Topic61: exception handling part-2, Nested Exceptions
		see processRecords() function for more details
	*/

	/* Topic61: exception handling part-3, Constr & Destructr
	*/
	try
	{
		/*
		once the object is created, memory is allocated
		and constr will onvoke
		but destructor won't be invoked
		*/
		TestExp  tE;	
	}
	catch(runtime_error &ex){
		cout << "catch part-3: " << ex.what() << endl;
	}
	/*
	output:
	memory allocated to AExp() has not been deleted
	since destructor of ~BExp() invoked cause this is concrete object (at runtime expection)
	but the memory allocated through NEW won't be deleted automatically
	need to delete manually
	-> can be solve using concepts RAIi-> smart_ptr
	part-3-1, memory leaks

	BExp():constr!
	TestExp():constr!
	AExp():constr!
	~BExp():destrctor!
	catch part-3: Failed to initialize
	
	output2:
	RAIi-> smart_ptr solve the problem of memory leak
	BExp():constr!
	TestExp():constr!
	AExp():constr!
	~BExp():destrctor!
	~AExp():Destructor!
	catch part-3: Failed to initialize
	*/
	
	/*Topic61, Expection Handling, No Exception
	1. Applied to function (declaration & definitions)
	2. indicates funciton that does not throw any exception
	3. compiler can optimize the function code: no need to generate stackunwinding code
	4. An exception immediately terminates the program: stack may/not be unwinded
	5. Not all function should use noexcept specifier: fun calling another function, fuction: exceptional neutral
	6.  
	
	//cout<< boolalpha << noexcept(TestNoExcept(5)) << endl;	//true/false
	try
	{
		SumNoExcept(3,5);
	}
	catch(int x)
	{
		cout << "SumNoExcept: 	" << x << endl;
	}
	NOTE: this need separate project to run and check output at all stages
	*/

	/* Topic62: Raw String literals (C++11)
	
	*/
	cout << "\nTopic62, Raw String Literals! " << endl;
	string fileName {"C:\temp\newfile.txt"};
	/*
	output:
	C:    emp
	ewfile.txt
	\t and \n from string -> consider as escape sequense
	to avoid this and skip escape sequenses, need to use extra \ with delimeter
	*/
	cout << "fileName: " << fileName << endl;
	string fileName1 {"C:\\temp\\newfile1.txt"};
	cout << "valid fileName1: " << fileName1 << endl;
	/* output:valid fileName1: C:\temp\newfile1.txt
	this is trdious for long string like html, and xmls
	use raw string literals -> with regx as well

	*/
	string fileName2 {R"(C:\temp\newfile2.txt)"};
	cout << "with str literals, fileName2: " << fileName2 << endl;

	/*
	output:
	with str literals, fileName2: C:\temp\newfile2.txt
	use delimeters to allow use of )", char in string
	*/
	string message{R"MSG(C++ intoduced filesytem "(API in C++17)")MSG"};
	cout << "with delimeters, message: " << message << endl;

	/*
	output: with delimeters, message: C++ intoduced filesytem "(API in C++17)"
	*/

	/* Topic63-1, File handling and operations*/
	cout << "\nTopic63, File Operations and Error Handling! " << endl;
	writeFile();
	readFile();
	/*
	output:
	Topic63, File Operations and Error Handling!
	File is open!
	I/O operation is successful!
	Hello World!:10
	*/
	cout << "\nTopic63-2, File Operations-Copy Utility! " << endl;
	//add -lstdc++fs in task.json file to build project with experiemental:filesystem
	int retCpUitility = copyUtility();	
	cout << "retCpUitility: " << retCpUitility << endl;
	/*
	output:
	if filename/path is wrong -->
	source(current_path()): "G:\\CPP\\2024\\VSCode\\UdemyCpp"
	dest(current_path()): "G:\\CPP\\2024\\VSCode\\UdemyCpp\\oopsConcept.txt"
	dest: oopsConcept.txt file found!
	retCpUitility: 0
	*/

	/*
	Topic63-3,4,5,
    io stream has internally a pointer which points to location of file while R/W.
    for ifstream -> ptr -> get ptr
    for ofstream -> ptr -> put ptr
	if we need to read a file from specific location
	we have to change position of get ptr
	to know correct position of get-ptr tellg()
	to know correct position of put-ptr tellp()
	please check above writeFile()/readFile() methods
	*/

	//Topic63-6 : IO operation from file
	cout << "\nTopic63-6, IO operation from file! " << endl;
	usingFstream();

	/*
	output1:
	1. since file wasa not exist, it will create new file here -->

	fileStream.txt doesn't exist
	content from fileStream.txt: 
	
	2. since file is exist, try to read the content of file
	but unable ro read since get ptr is at EOF, need to shift ptr to SOF
	using seekg(0);
	output2:
	content from fileStream.txt:
	
	output3:
	content from fileStream.txt: Hello world.	
	*/

	/* Topic63-8: Binary-IO operation from file handler*/
	cout << "\nTopic63-7, bin-txt operation from file! " << endl;
	usingBinMode();

	/*
	binary file will be created in this current directory 
	value: (75BCD15)H (displayed in reverse order in file)
	dec value: (123456798)10

	data file with value: 123456798 
	
	output:
	Topic63-7, bin-txt operation from file!
	num from binary file: 123456789
	*/

	/*Topic63-8, Binary-IO records operation from file handler!*/
	cout << "Topic63-8, Binary-IO operation from file handler!" << endl;
	Record r;
	r.id = 1001;
	strcpy_s(r.name, 10, "Records");
	writeBinRecords(&r);

	Record r2 = getBinRecords();
	cout << "binRecord R2= " << r2.id << ':' << r2.name << endl;

	/*
	NOTE: to write multiple records, have to write totol number of records in file
	then, count how many records present in file, then read the records
	cause it does not have EOF character, so important to know count of records while writing and reading. 
	output:
	binRecord R2= 1001:Records
	*/

	/* Topic64: Templates in c++(11)*/
	cout << "Topic64: Templates and non-typr templates in c++(11)" << endl;
	allTemplateMethods();


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