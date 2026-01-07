// const pointers & pointers to const
/// pointer to const: non-const pointer pointing to const value
/// const pointer: pointer whose address cannot be changed after initialization

int main()
{
    const int x{ 5 };
    int y{ 6 };

    // Pointer to Const
    // const type* allows you to point to const vars
    // unlike lvalue refs to const, cannot point to rvalues (since they dont
    /// have addresses)
    const int* ptr{ &x };
    ptr = &y;
    // *ptr = 7 not allowed even though y is non-const
    y = 7;
    /// since ptr is const int*

    // Const Pointer
    int* const ptr2{ &y };
    *ptr2 = 7;
    int z{ 8 };
    // ptr2 = &z not allowed since type* const ptr
    /// cannot be reassigned

    // ptr3 cannot change the value it is pointing at nor be reassigned
    const int* const ptr3{ &z };

    return 0;
}
