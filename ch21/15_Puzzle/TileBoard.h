#ifndef TILEBOARD_H
#define TILEBOARD_H

#include "Idx.h"
#include "IOHelper.h"
#include <array>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <utility>   // for std::swap

// Implements a rectangular game board of tiles

template <int rows, int cols, int tiles>
class TileBoard
{
public:
    static_assert(rows > 0 && cols > 0);
    static_assert(rows * cols >= tiles);

    using Tile = int;
    constexpr static Tile s_emptySpace{ -1 };

    TileBoard() = default;

    Tile& operator() (Idx::D1 row, Idx::D1 col)       { return m_board[row][col]; }
    Tile operator()  (Idx::D1 row, Idx::D1 col) const { return m_board[row][col]; }
    Tile& operator[] (Idx::D1 index)
    {
        Idx::D2 d2Index{ Idx::toD2(index, cols) };
        return m_board[d2Index.row][d2Index.col];
    }
    Tile operator[] (Idx::D1 index) const
    {
        Idx::D2 d2Index{ Idx::toD2(index, cols) };
        return m_board[d2Index.row][d2Index.col];
    }

    Idx::D2 find(Tile t) const
    {
        for (Idx::D1 i{ }; i < rows; ++i)
        {
            for (Idx::D1 j{ }; j < cols; ++j)
            {
                if (m_board[i][j] == t)
                    return { i, j };
            }
        }
        return { rows, cols };
    }

    void reset() { m_board = m_savedBoard; }

    void save() { m_savedBoard = m_board; }

    void swap(Idx::D2 a, Idx::D2 b)
    {
        assert(a.row < rows && a.col < cols);
        assert(b.row < rows && b.col < cols);
        std::swap(m_board[a.row][a.col], m_board[b.row][b.col]);
    }


private:
    using Board = std::array<std::array<Tile, cols>, rows>;

    constexpr static Board createBoard(int start=1, int factor=1)
    {
        Board board;
        for (Idx::D1 i{ }; i < rows; ++i)
        {
            for (Idx::D1 j{ }; j < cols; ++j)
            {
                Idx::D1 locD1{ Idx::toD1(i, j, cols) };
                if (locD1 < tiles)
                    board[i][j] = (locD1 + start) * factor;
                else
                    board[i][j] = s_emptySpace;
            }
        }
        return board;
    }

    Board m_board{ createBoard() };
    Board m_savedBoard{ m_board };
};


template <int rows, int cols, int tiles>
std::ostream& operator<<(std::ostream& out, const TileBoard<rows,cols,tiles>& board)
{
    IOHelper::OStreamSaver oss{ out };
    out << std::left;
    for (Idx::D1 i{ }; i < rows; ++i)
    {
        for (Idx::D1 j{ }; j < cols; ++j)
        {
            out << std::setw(6);
            if (board(i, j) == TileBoard<rows,cols,tiles>::s_emptySpace)
                out << ' ';
            else
                out << board(i, j);
        }
        out << '\n';
    }
    return out;
}

#endif