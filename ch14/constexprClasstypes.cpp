/*
Constexpr aggregates and classes

Notes:
implicitly defined constructors are constexpr if possible
explicitly defaulted constructors must be declared so
*/

#include <cmath>
#include <iostream>

struct Coordinate // Aggregate
{
    int m_x{ };
    int m_y{ };
};

class Vector // Non-aggregate
{
private:
    int m_x1{ };
    int m_x2{ };

public:
    constexpr Vector(int x1, int x2)
        : m_x1{ x1 }, m_x2{ x2 }
    {
    }

    constexpr Vector(const Coordinate& c)
        : Vector(c.m_x, c.m_y) {}

    constexpr int x1() const { return m_x1; }
    constexpr int x2() const { return m_x2; }

    // constexpr - function evaluatable at compile time
    // const 1   - pointer cannot be used to modify pointee
    // const 2   - pointer cannot be reseated (meaningless in return context)
    // const 3   - x1_address() can be called by const Vectors
    // n.b.      - constexpr functions do not have to contain/return const locals
    constexpr const int* const x1_address() const { return &m_x1; }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        return out << "(" << v.m_x1 << "," << v.m_x2 << ")";
    }
};

// std::sqrt and std::pow are not constexpr in C++17
/// but gcc performs some trickery so they behave like constexpr
constexpr double magnitude(const Vector& v)
{
    return std::sqrt( std::pow(v.x1(), 2) + std::pow(v.x2(), 2) );
}

int main()
{
    // Usually ok to make aggregates constexpr by default
    constexpr Coordinate c{4, 5};
    // Classes need a constexpr constructor to be literal types
    /// Literal types := can be used as the type of a constexpr value
    constexpr Vector v{ Coordinate{4,5} };
    constexpr double m{ magnitude(v) };

    std::cout << "Vector " << v << " has magnitude " << m << '\n';
    std::cout << "The address of x1 is " << v.x1_address() << '\n';

    return 0;
}
