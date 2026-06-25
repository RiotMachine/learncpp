#include <array>        // contains std::begin(), ::end(), and ::size()
#include <algorithm>    // for std::copy()
#include <iostream>
#include <string_view>

/*
    General rules 
    - C-style arrays are for global constexpr objects only
    - prefer std::vector unless array is constexpr
    - std::string and ::string_view for modifiable strs and read-only ones, respectively
*/

// array decays to pointer when passed to function
// still, preferable to use array syntax for parameter
// pointer CAN be reseated; does not reseat underlying array
void function(const int arr[])
{
    const int newArr[]{ 1, 2, 3 };
    arr = newArr;
}

// function templates account for wide range of std::array implementations
template <typename T, std::size_t N>
void function2(const std::array<T, N>& arr)
{
    std::cout << "Hi, I'm an std::array.";
}

namespace Review
{
    constexpr int arr1[]{
        3, 1, 4, 1, 5, 9    
    };

    constexpr int arr2[]{
        2, 7, 1, 8, 2, 8
    };

    // array decay works for getting ptr to first array elem
    const int* ptr{ arr1 };

    // cannot however treat array itself as reseatable ptr
    // arr1 = arr2 doesnt make sense
    // can only change individual elements, and that only if the array is non-const

    // as a result, const type* const && const type[] both function as symbolic constants
    // compiler knows to append a null terminator when working with char*/char[]
    const char str[]{ "Howdy" };
    const char* const str2{ "Hi" };
    std::string_view str3{ "Hiya" };

    // ptr[n] == *(ptr + n)
    // ptr arithmetic moves forward by size of type underlying ptr
    template <std::size_t N=2>
    void print() { std::cout << std::boolalpha << (ptr[N] == arr1[N]); }

    // std::reference_wrapper .get() returns a reference's value
    // C++ multi-dimensional arrays are not jagged by default
    // {{ }} required to frame array of anything other than fundamental types
}

int main()
{
    function(Review::arr1);

    // std::size() will throw if C-style array has decayed
    std::array<int, std::size(Review::arr2)> arr3{ };
    std::copy(std::begin(Review::arr2), std::end(Review::arr2), arr3.begin());
    function2(arr3);
    std::cout << '\n';

    Review::print();
    std::cout << '\n';

    return 0;
}