#ifndef 15PUZZLE_H
#define 15PUZZLE_H

class 15Puzzle
{
public:
    15Puzzle()
    : m_time{ 

    void welcome();
    void play()
    void printResults();

private:
    constexpr static int s_rows{ 4 };
    constexpr static int s_cols{ 4 };
    constexpr static int s_blankSpaces{ 1 }

    BoardSet<s_rows, s_cols, s_blankSpaces>  m_boardSet{ };
    int m_moves{ };
    m_time{ };
};

#endif
