#include "../header/perfect_forwarding.hpp"



using namespace std;

/*
perfect_forwarding::perfect_forwarding(const std::string &name, const Integer_forward &id) : m_forName {name}, m_Id {id}
{
    cout << "perfect_forwarding::perfect_forwarding(const std::string &name, const Integer_forward &id)" << endl;
}

perfect_forwarding::perfect_forwarding(std::string &&name, Integer_forward &&id): m_forName {name}, m_Id {move(id)} //with function template for constr, std::move is not needed
{
    cout << "perfect_forwarding::perfect_forwarding(std::string &&name, Integer_forward &&id)" << endl;
}
/*
1. even though we are passing the temporary values
2. copy constr of m_forName {name}, m_Id {id} these objects are also invoke

	Topic64, Perfect Forwarding!
	Integer_forward::Integer_forward(int value) //param constr, cause 105 value is passed thorugh object from main()
	Integer_forward::Integer_forward(const Integer_forward &obj)	//then ID is copied in m_pId using copy constr
	//same thing will happen for string: "cpp_check" -> m_forName using constr
	Integer_forward::~Integer_forward()
	Integer_forward::~Integer_forward() // this will execite after end of main

3. if we want to invoke move constr for these objects
4. we need another constr that accepts rvalue references

	output2: after adding move constr
	Topic65, Perfect Forwarding!
	Integer_forward::Integer_forward(int value) //still for copy constr is invoked from Integer_forward class
	Integer_forward::Integer_forward(const Integer_forward &obj)
	perfect_forwarding::perfect_forwarding(std::string &&name, Integer_forward &&id)
	Integer_forward::~Integer_forward()
	Integer_forward::~Integer_forward() // this will execite after end of main

5. here, copy constr for m_Id {id} from Integer_forward class is invoked.
6. cause, even if you declared it as ravlue ref -> Integer_forward &&id, it has a name m_Id {id} -> id
7. compiler will match the name here with copy constr
8. id variable is not a temporary, which become lvalue i.e. compiler will invoked copy constr

9. need to use move function inside move constr with id
    m_Id std::move(id)

    Topic65, Perfect Forwarding!
    case1, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(Integer_forward &&obj)
    perfect_forwarding::perfect_forwarding(std::string &&name, Integer_forward &&id)
    Integer_forward::~Integer_forward()
	Integer_forward::~Integer_forward() // this will execite after end of main

    string case2 {"cpp_check"};
	perfect_forwarding pFor2{case2, 100};	//temp values
    output:
    case2, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(const Integer_forward &obj)
    perfect_forwarding::perfect_forwarding(const std::string &name, const Integer_forward &id)
    Integer_forward::~Integer_forward()

10. here 100 is temp, and id object is init by copying value to m_Id {id}
    so, copy constr from Integer_forward class

11. output4, case4 with std::forward function with objects in constr
    case4, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(Integer_forward &&obj)
    perfect_forwarding(T1 &&name,T2 &&id)
    Integer_forward::~Integer_forward()
    
    Integer_forward::~Integer_forward() //after end of main()

    case5, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(const Integer_forward &obj)    //copy constr cause of intVal5
    perfect_forwarding(T1 &&name,T2 &&id)
    Integer_forward::~Integer_forward()
    
    Integer_forward::~Integer_forward() //after end of main()

12. perfect forwarding (using std::forward) -> information of type is preserved, when it is forwarded to next function call
    we can check by creating function that will create perfect_forwarding object for us.   
    -> check .hpp file with case6
    case6, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(const Integer_forward &obj) // copy constr since it invoked with name with (l-value) for b not with r-value ref
    perfect_forwarding(T1 &&name,T2 &&id)
    Integer_forward::~Integer_forward()
    
    Integer_forward::~Integer_forward() //after end of main()

13. to ensure that type information is preserved, will use std::forward with objects a & b
    //case 6-1, with std::forward
    case6, Perfect Forwarding!
    Integer_forward::Integer_forward(int value)
    Integer_forward::Integer_forward(Integer_forward &&obj)
    perfect_forwarding(T1 &&name,T2 &&id)
    Integer_forward::~Integer_forward()

    take advantage of perfect forwarding when function template is invoking some other function template internally.
    and want to preserved information about the types.
*/