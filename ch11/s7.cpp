// function template instantiation

#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// compiler will create as many copies of template
// as are needed to match actual data type combinations
template <typename T>
T getInput()
{
    while (true)
    {
        std::cout << "Input a value: ";
        T x{};
        if (!(std::cin >> x))
        {
            std::cout << "Invalid input.\n";
            std::cin.clear();
            ignoreLine();
            continue;
        }
        ignoreLine();
        return x;
    }
}

// function-call style syntax looks for an exact type match before
// resorting to making one from a template
template <typename T>
void divide(T x, T y)
{
    std::cout << x << " divided by " << y << " is " << x / y << '\n';
}

void divide(int x, int y)
{
    std::cout << y << " goes into " << x << " " << x / y << " times\n";
    std::cout << x << " mod " << y << " is " << x % y << '\n';
}

// can forbid certain forms of a template from being brought into reality
template <>
void divide(const char* x, const char* y) = delete;

int main()
{
    int x{};
    while (true)
    {
        std::cout << "Input 1 for integer division, 2 for double division: ";
        if (std::cin >> x && (x == 1 || x == 2))
        {
            break;
        }
        else
        {
            std::cout << "You did not input 1 or 2\n";
            std::cin.clear();
            ignoreLine();
        }
    }
    if (x == 1)
    {
        int y {getInput<int>()};
        int z {getInput<int>()};
        divide (y, z);
    }
    else
    {
        double y {getInput<double>()};
        double z {getInput<double>()};
        divide (y, z);
    }

    return 0;
}