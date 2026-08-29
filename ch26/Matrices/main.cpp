#include "Matrix.h"
#include <iostream>

int main()
{
    constexpr int cols{ 3 };

    int arr1[][cols] {
        {1, 2, 3},
        {4, 5, 6}
    };
    int arr2[][cols] {
        {10, 20, 30},
        {40, 50, 60}
    };

    Matrix a{ arr1 };
    Matrix b{ arr2 };

    std::cout << "A:\n"      << a       << '\n'
              << "B:\n"      << b       << '\n'
              << "A+B:\n"    << a + b   << '\n'
              << "~A:\n"     << ~a      << '\n'
              << "A * ~A:\n" << a * ~a  << '\n';

    double arr3[][cols] {
        {5,  1.2, 7.8888},
        {23, 19, -0.0067}
    };    
    
    Matrix c{ arr3 };
    std::cout << "C:\n" << c;

    return 0;
}