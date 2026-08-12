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
        std::copy_n(v.m_data.get(), m_length, m_data.get());
    }

    MyVector(MyVector&& v) noexcept
      : MyVector(v.m_length)
    {
        m_data.swap(v.m_data);
    }

    MyVector& operator=(const MyVector& v)
    {
        if (&v == this)
            return *this;
        reallocate(v.m_length);
        std::copy_n(v.m_data.get(), m_length, m_data.get());
    }

    MyVector& operator=(MyVector&& v)
    {
        m_length = v.m_length;
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

    void reset()
    {
        m_length = 0;
        m_data.reset();
    }

    void reallocate(std::size_t newLength)
    {
        m_length = newLength;
        m_data.reset(
            std::make_unique<T[]>(newLength)
        );
    }

    void resize(std::size_t newLength)
    {
        switch (newLength)
        {
        case 0:        reset();
        case m_length: return;
        }

        auto ptr{ std::make_unique<T[]>(newLength) };
        auto moveLength{ std::min(m_length, newLength) };
        std::copy_n(m_data.get(), moveLength, ptr.get());

        m_length = newLength;
        m_data.reset(ptr);
    }

private:
    std::size_t m_length{ };
    std::unique_ptr<T> m_data{ };
};

#endif
