#include <array>
#include <iostream>

using IDX = std::size_t;

template <typename T, IDX Row, IDX Col>
using Array2d = std::array<std::array<T, Col>, Row>;

template <typename T, IDX Row, IDX Col>
constexpr int rowLen(const Array2d<T, Row, Col>& arr)
{ return Row; }

template <typename T, IDX Row, IDX Col>
constexpr int colLen(const Array2d<T, Row, Col>& arr)
{ return Col; }


template <typename T, IDX Row, IDX Col>
void print(const Array2d<T, Row, Col>& arr)
{
    for (const auto& row : arr)
    {
        for (const T& e : row)
            std::cout << e << ' ';
        std::cout << '\n';
    }
}


int main()
{
    constexpr Array2d<int, 3, 4> arr{{
        {0, 9, 8, 7},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    }};

    print(arr);

    std::cout << "The array has " << rowLen(arr) << " rows and "
      << colLen(arr) << " columns.";

    return 0;
}