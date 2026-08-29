#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <algorithm>
#include <cassert>
#include <iostream>

template <int ROWS, int COLS, typename T>
class Array2D
{
public:
    Array2D() = default;

    template <int N>
    explicit Array2D(const T (*data)[N])
    {
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                (*this)(i,j) = data[i][j];
        }
    }

    Array2D(const Array2D& arr)
    {
        std::copy_n(arr.m_data, ROWS*COLS, m_data);
    }

    Array2D& operator=(const Array2D& arr)
    {
        if (&arr == this)
            return *this;
        std::copy_n(arr.m_data, ROWS*COLS, m_data);
        return *this;
    }

    ~Array2D() = default;

    T& operator()(int row, int col)
    {
        assert(row >= 0 && row < ROWS);
        assert(col >= 0 && col < COLS);
        return m_data[row * COLS + col];
    }
    const T& operator()(int row, int col) const
    {
        assert(row >= 0 && row < ROWS);
        assert(col >= 0 && col < COLS);
        return m_data[row * COLS + col];
    }

private:
    T m_data[ROWS*COLS] { };
};

template <int ROWS, int COLS, typename T>
inline std::ostream& operator<<(std::ostream& out, const Array2D<ROWS, COLS, T>& arr)
{
    for (int i{ }; i < ROWS; ++i)
    {
        for (int j{ }; j < COLS; ++j)
            out << arr(i,j) << "    ";
        out << '\n';
    }
    return out;
}

#endif