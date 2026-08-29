#include "Matrix.h"
#include <iostream>

int main()
{
    constexpr int rows{ 2 };
    constexpr int cols{ 3 };

    int arr1[][cols] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int arr2[][cols] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    Matrix<int> a{ rows, cols, arr1 };
    Matrix<int> b{ rows, cols, arr2};

    std::cout << "A:\n"           << a
              << "B:\n"           << b
              << "Sum (A+B):\n"   << a + b
              << "A Transpose:\n" << ~a
              << "A x A^T:\n"      << a * ~a;

    return 0;
}
