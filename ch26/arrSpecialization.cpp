#include <iostream>
#include <iomanip>

template <int ROWS, int COLS, T typename>
class Dynamic2D
{
public:
    Dynamic2D()
      : m_rows{ ROWS }, m_cols{ COLS }, m_array{ new int*[ROWS] }
    {
        for (int i{ }; i < m_rows; ++i)
            m_array[i] = new int[m_cols];
    }

    T& operator()(int row, int col) { return m_array[row][col]; }
    const T operator(int row, int col) const { return m_array[row][col; }

    Dynamic2D(const Dynamic2D& d) = delete;
    Dynamic2D& operator=(const Dynamic2D& d) = delete;

    ~Dynamic2D()
    {
        for (int i{ }; i < m_rows; ++i)
            delete[] m_array[i];
        delete[] m_array;
    }

private:
    int m_rows{ };
    int m_cols{ };
    T** m_array{ nullptr };
};

void matrixAdd(const Dynamic2D& arr1, const Dynamic2D& arr2, int result[][COLS])
{
    for (int i{ }; i < ROWS; ++i)
    {
        for (int j{ }; j < COLS; ++j)
            result[i][j] = arr1(i,j) + arr2(i,j);
    }
}

void matrixAdd(const int a[][COLS], const int b[][COLS], int result[][COLS])
{
    for (int i{ }; i < ROWS; ++i)
    {
        for (int j{ }; j < COLS; ++j)
            result[i][j] = a[i][j] + b[i][j];
    }
}

void matrixTranspose(const int original[][COLS], int transpose[][ROWS])
{
    for (int i{ }; i < ROWS; ++i)
    {
        for (int j{ }; j < COLS; ++j)
            transpose[j][i] = original[i][j];
    }
}

// Currently only works when aRows == bCols.
void matrixMultiply(const int a[][COLS], const int b[][ROWS], int result[][ROWS])
{
    const int aRows{ ROWS };
    const int bCols{ ROWS };
    const int innerLen{ COLS };

    for (int i{ }; i < aRows; ++i)
    {
        for (int j{ }; j < bCols; ++j)
        {
            result[i][j] = 0;
            for (int k{ }; k < innerLen; ++k)
                result[i][j] += a[i][k]*b[k][j];
        }
    }
}

template <int N>
void printMatrix(const int m[][N], const int rows, const std::string& label)
{
    std::cout << label << ":\n";
    for (int i{ }; i < rows; ++i)
    {
        for (int j{ }; j < N; ++j)
            std::cout << std::setw(5) << m[i][j];
        std::cout << '\n';
    }
}

int main()
{
    constexpr int rows{ 2 };
    constexpr int cols{ 3 };

    int a[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int b[ROWS][COLS] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    printMatrix(a, ROWS, "A");
    printMatrix(b, ROWS, "B");

    int sum[ROWS][COLS];
    matrixAdd(a, b, sum);
    printMatrix(sum, ROWS, "Sum (A+B)");

    int transpose[COLS][ROWS];
    matrixTranspose(a, transpose);
    printMatrix(transpose, COLS, "A Transpose");

    int product[ROWS][ROWS];
    matrixMultiply(a, transpose, product);
    printMatrix(product, ROWS, "A x A^T");

    Dynamic2D dynArr1{ ROWS, COLS, 1 };
    Dynamic2D dynArr2{ ROWS, COLS, 2 };
    int sum2[ROWS][COLS];
    matrixAdd(dynArr1, dynArr2, sum2);
    printMatrix(sum2, ROWS, "Heap Sum");

    return 0;
}
