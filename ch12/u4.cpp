// Lvalue references to const
/// n.b. though normally temp objects die at the end of the
//// expression in which they are created, when a const lvalue ref
//// is directly bound to a temp object, the temp object's lifetime
//// is extended to match that of the reference

#include <iostream>

int main()
{
    // can use const ref with non-const lvalue
    // have to then modify lvalue directly
    int x{ 5 };
    const int& ref1{ x };
    std::cout << ref1 << '\n';
    x = 6;
    std::cout << ref1 << '\n';

    // lvalue const ref can attach to rvalue
    // in this instance a temp object is created
    /// then the ref attaches to that
    const int& ref2 { 5 };
    std::cout << ref2 << '\n';

    // lvalue const refs can also bind to values of different type
    // temp object is created of the ref's underlying type
    /// and ref binds to that
    char c{ 'b' };
    const int& r2{ c };
    std::cout << c << '\n';
    std::cout << r2 << '\n';
    c = 'c';
    std::cout << c << '\n';
    std::cout << r2 << '\n';

    return 0;
}
