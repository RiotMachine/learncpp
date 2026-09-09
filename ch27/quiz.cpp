#include <exception>
#include <iostream>
#include <stdexcept>

class Fraction
{
public:
    explicit Fraction(int n, int d=1)
      : m_numerator{ n }, m_denominator{ d }
    {
        if (d == 0)
            throw std::runtime_error { "Invalid denominator" };
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
    {
        return out << f.m_numerator << '/' << f.m_denominator;
    }

private:
    int m_numerator{ };
    int m_denominator{ 1 };
};

int main()
{
    int n{ };
    std::cout << "Enter the numerator: ";
    std::cin >> n;

    int d{ };
    std::cout << "Enter the denominator: ";
    std::cin >> d;

    try
    {
        Fraction f{ n, d };
        std::cout << f << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}
