#include <iostream>
#include <vector>


int main()
{
    std::vector v{ 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << std::size(v) << " elements.\n";

    // T is some container type

    // (T::)size_type is a nested typedef for container indices and length
    // size_type can be assumed to be (unsigned) std::size_t
    std::size_t idx{ 1 };
    // T.size() && std::size(T x) return size_type
    std::cout << v[idx] << v.at(idx) << '\n';

    return 0;
}
