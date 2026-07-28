#include <cstdint>
#include <iostream>

class Average
{
public:
    double calculate() const
    {
        if (!m_quant)
            return 0;
        return m_sum / static_cast<double>(m_quant); 
    }

    Average& operator+=(int input)
    {
        m_sum += input;
        ++m_quant;
        return *this;
    }

private:
    std::int32_t m_sum{ };
    int m_quant{ };
};

std::ostream& operator<<(std::ostream& out, const Average& avg) 
{
    return out << avg.calculate();
}


int main()
{
    Average avg{ };
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n';

    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';

    avg += -10;
    std::cout << avg << '\n';

    (avg += 6) += 10;
    std::cout << avg << '\n';

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}