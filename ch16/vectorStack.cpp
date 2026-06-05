#include <array>
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void print(const std::vector<T>& v)
{
    std::cout << '\t' << "(Stack:";
    if (v.empty())
        std::cout << " empty";
    else
        for (const T& x : v)
            std::cout << ' ' << x;
    std::cout << ")\n";
}

template <typename T>
void push(std::vector<T>& v, T x)
{
    std::cout << "Push " << x;
    v.push_back(x);
}

template <typename T>
void pop(std::vector<T>& v)
{
    std::cout << "Pop";
    v.pop_back();
}

int main()
{
    std::vector<int> v{ };
    print(v);

    constexpr int sentinel{ std::numeric_limits<int>::min() };
    constexpr std::array queue{ 1, 2, 3, sentinel, 4, sentinel, sentinel, sentinel };
    v.reserve(queue.size());

    for (const auto& x : queue)
    {
        if (x == sentinel)
            pop(v);
        else
            push(v, x);
        print(v);
    }

    return 0;
}
