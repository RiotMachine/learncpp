#include <iostream>
#include <numeric>

class Fraction
{
public:
    Fraction(int x, int y)
        : m_numerator{ x }, m_denominator{ y } { reduce(); }

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int x);
    friend Fraction operator*(int x, const Fraction& f);

private:
    int m_numerator{ };
    int m_denominator{ };
};


Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction { f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator };
}

Fraction operator*(const Fraction& f, int x)
{
    return f * Fraction { x, 1 };
}

Fraction operator*(int x, const Fraction& f)
{
    return Fraction { x, 1 } * f;
}


int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}