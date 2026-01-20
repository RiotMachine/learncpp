#include "games.h"
#include <ostream>

std::ostream& operator<<(std::ostream&out, WltResult result)
{
    switch(result)
    {
    case WltResult::win:  return out << "win";
    case WltResult::loss: return out << "loss";
    case WltResult::tie:  return out << "tie";
    default:              return out << "???";
    }
}
