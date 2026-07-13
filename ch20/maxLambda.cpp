#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student
{
    std::string name{ };
    int points{ };
};


int main()
{
    constexpr int MAX_STUDENT{ 8 };

    // cant be constexpr bcause of std::string member
    const std::array students{
        Student { "Albert",    3 },
        Student { "Ben",       5 },
        Student { "Christine", 2 },
        Student { "Dan",       8 },
        Student { "Enchilada", 4 },
        Student { "Francis",   1 },
        Student { "Greg",      3 },
        Student { "Hagrid",    5 }
    };
    static_assert(students.size() == MAX_STUDENT);

    const auto maxStudent{ std::max_element(students.begin(), students.end(), 
        [](const Student& s1, const Student& s2) {
            return s1.points < s2.points;
        })
    };

    std::cout << maxStudent -> name << " is the best student\n";

    return 0;
}