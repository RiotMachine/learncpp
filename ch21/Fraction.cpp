#include <iostream>
#include <numeric>

class Fraction
{
public:
    Fraction(int x=0, int y=1)
        : m_numerator{ x }, m_denominator{ y } { reduce(); }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int x);
    friend Fraction operator*(int x, const Fraction& f);

private:
    int m_numerator{ };
    int m_denominator{ };
};


std::istream& operator>>(std::istream& in, Fraction& f)
{
    int numerator{ };
    char slash{ };
    int denominator{ };
    in >> numerator >> slash >> denominator;
    if (denominator == 0)
        in.setstate(std::ios_base::failbit);
    if (in)
        f = Fraction { numerator, denominator };
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.m_numerator << '/' << f.m_denominator;
}

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
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

    return 0;
}