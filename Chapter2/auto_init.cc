#include <iostream>
#include <cstdint>

// AAA: Almost Always Auto
// DRY: Don't repeat Yourself
int main()
{

    // implicit conversions are bad. Other people will ask to himself Is this a Bug? or intencionally?
    float a = 10.5; // implicity converted
    std::int32_t b = a; // implicity converted

    // explicity converted
    auto c = static_cast<std::int32_t>(a);

    // Uniform initialization depends on Msv config of the project could fail
    // auto d = std::int32_t{a}; // Throw error by compiler
    auto e = std::int32_t{}; // Uniform init using default value of datatype

    auto f = 10 + 10.5; // Resolves in a double because c++ prefers the bigger, claude explain this better please

    return 0;
}
