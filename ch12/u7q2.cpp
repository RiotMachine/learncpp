int v1{ 45 };
int* ptr{ &v1 };

int v2{ 78 };
ptr = &v2;
// *ptr = &v2 would be trying to assign the address of
/// v2 as the value of the int v1
