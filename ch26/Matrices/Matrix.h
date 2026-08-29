#ifndef MATRIX_H
#define MATRIX_H

#include "Array2D.h"

template <int ROWS, int COLS, typename T>
class Matrix : public Array2D<ROWS, COLS, T>
{
public:
    Matrix() = default;
    
    explicit Matrix(const T (&data)[ROWS][COLS])
      : Array2D<ROWS, COLS, T>(data) {}

    friend Matrix operator+(const Matrix& arr1, const Matrix& arr2)
    {
        Matrix sum{ arr1 };
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                sum(i,j) += arr2(i,j);
        }
        return sum;
    }

    friend Matrix<COLS, ROWS, T> operator~(const Matrix& original)
    {
        Matrix<COLS, ROWS, T> transpose;
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                transpose(j,i) = original(i,j);
        }
        return transpose;
    }

    template <int N>
    friend Matrix<ROWS, N, T> operator*(const Matrix& arr1, const Matrix<COLS, N, T>& arr2)
    {
        Matrix<ROWS, N, T> product;
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < N; ++j)
            {
                for (int k{ }; k < COLS; ++k)
                    product(i,j) += arr1(i,k) * arr2(k,j);
            }
        }
        return product;
    }
};

#endif