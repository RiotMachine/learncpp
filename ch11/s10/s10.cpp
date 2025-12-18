// using function templates in multiple files
/// define templates in header file then include them wherever
/// doesnt violate ODR since implicit function instantiations are 
//// implicitly inline && coming from one source of truth
//// definitions with the same name and types are identical

#include "s10.h"

void foo();

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // factorial<-3>(); // should fail to compile

    foo();

    return 0;
}