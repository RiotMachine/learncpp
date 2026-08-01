#ifndef TILEBOARD_H
#define TILEBOARD_H

#include "Random.h"
#include <algorithm>
#include <array>

// Implements a rectangular game board with movable tiles
// Future improvement: variable-sized tileBank that m_tiles pulls from

template <int rows, int cols, int tiles>
class TileBoard
{
public:
    static_assert(rows * cols >= tiles);

    using Idx   = std::size_t;
    using Tile  = int;
    using Board = std::array<std::array<Tile, cols>, rows>;

    constexpr static Tile s_emptySpace{ -1 };

    TileBoard() = default;

    void shuffleTiles()
    {
        std::shuffle(m_tiles.begin(), m_tiles.end(), Random::mt);
        m_board = createBoard();
    }

private:
    using TileTray = std::array<Tile, tiles>;

    constexpr static TileTray createTiles(int start=1, int factor=1)
    {
        TileTray tt;
        for (Idx i{ 0 }; i < tt.size(); ++i)
            tt[i] = (i+start) * factor;
        return tt;
    }

    Board createBoard()
    {
        Board board;
        for (Idx i{ }; i < rows; ++i)
        {
            for (Idx j{ }; j < cols; ++j)
                board[i][j] = i+j < m_tiles.size() ? m_tiles[i+j] : s_emptySpace;
        }
        return board;
    }

    TileTray m_tiles{ createTiles() };
    Board m_board   { createBoard() };
};

#endif
