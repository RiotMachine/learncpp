#include <iostream>

class Point3d
{
private:
    int m_x{ };
    int m_y{ };
    int m_z{ };

    bool isEqual(const Point3d& p) const
    {
        return (m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z);
    }

public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() const
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }

    void printIsEqual(const Point3d& p) const
    {
        std::cout << (isEqual(p) ? "" : " not") << " equal\n";
    }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point2{ };
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are";
    point.printIsEqual(point2);

    Point3d point3{ };
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are";
    point.printIsEqual(point3);

    return 0;
}
