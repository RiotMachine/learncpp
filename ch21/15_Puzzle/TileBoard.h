#ifndef TILEBOARD_H
#define TILEBOARD_H

#include "Helpers.h"
#include "Indices.h"
#include "Random.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <utility>   // for std::swap

// Implements a rectangular game board with movable tiles

template <int rows, int cols, int tiles>
class TileBoard
{
public:
    static_assert(rows > 0 && cols > 0);
    static_assert(rows * cols >= tiles);

    using Tile  = int;
    using Board = std::array<std::array<Tile, cols>, rows>;

    constexpr static Tile s_emptySpace{ -1 };

    TileBoard() = default;

    const Board& board() const { return m_board; }
    void swap(std::size_t aRow, std::size_t aCol, std::size_t bRow, std::size_t bCol)
    {
        assert(aRow < rows && aCol < cols);
        assert(bRow < rows && bCol < cols);
        std::swap(m_board[aRow][aCol], m_board[bRow][bCol]);
    }
    void swap(Indices::Idx2D a, Indices::Idx2D b)
    {
        swap(a.row, a.col, b.row, b.col);
    }
    void shuffleTiles()
    {
        std::shuffle(m_tiles.begin(), m_tiles.end(), Random::mt);
        m_board = createBoard();
    }

private:
    using Idx      = Indices::Idx;
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
            {
                Idx trayIdx{ Indices::make1D(i, j, cols) };
                if (trayIdx < m_tiles.size())
                    board[i][j] = m_tiles[trayIdx];
                else
                    board[i][j] = s_emptySpace;
            }
        }
        return board;
    }

    TileTray m_tiles{ createTiles() };
    Board m_board   { createBoard() };
};


template <int rows, int cols, int tiles>
std::ostream& operator<<(std::ostream& out, const TileBoard<rows,cols,tiles>& tb)
{
    Helpers::OStreamSaver oss{ out };
    const auto& board{ tb.board() };
    out << std::left;
    for (const auto& row : board)
    {
        for (const auto tile : row)
        {
            out << std::setw(6);
            if (tile == TileBoard<rows,cols,tiles>::s_emptySpace)
                out << ' ';
            else
                out << tile;
        }
        out << '\n';
    }
    return out;
}

#endif