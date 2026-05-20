#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

template <typename T=int>
class Sport
{
public:
    enum Type
    {
        individual,
        team
    };

    Sport(std::string_view name, Type type=individual) :
        m_name{ name }, m_type{ type } {}

    ~Sport()
    {
        std::cout << "Killing " << m_name << ".\n";
    }

    std::string_view getName() const { return m_name; }
    T getPoints() const { return m_points; }
    void play() const { std::cout << "You played " << m_name << ".\n"; }

private:
    Type m_type{ };
    std::string m_name{ };
    T m_points{ 0 };
};

void capitalize(std::string& string)
{
    string.front() = std::toupper(string.front());
}

template <typename T>
void getScoreType(const Sport<T>& sport)
{
    std::string sportName{ sport.getName() };
    capitalize(sportName);
    std::cout << sportName << " has score type " <<
        typeid(sport.getPoints()).name() << ".\n";
}

int main()
{
    Sport soccer{ "soccer", Sport<int>::team };
    Sport<double> track{ "track" };
    Sport tennis{ "tennis" };

    tennis.play();
    soccer.play();
    track.play();
    std::cout << '\n';

    getScoreType(soccer);
    getScoreType(tennis);
    getScoreType(track);

    std::cout << "\nShutting down.\n";
    return 0;
}
