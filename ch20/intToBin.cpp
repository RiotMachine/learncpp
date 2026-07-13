#include <iostream>

void printBinary(int x)
{
    unsigned int ux{ static_cast<unsigned>(x) };
    if (ux > 1)
        printBinary(ux / 2);
    std::cout << (ux % 2);
}

int main()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    printBinary(x);

    return 0;
}