#include "Matrix.h"
#include <iostream>

int main()
{
    constexpr int rows{ 2 };
    constexpr int cols{ 3 };

    int arr1[][cols] {
        {1, 2, 3},
        {4, 5, 6}
    };
    int arr2[][cols] {
        {10, 20, 30},
        {40, 50, 60}
    };

    Matrix<rows, cols, int> a{ arr1 };
    Matrix<rows, cols, int> b{ arr2 };

    std::cout << "A:\n"      << a       << '\n'
              << "B:\n"      << b       << '\n'
              << "A+B:\n"    << a + b   << '\n'
              << "~A:\n"     << ~a      << '\n'
              << "A * ~A:\n" << a * ~a;

    return 0;
}