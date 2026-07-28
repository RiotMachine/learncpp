#include "IntArray.h"
#include <cstddef>
#include <iostream>

using Idx = std::size_t;

void IntArray::deepCopy(const IntArray& source)
{
    delete[] m_arr;
    m_size = source.m_size;
    if (source.m_arr)
    {
        m_arr = new int[m_size];
        for (Idx i{ 0 }; i < m_size; ++i)
            m_arr[i] = source.m_arr[i];
    }
    else
        m_arr = nullptr;
}

std::ostream& operator<<(std::ostream& out, const IntArray& arr)
{
    for (Idx i{ }; i < arr.m_size; ++i)
    {
        out << arr.m_arr[i];
        if (i < arr.m_size-1)
            out << ' ';
    }
    return out;
}