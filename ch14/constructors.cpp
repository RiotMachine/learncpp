#include <iostream>
#include <string>
#include <string_view>

class Fraction
{
private:
    // direct list init defaults to 0 for fundamental data types
    int m_numerator{ };
    int m_denominator{ 1 };

public:
    // implicit default constructor only when no user-defined constructors
    Fraction() = default;

    Fraction(int numerator, int denominator=1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    int numerator() const   { return m_numerator; };
    int denominator() const { return m_denominator; };
};


class Real
{
private:
    double m_value{ };

public:
    // best practice to make constructor w/ single arg explicit
    explicit Real(double number)
        : m_value{ number }
    {
    }

    // not best practice, just for practice; same as default copy constructor
    // copy constructor (when not elided) called whenever object is copied
    ///  eg. pass by value
    //// mandatory copy elision still worx even if you =delete copy constructor
    //// private members are visible to all objects of the class
    Real(const Real& real)
        : m_value { real.m_value }
    {
    }

    double value() const { return m_value; };
};


void print(Fraction f)
{
    std::cout << f.numerator() << " / " << f.denominator() << '\n';
}

void print(Real r)
{
    std::cout << r.value() << '\n';
}

void printString(std::string r)
{
    std::cout << r << '\n';
}

int main()
{
    // Temporary (anonymous) class objects
    print( Fraction{ } );
    print( Real{ 5 } );
    print( Fraction{ 5, 9 } );

    // Converting constructors
    /// only one user-defined conversion in a conversion stack allowed
    /// double to int doesnt count since not user-defined
    /// Using bracelist to count as one passed object since print takes one param
    print(7);
    print( {5.0, 8} );

    // std::string can be implicitly constructed from a c-style string
    // semantic and performant, I guess
    printString("Fuck them picks.");

    // std::string cannot be implicitly constructed from a string_view
    /// semantic but non-performant
    // explicit constructor can still be used thru (direct &&) direct list init
    std::string_view rams{ "Fuck them picks." };
    printString( std::string { rams } );

    printString( static_cast<std::string>(rams) );

    return 0;
}
