#include "../header/partialSpecialization.hpp"


/*template <typename T, int columns>
inline void partialSpecialization<T, columns>::Print()
{
    std::cout << "columns: " << column << std::endl;    //Topic69: partial
    std::cout << "{" <<  << "}" << std::endl;
}
template <typename T, int columns>
T *partialSpecialization<T, columns>::getPartialData()
{
    return m_par;
}

*/

void all_partial_specialization_methods()
{
    /*
        In explicit specialization, all the template parameters are specialized
        In partial specialization, only some of the template parameters are specialized
        -> add non-type template parameter (int columns) in,

        template<typename T, int columns>
        class explicitSpecialization
        columns contains values used by the Print() method
        to find out what is available width to print the data
        values become const and cannot modify it.
    */
    std::cout << "\nTopic69, partial vs explicit specialization" << std::endl;
	int partialData = 800;
	partialSpecialization<int, 40> partial_Special{&partialData};
    partial_Special.Print();

	/*
		output:
		Topic69, partial vs explicit specialization
		columns: 40
		{800}

        there are 40 columns available, Assuming class would used in device where 80 column present (most # of column available on devices).
        use this column and format Print() in more efficiant way.

        condition: when columns == 80, then decide print data in different way
        we can do it in runtime by adding conditional statement in Print(), and chk value of columns
        BUT, there is more efficiant way, we can partially specialize the partialSpecialization class for the value

        So, in partialSpecialization specialize some of valies of template parameters
        first param: typename, second param: non-type
        NOTE: check header file for more implementation details
	*/
    std::cout << "\nTopic69-2, partial specialization" << std::endl;
    int partialData1 = 900;
	partialSpecialization<int, 80> partial_80Special{&partialData1};
    partial_80Special.Print();

    /*
        Compiler choose partial specialization
        Topic69, partial vs explicit specialization
        columns: 40
        {800}
        Topic69-2, partial specialization
        Using 80 columns:
        {900}
    */
    std::cout << "\nTopic69-3, partial specialization with Smart Pointer" << std::endl;
    SmartPointer<int> s_ptr{new int(3)};
    std::cout << "*s_ptr: " << *s_ptr << std::endl; //output: *s_ptr: 3

    /*
        smart pointer with dynamic array
        e.g.
        SmartPointer<int> s_ptr{new int[5]};

        need change simple integer pointer to integer array
        smartPointer holds a ptr to an array and class won't give correct semantics
        and behaviour for this smart ptr when it internally points to integer array.

        firstly, we cannot access the elements of array using this smart ptr
        implementation of destructor as above is not correct and need modifications
        should use delete[] for arrays
        partially specialized SmartPointer class for array type
        
        need to write new class SmartPointer with array type
        NOTE: chk header

        T * operator -> , T & operator *()  operators won't make sense to use
        replaced with overloaded subscript operator
    
        instance of class which hold an array
        then specify arg as an array with class: SmartPointer<int[]>
        meaning: SmartPointer is instantiated for an array type

        Compiler will choose partial specialization
    */
    std::cout << "\nTopic69-4, partial specialization, Smart Pointer with dynamic array" << std::endl;
    SmartPointer<int[]> s_arrayPtr{new int[5]};
    // std::cout << "*s_arrayPtr :" << *s_arrayPtr << std::endl;    //*s_arrayPtr : won't work here, use subscript operator
    s_arrayPtr[0] = 5;  //use subscript operator with array
    std::cout << "s_arrayPtr[0] :" << s_arrayPtr[0] << std::endl;

    /*
        output:
        Topic69-3, partial specialization with Smart Pointer
        *s_ptr: 3
        Topic69-4, partial specialization, Smart Pointer with dynamic array
        s_arrayPtr[0] :5

        NOTE:
        Object: The actual entity created from a class, existing in memory.
        Instance: The specific realization of a class, essentially the same as an object 
        but emphasizing the creation process.
    */
}