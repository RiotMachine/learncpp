#include "MyVector.h"
#include <cstddef>
#include <iostream>

template <typename T>
void print(MyVector<T> v)
{
    for (std::size_t i{ }; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

int main()
{
    // 23.6
    MyVector<int> vector(10);

    for (std::size_t i{ }; i < 10; ++i)
        vector[i] = static_cast<int>(i+1);

    vector.resize(8);
    vector.insert(20, 5);
    vector.remove(3);
    vector.push_back(30);
    vector.push_front(40);

    {
        MyVector v{ vector };
        v = vector;
        v = v;
        vector = vector;
    }

    print(vector);


    // 23.7
    MyVector array{ 5, 4, 3, 2, 1 };
    print(array);

    array = { 1, 3, 5, 7, 9, 11 };
    print(array);


    return 0;
}
