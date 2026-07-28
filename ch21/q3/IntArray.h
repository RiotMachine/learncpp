#include <cassert>
#include <cstddef>
#include <iostream>

using Idx = std::size_t;

class IntArray
{
public:
    explicit IntArray(Idx size)
    {
        m_size = size;
        m_arr = (m_size ? new int[m_size] : nullptr);
    }

    IntArray(const IntArray& source)
    {
        deepCopy(source);
    }
    
    ~IntArray()
    {
        delete[] m_arr;
    }

    IntArray& operator=(const IntArray& source)
    {
        if (this != &source)
            deepCopy(source);
        return *this;
    }

    int& operator[](Idx i)
    {
        assert(i < m_size);
        return m_arr[i];
    }

    const int& operator[](Idx i) const
    {
        assert(i < m_size);
        return m_arr[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);

private:
    void deepCopy(const IntArray& source);

    int* m_arr{ nullptr };
    Idx m_size{ };
};
