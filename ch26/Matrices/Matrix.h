#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <iostream>

template <int ROWS, int COLS, typename T>
class Matrix
{
public:
    Matrix() = default;

    template <std::size_t N>
    explicit Matrix(const T (*data)[N])
    {
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                (*this)(i,j) = data[i][j];
        }
    }

    Matrix(const Matrix& mtx)
    {
        std::copy_n(mtx.m_data, ROWS*COLS, m_data);
    }

    Matrix& operator=(const Matrix& mtx)
    {
        if (&mtx == this)
            return *this;
        std::copy_n(mtx.m_data, ROWS*COLS, m_data);
        return *this;
    }

    ~Matrix() = default;

    T& operator()(int row, int col)
    {
        return m_data[row * COLS + col];
    }
    const T& operator()(int row, int col) const
    {
        return m_data[row * COLS + col];
    }

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

    friend std::ostream& operator<<(std::ostream& out, const Matrix& mtx)
    {
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                out << mtx(i,j) << "    ";
            out << '\n';
        }
        return out;
    }

private:
    T m_data[ROWS*COLS] { };
};

#endif