#include "Board.h"
#include "Random.h"
#include <algorithm>


void Board::shuffleTiles()
{
    std::shuffle(m_tiles.begin(), m_tiles.end(), Random::mt);
}


void BoardSet::setBoard()
{
    for (Idx i{ }; i < rows; ++i)
    {
        for (Idx j{ }; j < cols; ++j)
            m_board[i][j] = m_tiles[i+j];
    }
}


constexpr BoardSet::TileTray BoardSet::createTiles()
{
    TileTray tray{ };
    for (Idx i{ 0 }; i < arr.size(); ++i)
        arr[i] = i+1;
    return arr;
}



