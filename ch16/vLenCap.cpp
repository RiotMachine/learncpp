#include <iostream>
#include <vector>

template <typename T>
void print(const std::vector<T>& v)
{
    std::cout << "Capacity: " << v.capacity() << '\t'
        << "Length: " << v.size() << '\n';
}

int main()
{
    std::vector<std::string> v(1000);
    print(v);

    v.resize(0);
    print(v);

    // non-binding; compiler's choice
    v.shrink_to_fit();
    print(v);
}
