#include <cassert>
#include <iostream>
#include <string>

using Idx = std::size_t;

class MyString
{
public:
    MyString(const std::string& str)
        : m_str{ str } {}

    MyString operator()(Idx i, Idx len)
    {
        assert(i + len < m_str.size());
        return m_str.substr(i, len);
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& ms)
    {
        return out << ms.m_str;
    }

private:
    std::string m_str{ };
};


int main()
{
    MyString s{ "Hello, world!" };
    std::cout << s(7, 5) << '\n';

    return 0;
}
