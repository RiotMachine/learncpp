#ifndef PAIR_H
#define PAIR_H

#include <string>

template <typename T, typename U>
class Pair
{
public:
    Pair(const T& item1, const U& item2)
      : m_first{ item1 }, m_second{ item2 } {}

    const T& first()  const { return m_first; }
    const U& second() const { return m_second; }

protected:
    T m_first{ };
    U m_second{ };
};


template <typename T>
class PairSame : public Pair<T, T>
{
public:
    PairSame(const T& item1, const T& item2)
      : Pair<T,T>{item1, item2} {}
};


template <typename U>
class PairStringValue : public Pair<std::string, U>
{
public:
    PairStringValue(const std::string& str, const U& value)
      : Pair<std::string, U>{str, value} {}
};

#endif
