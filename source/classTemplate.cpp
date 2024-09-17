#include <iostream>
#include "../header/classTemplate.hpp"

using namespace std;

void classTemplate::all_classTemplate_methods()
{
    st.Push(3);
    st.Push(2);
    st.Push(4);
    st.Push(7);

    while (!st.isEmpty())
    {
        cout << st.Top() << ' ';
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
}

classTemplate::classTemplate()
{
    cout << "constr, classTemplate::classTemplate()" << endl;
}

classTemplate::~classTemplate()
{
    cout << "distructor, classTemplate::~classTemplate()" << endl;
}

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
