#include <iostream>
#include <limits>
#include <optional>
#include <vector>

void clearStream() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

template <typename T>
class Container
{
public:
    Container(const std::vector<T>& v)
        : m_vector{ v } {}

    std::optional<std::size_t> search(const T& x) const
    {
        for (std::size_t i{ 0 }; i < m_vector.size(); ++i)
            if (m_vector[i] == x)
                return i;
        return { };
    }

    void print() const
    {
        for (std::size_t i{ 0 }; i < m_vector.size(); ++i)
            std::cout << m_vector[i] << '\t';
        std::cout << '\n';
    }

    void print(const T& x) const
    {
        std::optional<std::size_t> idx{ search(x) };
        std::cout << "The number " << x;
        if (idx)
            std::cout << " has index " << *idx;
        else
            std::cout << " was not found";
        std::cout << '\n';
    }

private:
    std::vector<T> m_vector{ };
};

template <typename T>
T getNumber(T min, T max)
{
    T x{ };
    while (true)
    {
        std::cout << "Enter a number of the same type between " << min << " and " << max << ": ";
        if (std::cin >> x && x >= min && x <= max)
        {
            clearStream();
            return x;
        }
        std::cin.clear();
        clearStream();
    }
}


int main()
{
    Container arr{ std::vector {4, 6, 7, 3, 8, 2, 1, 9} };
    arr.print();
    arr.print( getNumber(1, 9) );

    std::cout << '\n';

    Container arr2{ std::vector {4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9} };
    arr2.print();
    arr2.print( getNumber(1.1, 9.9) );

    return 0;
}
