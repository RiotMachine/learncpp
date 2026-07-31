#ifndef BOARD_H
#define BOARD_H

#include <array>

// Implements a rectangular game board with movable tiles

template <int rows, int cols, int emptySpaces>
class BoardSet
{
public:
    using Tile = int;
    using TileTray = std::array<Tile, tilesQuant>;
    using Board = std::array<std::array<Tile, cols>, rows>;

    constexpr Tile emptySpace{ -1 };
    constexpr Idx spaces{ rows * cols };
    constexpr int tilesQuant{ spaces - emptySpaces };

    BoardSet()
    :  m_board{

    void shuffleTiles();
    void setBoard();

private:
    using Idx = std::size_t;

    constexpr std::array<Tile, tilesQuant> createTiles();

    constexpr TileTray s_tileInventory { createTiles() }


    Board m_board{};
    TileTray m_tiles{ } 
};

#endif
