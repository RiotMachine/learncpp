#ifndef GAMES_H
#define GAMES_H

#include <iosfwd>

enum class WltResult
{
    win,
    loss,
    tie,
};

enum class WlResult
{
    win,
    loss,
};

std::ostream& operator<<(std::ostream&out, WltResult result);

#endif
