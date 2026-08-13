#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
public:
    Fruit(std::string_view name, std::string_view color)
      : m_name{ name }, m_color{ color } {}

    const std::string& name() const  { return m_name; }
    const std::string& color() const { return m_color; }

private:
    std::string m_name{ };
    std::string m_color{ };
};


class Apple : public Fruit
{
public:
    Apple(std::string_view name, std::string_view color, double fiber)
      : Fruit(name, color),
        m_fiber{ fiber } {}

    double fiber() const { return m_fiber; }

private:
    double m_fiber{ };
};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
    return out << "Apple(" << a.name() << ", " << a.color()
               << ", " << a.fiber() << ')';
}


class Banana : public Fruit
{
public:
    Banana(std::string_view name, std::string_view color)
      : Fruit(name, color) {}
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    return out << "Banana(" << b.name() << ", " << b.color() << ')';
}


int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}
