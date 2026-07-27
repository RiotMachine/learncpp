#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade
{
    std::string name{ };
    char grade{ };
};

class GradeMap
{
public:
    char& operator[](std::string_view str)
    {
        auto iterator{ std::find_if(
            m_map.begin(), m_map.end(), [str](const StudentGrade& sg) 
                                        { return sg.name == str; }
        )};
        if (iterator != m_map.end())
            return iterator->grade;
        m_map.push_back(StudentGrade { std::string { str } });
        return m_map.back().grade;
    }

private:
    std::vector<StudentGrade> m_map{ };
};



int main()
{
    GradeMap grades{ };

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}