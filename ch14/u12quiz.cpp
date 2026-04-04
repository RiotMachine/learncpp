#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
    std::string m_color{ "black" };
    float m_radius{ 10.0 };

    void printBall() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

public:
    Ball()
    {
        printBall();
    }

    Ball(std::string_view color)
        : m_color{ color }
    {
        printBall();
    }

    Ball(float radius)
        : m_radius{ radius }
    {
        printBall();
    }

    Ball(std::string_view color, float radius)
        : m_color{ color }, m_radius{ radius }
    {
        printBall();
    }
};


int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
