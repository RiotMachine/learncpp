#ifndef MATRIX_H
#define MATRIX_H

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>

template <typename T>
class Matrix
{
public:
    Matrix() = default;

    Matrix(int rows, int cols)
      : m_rows{ rows }, m_cols{ cols },
        m_data{ new T[static_cast<std::size_t>(rows*cols)] { } } {}

    template <std::size_t N>
    Matrix(int rows, int cols, const T (*data)[N])
      : Matrix(rows, cols)
    {
        for (int i{ }; i < rows; ++i)
        {
            for (int j{ }; j < cols; ++j)
                (*this)(i,j) = data[i][j];
        }
    }

    Matrix(const Matrix& mtx)
      : Matrix(mtx.rows(), mtx.cols())
    {
         std::copy_n(mtx.m_data, m_rows*m_cols, m_data);
    }

    void clear()
    {
        delete[] m_data;
        m_data = nullptr;
        m_rows = 0;
        m_cols = 0;
    }

    void reallocate(int newRows, int newCols)
    {
        clear();
        m_rows = newRows;
        m_cols = newCols;
        m_data = new T[static_cast<std::size_t>(newRows*newCols)] { };
    }

    Matrix& operator=(const Matrix& mtx)
    {
        if (&mtx == this)
            return *this;

        reallocate(mtx.rows(), mtx.cols());
        std::copy_n(mtx.m_data, m_rows*m_cols, m_data);

        return *this;
    }

    ~Matrix() { delete[] m_data; }

    T& operator()(int row, int col)
    {
        return m_data[row * m_cols + col];
    }
    const T& operator()(int row, int col) const
    {
        return m_data[row * m_cols + col];
    }

    int rows() const { return m_rows; }
    int cols() const { return m_cols; }

private:
    int m_rows{ };
    int m_cols{ };
    T* m_data{ };
};

template <typename T>
inline Matrix<T> operator+(const Matrix<T>& arr1, const Matrix<T>& arr2)
{
    assert(arr1.rows() == arr2.rows());
    assert(arr1.cols() == arr2.cols());
    Matrix<T> sum(arr1.rows(), arr1.cols());

    for (int i{ }; i < sum.rows(); ++i)
    {
        for (int j{ }; j < sum.cols(); ++j)
            sum(i,j) = arr1(i,j) + arr2(i,j);
    }
    return sum;
}

template <typename T>
inline Matrix<T> operator*(const Matrix<T>& arr1, const Matrix<T>& arr2)
{
    assert(arr1.cols() == arr2.rows());
    Matrix<T> product(arr1.rows(), arr2.cols());
    const int terms{ arr1.cols() };

    for (int i{ }; i < product.rows(); ++i)
    {
        for (int j{ }; j < product.cols(); ++j)
        {
            for (int k{ }; k < terms; ++k)
                product(i,j) += arr1(i,k) * arr2(k,j);
        }
    }
    return product;
}

template <typename T>
inline Matrix<T> operator~(const Matrix<T>& original)
{
    Matrix<T> transpose(original.cols(), original.rows());

    for (int i{ }; i < transpose.rows(); ++i)
    {
        for (int j{ }; j < transpose.cols(); ++j)
            transpose(i,j) = original(j,i);
    }
    return transpose;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Matrix<T>& mtx)
{
    for (int i{ }; i < mtx.rows(); ++i)
    {
        for (int j{ }; j < mtx.cols(); ++j)
            out << std::setw(5) << mtx(i,j);
        out << '\n';
    }
    return out;
}

#endif
