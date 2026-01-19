#include <iostream>

struct Fraction
{
    int num{ 0 };
    int denom{ 1 };
};

Fraction getFraction()
{
    Fraction temp{ };
    std::cout << "Input a numerator: ";
    std::cin >> temp.num;
    while (true)
    {
        std::cout << "Input a denominator: ";
        std::cin >> temp.denom;
        if (temp.denom == 0)
            std::cout << "A fraction cannot have a denominator of 0\n";
        else
            return temp;
    }
}

void printFraction(const Fraction& fraction)
{
    std::cout << fraction.num << "/" << fraction.denom << '\n';
}

constexpr Fraction getFractionProduct(const Fraction& fraction1, const Fraction& fraction2)
{
    return {
        fraction1.num * fraction2.num,
        fraction1.denom * fraction2.denom
    };
}

int main()
{
    std::cout << "Getting Fraction #1...\n";
    Fraction fraction1{ getFraction() };
    std::cout << '\n';

    std::cout << "Getting Fraction #2...\n";
    Fraction fraction2{ getFraction() };
    std::cout << '\n';

    std::cout << "Your fractions multiplied together: ";
    printFraction(getFractionProduct(fraction1, fraction2));

    return 0;
}
