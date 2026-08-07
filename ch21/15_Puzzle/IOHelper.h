#ifndef HELPERS_H
#define HELPERS_H

#include <chrono>
#include <iostream>
#include <limits>

namespace Helpers
{
    // IO
    inline void clearBuffer()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline char getChar()
    {
        char c{ };
        while (!(std::cin >> c))
        {
            std::cin.clear();
            clearBuffer();
        }
        clearBuffer();
        return c;
    }

    // thanks qbert220
    // https://stackoverflow.com/a/18822888
    class OStreamSaver
    {
    public:
        explicit OStreamSaver(std::ostream& out)
        :  m_out{ out }, m_flags{ out.flags() } {}

        OStreamSaver(const OStreamSaver& oss) = delete;

        OStreamSaver& operator=(const OStreamSaver& oss) = delete;

        ~OStreamSaver() { m_out.flags(m_flags); }

    private:
        std::ostream& m_out;
        std::ios::fmtflags m_flags;
    };


    // Timing
    class Timer
    {
    public:
        void reset() { m_beg = Clock::now(); }
        double elapsed() const
        { 
            return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
        }

    private:
        using Clock  = std::chrono::steady_clock;
        using Second = std::chrono::duration<double, std::ratio<1>>;

        std::chrono::time_point<Clock> m_beg{ Clock::now() };
    };
}

#endif
