/*
What type of conversion happens in each of the following cases? 
Valid answers are: No conversion needed, numeric promotion, numeric conversion, won’t compile due to narrowing conversion. 
Assume int and long are both 4 bytes.
*/

#include <iostream>

int main()
{
    int a { 5 };        // No conversion needed
    int b { 'a' };      // numeric promotion
    //int c { 5.4 };       wont compile due to narrowing conversion
    int d { true };     // numeric promotion
    int e { static_cast<int>(5.4) }; // numeric conversion, narrowing allowed since explicit

    double f { 5.0f };  // numeric promotion
    double g { 5 };     // numeric conversion, not narrowing since 5 is constexpr and in double's range

    // Extra credit section
    long h { 5 };       // numeric conversion - not all widening conversions are considered promotions

    float i { f };      // narrowing conversion since f is double and not constexpr; 
                        // but only throws warning whereas int c { 5.4 } throws error
    float j { 5.0 };    // numeric conversion, not narrowing since 5.0 is constexpr and in float's range

    return 0 ;
}