#include <cassert>
#include <functional>
#include <iostream>

namespace Calculator
{
    int add(int x, int y)      { return x + y; }
    int subtract(int x, int y) { return x - y; }
    int multiply(int x, int y) { return x * y; }
    int divide(int x, int y)   { return x / y; }
}


using ArithmeticFcn = std::function<int(int, int)>;

int getInt()
{
    int x;
    std::cin >> x;
    return x;
}

char getChar()
{
    char c;
    std::cin >> c;
    return c;
}

ArithmeticFcn getArithmeticFcn(char c)
{
    switch (c)
    {
    case '+': return Calculator::add;
    case '-': return Calculator::subtract;
    case '*': return Calculator::multiply;
    case '/': return Calculator::divide;
    default:
        std::cerr << "getFcn(): Invalid choice.\n";
        assert(false && "getFcn(): Invalid choice.");
        return nullptr;
    }
}

int main()
{
    std::cout << "Input an integer: ";
    int x{ getInt() };
    std::cout << "Input another integer: ";
    int y{ getInt() };
    std::cout << "Input an operator (+, -, *, /): ";
    char c{ getChar() };

    ArithmeticFcn fcnPtr{ getArithmeticFcn(c) };
    if (fcnPtr)
        std::cout << x << ' ' << c << ' ' << y << " = " 
            << fcnPtr(x, y) << '\n';
    
    return 0;
}
