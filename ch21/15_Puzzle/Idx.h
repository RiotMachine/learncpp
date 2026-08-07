#ifndef IDX_H
#define IDX_H

#include <cstddef>

namespace Idx
{
    using D1 = std::size_t;

    struct D2
    {
        D1 row{ };
        D1 col{ };
    };

    inline D1 toD1(D2 d, D1 cols)
    { 
        return d.row * cols + d.col; 
    }

    inline D1 toD1(D1 row, D1 col, D1 cols)
    {
        return toD1(D2 { row, col }, cols);
    }

    inline D2 toD2(D1 index, D1 cols)
    {
        return { index / cols, index % cols };
    }
}

#endif