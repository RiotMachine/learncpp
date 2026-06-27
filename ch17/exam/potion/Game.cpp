#include "Game.h"

void init()
{


}


void shop()
{
    for (const auto& potion : Type)
       std::cout << static_cast<int>(Type) << ") "
           << names[potion] << " costs " << costs[potion]
           << '\n';
}


void close()
{



}
