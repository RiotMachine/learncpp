int main()
{
    int x{ };

    // commenting out statements that wont compile

    int& ref1{ x };
    // int& ref2{ 5 };

    const int& ref3{ x };
    const int& ref4{ 5 };

    // int&& ref5{ x };
    int&& ref6{ 5 };

    // const int&& ref7{ x };
    const int&& ref8{ 5 };

    return 0;
}
