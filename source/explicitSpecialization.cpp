#include "../header/explicitSpecialization.hpp"


template <typename T>
inline void explicitSpecialization<T>::Print()
{
    std::cout << "{" << *m_pData << "}" << std::endl;
}

template <typename T>
inline T *explicitSpecialization<T>::getData()
{
    return m_pData;
}

/*template <typename T>
explicitSpecialization<T>::~explicitSpecialization()
{
    delete m_pData;
}*/

/* 
    method to create     


    template <typename T>
    inline void explicitSpecialization<T>::all_explicitSpecialization_methods()
    {
    }
*/

void all_explicitSpecialization_methods()
{
    /* //68-2
    int i_Data = 5;
    float f_Data = 8.2f;
    explicitSpecialization<int> i_eSpecial(&i_Data);    // class template works with int type
    // explicitSpecialization<int> i_eSpecial(new int(i_Data));
    i_eSpecial.Print();
    explicitSpecialization<float> f_eSpecial(&f_Data);  // class template works with float type
    // explicitSpecialization<float> f_eSpecial(new float(f_Data));
    f_eSpecial.Print();
    /*
        output1:
        Topic68: Explicit Specialization Class Templates in c++
        {5}
        {8.2}
    */
    /*  //68-2
    //const char * - for string literals
    char *s_Str{"String Specialization"};   //warn: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]gcc
    /* 
        explicitSpecialization<char*> s_eSpecial(s_Str);
        no matching function for call to 'explicitSpecialization<char*>::explicitSpecialization(char*&)'
        no known conversion for argument 1 from 'char*' to 'explicitSpecialization<char*>&&'
        when we use char* as template parameter, then type of T -> T*
        and declaration become T** -> T *m_pData;
        here, only ptr char* is passed with s_Str -> need to pass with char** -> (&s_Str)
    */
    /* //68-2
    explicitSpecialization<char*> s_eSpecial(&s_Str);
    s_eSpecial.Print();
    /*
        Topic68: Explicit Specialization Class Templates in c++
        {5}
        {8.2}
        {String Specialization}
    */
    /*
        error: cannot convert 'char**' to 'char*' in initialization

        we use char* as template parameter
        so, T -> T*
        and getData return T ** as per definition
        this becomes counter intuitive, when used with explicitSpecialization<char*>

        explicitSpecialization<char> s_eSpecial(s_Str); -> this will print only first char
        {S}
        m_pData() -> ptr to char/str, while dereferencing with *, it will print only frst char
        so explicitSpecialization<char*> /explicitSpecialization<char> does not give correct results

    */
    /* //68-2
    char **s_eGetdata = s_eSpecial.getData();
    std::cout << "**s_eGetdata for char*: " << **s_eGetdata << std::endl;   
    char *s_eData = s_eSpecial.getData();
    std::cout << "*s_eData for char*: " << *s_eData << std::endl;   
    /*
        output:
        **s_eGetdata for char*: S
        this is wrong result.
        need to create explicite specialization for string type  
        
    */
    //NOTE: "Need to comment out previous int and float section due to char*
    char *s_specialStr{"String explicit Specialization"};   // warning: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
    explicitSpecialization<char*> s_explicitSpecial(s_specialStr);
    // s_explicitSpecial.printExplicitSpecial();
    s_explicitSpecial.Print();
    // char *pData = s_explicitSpecial.getExplicitData();
    char *pData = s_explicitSpecial.getData();

    /*
        output: 68-2
        Topic68: Explicit Specialization Class Templates in c++
        {String explicit Specialization}    
    */
}

// Explicit instantiation
// template class explicitSpecialization<int>;
// template class explicitSpecialization<float>;