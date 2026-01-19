#include <iostream>

struct Fraction
{
    int num{ 0 };
    int denom{ 1 };
};

void setFraction(Fraction& fraction)
{
    std::cout << "Input a numerator: ";
    std::cin >> fraction.num;
    bool flag{ true };
    do
    {
        std::cout << "Input a denominator: ";
        int temp{ };
        std::cin >> temp;
        if (temp == 0)
            std::cout << "A fraction cannot have a denominator of 0\n";
        else
        {
            fraction.denom = temp;
            flag = false;
        }
    } while (flag);
}

void printFraction(const Fraction& fraction)
{
    std::cout << fraction.num << "/" << fraction.denom << '\n';
}

Fraction getFractionProduct(const Fraction& fraction1, const Fraction& fraction2)
{
    return {
        fraction1.num * fraction2.num,
        fraction1.denom * fraction2.denom
    };
}

int main()
{
    std::cout << "Getting Fraction #1...\n";
    Fraction fraction1{ };
    setFraction(fraction1);
    std::cout << '\n';

    std::cout << "Getting Fraction #2...\n";
    Fraction fraction2{ };
    setFraction(fraction2);
    std::cout << '\n';

    std::cout << "Your fractions multiplied together: ";
    printFraction(getFractionProduct(fraction1, fraction2));

    return 0;
}
