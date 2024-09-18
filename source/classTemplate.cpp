#include <iostream>
#include "../header/classTemplate.hpp"

//using namespace std; //to avoid to prevent namespace pollution

void classTemplate::all_classTemplate_methods()
{
    /*//67-1 without template class example
    st.Push(3);
    st.Push(2);
    st.Push(4); 
    st.Push(7);

    while (!st.isEmpty())
    {
        std::cout << st.Top() << ' ';
        st.Pop();
    }
    /*  output1:
        Topic67: Class Templates in c++
        constr, Stack::Stack()
        constr, classTemplate::classTemplate()
        7 4 2 3

        !End of Main()!
        distructor, classTemplate::~classTemplate()
        distructor, Stack::~Stack()
    */
    stFloat.Push(3);
    stFloat.Push(2);
    stFloat.Push(4); 
    stFloat.Push(7);
    auto stFloatCpy(stFloat);

    while (!stFloatCpy.isEmpty())
    {
        std::cout << stFloatCpy.Top() << ' ';
        stFloatCpy.Pop();
    }
    /*
        67-2, output:     
        Topic67: Class Templates in c++
        constr, Stack<T, size>::Stack()
        constr, classTemplate::classTemplate()
        7 4 2 3

        !End of Main()!
        distructor, classTemplate::~classTemplate()
        distructor, Stack<T, size>::~Stack()

        with explicite constr (compiler generated)
        Class Templates in c++
        constr, classTemplate::classTemplate()
        7 4 2 3 
        distructor, Stack<T, size>::~Stack()
    */
}

classTemplate::classTemplate()
{
    std::cout << "constr, classTemplate::classTemplate()" << std::endl;
}

classTemplate::~classTemplate()
{
    std::cout << "distructor, classTemplate::~classTemplate()" << std::endl;
}
/*
Stack::Stack()
{
    cout << "constr, Stack::Stack()" << endl;
}

void Stack::Push(int elem)
{
    m_Buffer[++m_Top] = elem;
}

void Stack::Pop()
{
    --m_Top;
}

int Stack::Top() const
{
    return m_Buffer[m_Top];
}

bool Stack::isEmpty()
{
    return m_Top == -1;
}

Stack::~Stack()
{
    cout << "distructor, Stack::~Stack()" << endl;
}
*/

/*
//note: required if Stack(); constr is used
template <typename T, std::size_t size>
Stack<T, size>::Stack()
{
    std::cout << "constr, Stack<T, size>::Stack()" << std::endl;
}*/

template <typename T, std::size_t size>
Stack<T, size>::Stack(const Stack &obj)
{
    m_Top = obj.m_Top;
    for(int i = 0; i<=m_Top; ++i) //since top start from -1, use <=
    {
        m_Buffer[i] = obj.m_Buffer[i];
    }
}

template <typename T, std::size_t size>
void Stack<T, size>::Push(const T &elem)
{
    m_Buffer[++m_Top] = elem;   //error: array subscript is not an integer
}

template <typename T, std::size_t size>
void Stack<T, size>::Pop()
{
    --m_Top;
}

template <typename T, std::size_t size>
const T &Stack<T, size>::Top() const
{
    return m_Buffer[m_Top]; //error: array subscript is not an integer, fixed with inlude array, and init in class
}

template <typename T, std::size_t size>
bool Stack<T, size>::isEmpty() const
{
    return m_Top == -1;
}


/* factory method, that creates and return instance of Stack class */
template <typename T, std::size_t size>
Stack<T, size> Stack<T, size>::Create() //compiler doen't know type of return value -> Stack , provided param
{
    return Stack<T, size>();    //create temp obj of Stack, returning by value, use it further 
}

template <typename T, std::size_t size>
Stack<T, size>::~Stack() noexcept
{
    std::cout << "\ndistructor, Stack<T, size>::~Stack()" << std::endl;
}