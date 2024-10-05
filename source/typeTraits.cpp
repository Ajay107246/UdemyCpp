#include "../header/typeTraits.hpp"

template <typename T>
inline T devide(T a, T b)
{
    /*
        so, in this method, to chk the type of this T & perform the devision only if its float type
        without TT, it give wrong result : 2
        as TT to check if float inputs, then only work

        -> TT is_floating_point deduce type(T) at compiler time
        at compiler time, expression T/F, entire condition executed at runtime
        at runtim, know that non/floating point type is arg are passed in devide()
        compiler should not compile the code, its more desirable cause chk will perform at compiler time
    */
    static_assert(is_floating_point<T>::value, "use floating point types only");  //static assertion failed: use floating point types only, use float
    if (is_floating_point<T>::value == false)
    {
        cout << "use floating point types!" << endl;
        return 0;
    }
    return a/b; //work for float/double, but for int: 
    /*
        output:
        use floating point types!
        0
        this is how we can see use TT for introspection
    */
}

template <typename T>
void check(T&&)
{
    /*
        deliberately pasing && forwarding reference, so function can accept L&R-value
        invoke check() from below function
        in some case, want to remove, and use remove_reference<T>::type : returns type

    */
    cout << boolalpha;
    cout << "is Reference?: " << is_reference<T>::value << endl;
    cout << "after removing: " << is_reference<typename remove_reference<T>::type>::value << endl;
    //typename: type is dependant type of remove_reference class
}

void all_type_traits_methods()
{
    cout << boolalpha
    << "is integer?: " << is_integral<int>::value << endl; //specify type: int, return boolean value will have a const (value)
    /*
        value: true/false
        all type traits works in this way
        pass the type and then whether it returns t/f using 'value' member
        header: <type_traits>

        output:
        Topic71, type traits with Template in c++
        is integer?: true
        
        -> meaning: is_integral<int>::value -> int is integer : true
        TT useful while working with template
        see divide() method

        there are other TT, allows you to transform a type        
        see check() method

        there are other TT, perform a transformation on types
        there TT internally used by many library function -> std::forward & std::move
        
        check devide() -> if() condition
    */
    cout << devide(5.5,2.2) << endl;

    check(5);
    int value{};
    check(value);

    /*
        when arg:5 -> not a reference
        but when value -> its reference

        output:
        Topic71, type traits with Template in c++
        is integer?: true
        use floating point types!
        0
        is Reference?: false
        is Reference?: true

        output2:
        Topic71, type traits with Template in c++
        is integer?: true
        use floating point types!
        0
        is Reference?: false
        after removing: false
        is Reference?: true
        after removing: false --> type T is no longer a reference

    */

}