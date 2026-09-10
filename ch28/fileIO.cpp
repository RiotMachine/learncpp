#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using Time = std::chrono::system_clock;

int main()
{
    // if std::ios::in is used, creating a file may cause fstream to fail
    std::ofstream ofile{ "test.txt", std::ios::app };
    if (!ofile)
    {
        std::cerr << "File could not be opened.\n";
        return 1;
    }
    std::cout << "Input your name: ";
    std::string name{ };
    std::getline(std::cin >> std::ws, name);

    // https://stackoverflow.com/a/27856440
    std::time_t curr_time{ Time::to_time_t(Time::now()) };
    ofile << name << " was here at " << std::ctime(&curr_time);

    ofile.close();

    std::ifstream ifile{ "test.txt" };
    if (!ifile)
    {
        std::cerr << "File could not be opened.\n";
        return 1;
    }
    std::string extract{ };
    while (std::getline(ifile, extract))
        std::cout << extract << '\n';

    return 0;
}
