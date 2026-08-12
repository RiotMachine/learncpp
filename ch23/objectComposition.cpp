/*
  Composition && Aggregation
    composition - manages parts' lifetimes
    aggregation - does not
    use simplest form that meets app needs
    composition is simpler than aggregation

    more likely members of a
      composition
        color of a ball
        my age
        the departments in a university
      aggregation
        employee of a particular employer
        marbles in a particular bag
*/

#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher
{
public:
    Teacher(std::string_view name)
      :  m_name{ name } {}

    const std::string& getName() const { return m_name; }

private:
    std::string m_name{ };
};

class Department
{
public:
    Department(std::string_view sv)
      : m_name{ sv } {}

    void add(const Teacher& t) { m_roster.emplace_back(t); }

    friend std::ostream& operator<<(std::ostream& out, const Department& dept)
    {
        out << dept.m_name << " Dept:\n";
        for (const auto& e : dept.m_roster)
            out << e.get().getName() << '\n';
        return out;
    }

private:
    using Roster = std::vector<std::reference_wrapper<const Teacher>>;

    Roster m_roster;
    std::string m_name;
};

int main()
{
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        Department department{ "English" };
        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department << '\n';
    }

    std::cout << t1.getName() << ", " << t2.getName() << ", and "
              << t3.getName() << " still exist.\n";

    return 0;
}
