#include <cassert>
#include <iostream>
#include <vector>

namespace Animal
{
    enum Name
    {
        cat,
        chicken,
        dog,
        duck,
        elephant,
        snake,
        max_animals
    };

    const std::vector legs{ 4, 2, 4, 2, 4, 0 };
}

int main()
{
    using namespace Animal;
    assert(max_animals == legs.size());
    std::cout << "An elephant has " << legs[elephant] << " legs.\n";

    return 0;
}
