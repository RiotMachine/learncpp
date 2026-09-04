#include "Pair.h"
#include <iostream>

template <typename T, typename U>
void print(const Pair<T,U>& p)
{
    std::cout << "Pair: " << p.first() << ' ' << p.second() << '\n';
}

int main()
{
    PairSame<int> p1{ 5, 8 };
    print(p1);

    const PairSame<double> p2{ 2.3, 4.5 };
    print(p2);

    Pair<int, double> p3{ 5, 6.7 };
    print(p3);

    const Pair<double, int> p4{ 2.3, 4 };
    print(p4);

    PairStringValue<int> svp{ "Hello", 5 };
    print(svp);

    return 0;
}
