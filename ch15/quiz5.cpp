#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad
{
public:
    Triad(const T& x, const U& y, const V& z) :
        m_first{ x }, m_second{ y }, m_third{ z } {}

    const T& first() const  { return m_first; };
    const U& second() const { return m_second; };
    const V& third() const  { return m_third; };
    void print() const;

private:
    T m_first{ };
    U m_second{ };
    V m_third{ };
};

// print() needs to be const so we can use it with const Triads
template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
    std::cout << '[' << m_first << ", " << m_second << ", " <<
        m_third << ']';
}


int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{ 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}
