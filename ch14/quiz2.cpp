#include <iostream>

class Fraction
{
public:
    Fraction()
    {
        std::cout << "Enter a numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

    void multiply()
    {
        Fraction multiplicand{ };
        m_numerator *= multiplicand.m_numerator;
        m_denominator *= multiplicand.m_denominator;
    }

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};


int main()
{
    Fraction f1{ };
    f1.multiply();

    std::cout << "Your fractions multiplied together: ";
    f1.print();

    return 0;
}
