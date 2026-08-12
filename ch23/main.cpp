#include "MyVector.h"
#include <iostream>

int main()
{

    MyVector<int> vector(10);

    for (std::size_t i{ }; i < 10; ++i)
        vector[i] = static_cast<int>(i+1);

    vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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

    for (std::size_t i{ }; i < vector.size(); ++i)
        std::cout << vector[i] << ' ';
    std::cout << '\n';

    return 0;
}
