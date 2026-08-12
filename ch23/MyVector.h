#ifndef MYVECTOR_H
#define MYVECTOR_H

/*
  templated version of Alex's custom array, built around std::unique_ptr
  including move semantics && optimizing moves over copies
*/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <memory>

template <typename T>
class MyVector
{
public:
    MyVector() = default;
    MyVector(std::size_t length)
      : m_length{ length }, m_data{ std::make_unique<T[]>(length) } {}

    ~MyVector() = default;

    MyVector(const MyVector& v)
      : MyVector(v.m_length)
    {
        auto start{ v.m_data.get(); }
        auto end{ start + v.m_length; }
        std::copy(start, end, m_data.get());
    }

    MyVector(MyVector&& v)
    {
        m_length = v.m_length;
        m_data.swap(v.m_data);
    }

    MyVector& operator=(const MyVector& v)
    {
        if (&v == this)
            return *this;
    }

    MyVector& operator=(MyVector&& v)
    {
        m_data.swap(v.m_data);
    }

    int& operator[](std::size_t index)
    {
        assert(index < m_length);
        return m_data[index];
    }

    int operator[](std::size_t index) const
    {
        assert(index < m_length);
        return m_data[index];
    }

    std::size_t size() { return m_length; }

    void erase()
    {
        m_data.reset();
        m_length = 0;
    }

    void resize(std::size_t newLength)
    {
        switch (newLength)
        {
        case 0:        erase();
        case m_length: return;
        }

        if (newLength < m_length)
        {
            m_length = newLength;
            return;
        }



        auto newData{ std::make_unique<T[]>(newLength) };
        std::size_t moveLength{ std::min(m_length, newLength) };
       
        newData = std::move(m_data); 

        m_data.reset(newData);
    }

private:
    std::size_t m_length{ };
    std::unique_ptr<T> m_data{ };
};

#endif
