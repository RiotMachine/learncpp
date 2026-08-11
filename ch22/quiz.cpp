/*
  Smart pointers
    #include <memory>
    std::unique_ptr - unique resource ownership; almost-always
    std::shared_ptr - shared resource ownership; sometimes
    std::weak_ptr   - resource access; viewing a shared_ptr's resource
    std::auto_ptr   - never
*/

/*
  Move constructor && move assignment
    utilize r-value references - safe to move from soon-dying objects
    returned auto-duration l-values also get these move semantics
*/

#include <iostream>
#include <memory>

class Resource
{
public:
    Resource()  { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto res{ std::make_shared<Resource>() };
    std::shared_ptr<Resource> ptr1{ res };
    std::shared_ptr<Resource> ptr2{ res };

    return 0;
}

