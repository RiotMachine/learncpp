#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
public:
    Matrix(

    T& operator()(int row, int col)
    {
        return m_array[row * cols + col];
    }
    const T& operator()(int row, int col) const
    {
        return m_array[row * self()->cols + col];
    }

    friend Matrix operator+(const Matrix& arr1, const Matrix& arr2)
    {
        Arr2D sum{ arr1.rows(), arr1.cols() };
        for (int i{ }; i < ROWS; ++i)
        {
            for (int j{ }; j < COLS; ++j)
                sum(i,j) = arr1(i,j) + arr2(i,j);
        }
        return sum;
    }

    friend Arr2D operator*(const Arr2D& arr1, const Arr2D& arr2)
    {
        int rows{ arr1.rows() };
        int cols{ arr2.cols() };
        const int innerLen{ arr1.cols() };

        Arr<rows, cols> product;

        for (int i{ }; i < rows; ++i)
        {
            for (int j{ }; j < cols; ++j)
            {
                for (int k{ }; k < innerLen; ++k)
                    product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    friend Arr2D operator~(const Arr2D&)
    {
        Arr2D<cols, rows> transpose;
        for (int i{ }; i < rows; ++i)
        {
            for (int j{ }; j < cols; ++j)
                transpose[j][i] = original[i][j];
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Arr2D
    {
        for (int i{ }; i < rows; ++i)
        {
            for (int j{ }; j < N; ++j)
                std::cout << std::setw(5) << arr[i][j];
            std::cout << '\n';
        }
    }

    int rows() { return ROWS; }
    int cols() { return COLS; }

private:
    T m_matrix[ROWS*COLS]{ };
};


template <typename T>
class Dynamic2D : Arr2D<Dynamic2D, T>
{
public:
    Dynamic2D()
      : m_array{ new T*[ROWS * COLS] } {}

    ~Dynamic2D() { delete[] m_array; }

    Arr2D(const Arr2D& d) = delete;
    Arr2D& operator=(const Dynamic2D& d) = delete;

private:
    T* m_array{ };
};


template <typename T>
class Static2D : Matrix
{
private:
    T m_array[ROWS*COLS]{ }
};

#endif
