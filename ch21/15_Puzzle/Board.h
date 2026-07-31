#ifndef BOARD_H
#define BOARD_H

#include <array>

// Implements a rectangular game board with movable tiles

template <int rows, int cols, int emptySpaces>
class BoardSet
{
public:
    using Idx   = std::size_t;
    using Tile  = int;
    using Board = std::array<std::array<Tile, cols>, rows>;

    constexpr static Tile s_emptySpace{ -1 };
    constexpr static Idx  s_spaces    { rows * cols };
    constexpr static Idx  s_tilesQuant{ s_spaces - emptySpaces };

    using TileTray = std::array<Tile, s_tilesQuant>;

    BoardSet() = default;

    void shuffleTiles();
    void setBoard();

private:
    constexpr static TileTray createTiles();
    constexpr static TileTray s_tileInventory{ createTiles() };

    TileTray m_tiles{ s_tileInventory };
    Board m_board{ };
};

#endif
