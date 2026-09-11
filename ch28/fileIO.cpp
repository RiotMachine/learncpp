#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using Time = std::chrono::system_clock;

/*
    std::ios::in  - read mode
    std::ios::out - write mode
    std::ios::app - append mode

    [funct]g - read/input   (get)
    [funct]p - write/output (put)

    *creating a file while in read mode may cause fstream to fail
    *cannot switch between read/write w/o a move
*/

std::time_t getTime()
{
    // https://stackoverflow.com/a/27856440
    return Time::to_time_t(Time::now());
}

void appendRecord(std::fstream& file)
{
    std::cout << "Input your name: ";
    std::string name{ };
    std::getline(std::cin >> std::ws, name);

    std::time_t curr_time{ getTime() };
    // std::setw only applies to the next extraction
    file << std::setw(15) << std::left << name << std::right
         << " was here at " << std::ctime(&curr_time);
}

void read(std::fstream& file)
{
    std::string extract{ };
    while (std::getline(file, extract))
        std::cout << extract << '\n';
}

int main()
{
    std::fstream file{ "test.txt", std::ios::app | std::ios::in };
    if (!file)
    {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    appendRecord(file);
    std::cout << '\n';
    file.seekg(0);
    read(file);

    return 0;
}
