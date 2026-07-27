#include <iostream>
#include <numeric>

class Fraction
{
public:
    Fraction(int x, int y=1)
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
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);

private:
    int m_numerator{ };
    int m_denominator{ };
};


std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return out << f.m_numerator << '/' << f.m_denominator;
}

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

bool operator==(const Fraction& f1, const Fraction& f2)
{
    return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
    int lcm{ std::lcm(f1.m_denominator, f2.m_denominator) };
    int f1Factor{ lcm / f1.m_denominator };
    int f2Factor{ lcm / f2.m_denominator };
    return f1.m_numerator*f1Factor < f2.m_numerator*f2Factor;
}

bool operator!=(const Fraction& f1, const Fraction& f2) { return !(f1 == f2); }
bool operator>(const Fraction& f1, const Fraction& f2)  { return f2 < f1; }
bool operator<=(const Fraction& f1, const Fraction& f2) { return !(f2 < f1); }
bool operator>=(const Fraction& f1, const Fraction& f2) { return !(f1 < f2); }

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction { f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator };
}


int main()
{
    Fraction f1{ 3, 2 };
    Fraction f2{ 5, 8 };

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

    return 0;
}