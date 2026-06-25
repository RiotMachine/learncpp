#include <cstring>
#include <iostream>

void printForward(const char* start, const char* end)
{
    for ( ; start != end; ++start)
        std::cout << *start;
}
    
void printBackward(const char* start, const char* end)
{
    for (--end; end >= start; --end)
        std::cout << *end;
}

int main()
{
    constexpr char str[]{ "Hello, world!" };

    const char* start{ str };
    const char* end{ str + std::size(str) };

    printForward(start, end);
    std::cout << '\n';
    printBackward(start, end);
    std::cout << '\n';

    return 0;
}