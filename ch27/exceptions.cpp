#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class StringSink
{
public:
    StringSink(int x, char c) try
      : m_str(x, c) {}
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
        throw;
    }

    const std::string& get() const { return m_str; }

private:
    std::string m_str;
};

void print(int x, char c)
{
    try
    {
        StringSink ss{ x, c };
        std::cout << ss.get() << '\n';
    }
    catch (const std::length_error& ex)
    {
        std::cerr << "Provided length too big\n";
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << "Provided length out of range\n";
    }
    catch (const std::logic_error& ex)
    {
        std::cerr << "Bad args.\n";
    }
}

int main()
{
    print(-11, 't');
    print(12, 'c');
    std::cout << "Bye!\n";

    return 0;
}
