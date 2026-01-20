#include <iostream>

struct Employee
{
    int id{ };
    int age{ };
    double wage{ };
};

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    Employee& joeRef{ joe };
    Employee* joePtr{ &joe };

    // member access syntax same for refs as var
    std::cout << "Joe's wage:\t" << joeRef.wage << '\n';

    // ptr needs to be deferenced
    // c++ has arrow operator for this same as c
    std::cout << "Joe's age:\t" << joePtr->age << '\n';

    return 0;
}
