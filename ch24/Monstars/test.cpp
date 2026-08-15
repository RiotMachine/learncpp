#include "Monster.h"
#include <iostream>
#include <string>

int main()
{
    for (int i{ }; i < 10; ++i)
    {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "A " << m.name() << " (" << m.symbol()
                  << ") was created.\n";
    }

    return 0;
}
