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
    std::cout << "\n 69, partial vs explicit specialization for vector" << std::endl;
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
}