#ifndef MYVECTOR_H
#define MYVECTOR_H

/*
  templated version of Alex's custom array, built around std::unique_ptr
  including move semantics && optimizing moves over copies
*/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <utility>

template <typename T>
class MyVector
{
public:
    MyVector() = default;

    explicit MyVector(std::size_t length)
      : m_length{ length }, m_data{ std::make_unique<T[]>(length) } {}

    MyVector(std::initializer_list<T> list)
      : MyVector(list.size())
    {
        std::copy(list.begin(), list.end(), m_data.get());
    }

    ~MyVector() = default;

    MyVector(const MyVector& v)
      : MyVector(v.m_length)
    {
        std::copy_n(v.m_data.get(), m_length, m_data.get());
    }

    MyVector(MyVector&& v) noexcept
      : m_length{ v.m_length }, m_data{ std::move(v.m_data) }
    {
        v.reset();
    }

    MyVector& operator=(const MyVector& v)
    {
        if (&v == this)
            return *this;
        reallocate(v.m_length);
        std::copy_n(v.m_data.get(), m_length, m_data.get());
        return *this;
    }

    MyVector& operator=(MyVector&& v) noexcept
    {
        if (&v == this)
            return *this;
        m_length = v.m_length;
        m_data = std::move(v.m_data);
        v.reset();
        return *this;
    }

    T& operator[](std::size_t index)
    {
        assert(index < m_length);
        return m_data[index];
    }

    const T& operator[](std::size_t index) const
    {
        assert(index < m_length);
        return m_data[index];
    }

    std::size_t size() const { return m_length; }

    void reset()
    {
        m_length = 0;
        m_data.reset();
    }

    void reallocate(std::size_t newLength)
    {
        m_length = newLength;
        m_data = std::make_unique<T[]>(newLength);
    }

    void resize(std::size_t newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength == 0)
        {
            reset();
            return;
        }

        auto ptr  { std::make_unique<T[]>(newLength) };
        auto start{ m_data.get() };
        auto end  { start + std::min(m_length, newLength) };

        std::move(start, end, ptr.get());

        m_length = newLength;
        m_data = std::move(ptr);
    }

    void insert(T value, std::size_t index)
    {
        assert(index <= m_length);

        auto ptr  { std::make_unique<T[]>(m_length+1) };
        auto start{ m_data.get() };

        std::move(start, start+index, ptr.get());
        ptr[index] = std::move(value);
        std::move(start+index, start+m_length, ptr.get()+index+1);

        ++m_length;
        m_data = std::move(ptr);
    }

    void remove(std::size_t index)
    {
        assert(index < m_length);

        if (m_length < 2)
        {
            reset();
            return;
        }

        auto ptr  { std::make_unique<T[]>(m_length-1) };
        auto start{ m_data.get() };

        std::move(start, start+index, ptr.get());
        std::move(start+index+1, start+m_length, ptr.get()+index);

        --m_length;
        m_data = std::move(ptr);
    }

    void push_front(const T& value) { insert(value, 0); }
    void push_front(T&& value)      { insert(std::move(value), 0); }
    void push_back(const T& value)  { insert(value, m_length); }
    void push_back(T&& value)       { insert(std::move(value), m_length); }

private:
    std::size_t m_length{ };
    std::unique_ptr<T[]> m_data{ };
};

#endif
