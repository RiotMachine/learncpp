#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
public:
    Fruit(std::string_view name, std::string_view color)
      : m_name{ name }, m_color{ color } {}

    const std::string& getName()  const { return m_name; }
    const std::string& getColor() const { return m_color; }

private:
    std::string m_name{ };
    std::string m_color{ };
};


class Apple : public Fruit
{
public:
    Apple(std::string_view name, std::string_view color)
      : Fruit(name, color) {}
    Apple(std::string_view color)
      : Apple("apple", color) {}
};

class Banana : public Fruit
{
public:
    Banana()
      : Fruit("banana", "yellow") {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
      : Apple("granny smith", "green") {}
};


void print(const Fruit& f)
{
    std::cout << "My " << f.getName() << " is " << f.getColor() << ".\n";
}

int main()
{
    Apple a{ "red" };
    Banana b{ };
    GrannySmith c;

    print(a);
    print(b);
    print(c);

    return 0;
}
