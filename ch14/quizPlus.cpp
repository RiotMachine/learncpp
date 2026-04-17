// making bp version of quiz2

#include <iostream>

class Fraction
{
public:
    explicit Fraction(int numerator=0, int denominator=1)
        : m_numerator{ numerator }, m_denominator{ denominator } {}

    int num()   const { return m_numerator; }
    int denom() const { return m_denominator; }

private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
};


void print(const Fraction& f)
{
    std::cout << f.num() << '/' << f.denom() << '\n';
}

Fraction multiplyFraction(const Fraction& f1, const Fraction& f2)
{
    return Fraction { f1.num() * f2.num(), f1.denom() * f2.denom() };
}

Fraction getFraction()
{
    std::cout << "Enter a numerator: ";
    int x{ };
    std::cin >> x;
    std::cout << "Enter a denominator: ";
    int y{ };
    std::cin >> y;
    std::cout << '\n';
    return Fraction{ x, y };
}


int main()
{
    print(
          multiplyFraction( getFraction(), getFraction() )
        );

    return 0;
}
