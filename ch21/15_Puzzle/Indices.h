#ifndef INDICES_H
#define INDICES_H

#include <cstddef>


namespace Indices
{
    using Idx = std::size_t;

    struct Idx2D
    {
        Idx row{ };
        Idx col{ };
    };

    inline Idx make1D(Idx2D d, Idx cols)
    { 
        return d.row * cols + d.col; 
    }

    inline Idx make1D(Idx row, Idx col, Idx cols)
    {
        return make1D(Idx2D { row, col }, cols);
    }
}

#endif