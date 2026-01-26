#include "sport.h"
#include <ostream>

std::ostream& Sport::operator<<(std::ostream&out, Sport::WlResult result)
{
    switch(result)
    {
    case Sport::WlResult::win:   return out << "win";
    case Sport::WlResult::loss:  return out << "loss";
    default:                     return out << "???";
    }
}

std::ostream& Sport::operator<<(std::ostream&out, Sport::WltResult result)
{
    switch(result)
    {
    case Sport::WltResult::win:   return out << "win";
    case Sport::WltResult::loss:  return out << "loss";
    case Sport::WltResult::tie:   return out << "tie";
    default:                      return out << "???";
    }
}
