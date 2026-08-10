#include <iostream>
#include <memory>

class Resource
{
public:
    Resource()  { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }

    std::weak_ptr<Resource> m_ptr{ };
};

int main()
{
    auto ptr1{ std::make_shared<Resource>() };
    ptr1->m_ptr = ptr1;

    return 0;
}
