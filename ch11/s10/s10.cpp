// using function templates in multiple files

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