int main()
{
    constexpr int rows{ 2 };
    constexpr int cols{ 3 };

    int a[][cols] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int b[][cols] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    std::cout << "A:\n"           << a      << '\n'
              << "B:\n"           << b      << '\n'
              << "Sum (A+B):\n"   << a + b  << '\n'
              << "A Transpose:\n" << ~a     << '\n'
              << "A x A^T\n"      << a * ~a << '\n';

    Dynamic2D<int, rows, cols> dynArr1{ };
    Dynamic2D<int, rows, cols> dynArr2{ };
    print(add(dynArr1, dynArr2), "Heap Sum");

    return 0;
}
