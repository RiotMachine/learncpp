// function templates

#include <iostream>

template <typename T>
void divide()
{
    std::cout << "Input a number: ";
    T x{};
    std::cin >> x;

    std::cout << "Input a second number: ";
    T y{};
    std::cin >> y;

    std::cout << x << " divided by " << y << " is " << x / y << '\n';
}

int main()
{
    divide<double>();
    return 0;
}

/*Q1 - Describe why construction blueprints are a type of template.
Construction blueprints are a type of template because they provide the base 
form of an object which will later have 1 or more instantiations.

Alex's:
The construction blueprint itself is just a piece of paper that describes how to construct a building. 
Using the blueprint, construction crews can quickly erect many buildings with an identical structure. 
However, the specific material types used for each building can vary 
(e.g. what type of material is used for the siding of the building), 
and don’t need to be determined until the buildings are actually built.

Not sure I agree that construction materials dont matter, but the metaphor converys.
*/