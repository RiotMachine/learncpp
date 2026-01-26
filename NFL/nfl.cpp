#include "helpers.h"
#include "nfl.h"
#include <iostream>
#include <string>

std::ostream& NFL::operator<<(std::ostream& out, NFL::Team team)
{
    switch (team)
    {
    case NFL::broncos:  return out << "Broncos";
    case NFL::chiefs:   return out << "Chiefs";
    case NFL::colts:    return out << "Colts";
    case NFL::cowboys:  return out << "Cowboys";
    case NFL::eagles:   return out << "Eagles";
    case NFL::texans:   return out << "Texans";
    default:            return out << "???";
    }
}

std::istream& NFL::operator>>(std::istream& in, NFL::Team& team)
{
    std::string s{ };
    in >> s;
    s = lowerString(s);

    if (s == "broncos")       team = NFL::broncos;
    else if (s == "chiefs")   team = NFL::chiefs;
    else if (s == "colts")    team = NFL::colts;
    else if (s == "cowboys")  team = NFL::cowboys;
    else if (s == "eagles")   team = NFL::eagles;
    else if (s == "texans")   team = NFL::texans;
    else                      in.setstate(std::ios_base::failbit);

    return in;
}

