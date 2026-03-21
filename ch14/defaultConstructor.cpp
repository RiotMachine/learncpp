// default constructor creates non-aggregate object w/ no provided vals req
// prefer default constructor explicitly defaulted over one with empty body
// only create a default constructor if object w default vals makes sense

#include <iostream>

class Library
{
private:
    bool m_isTVOn{ true };

public:
    Library() = default;
    Library(bool isTVOn)
        : m_isTVOn{ isTVOn }
    {
    }

    void printTVOn() const
    {
        std::cout << "The TV is " << (m_isTVOn ? "on" : "off") << '\n';
    }
};

int main()
{
    Library l1{};
    l1.printTVOn();

    Library l2{false};
    l2.printTVOn();

    return 0;
}
