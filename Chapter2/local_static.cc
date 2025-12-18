#include <iostream>
#include <cstdint>

// static
// local variables
// global variables
// member variables of a class
// member functions of a class


std::uint64_t faculty(const std::uint8_t n)
{
    static std::uint32_t counter = std::uint64_t{1}; // compiled time variable
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++){
        result *= i;
    }

    // just an example
    //++counter;
    //std::cout << "Counter: " << counter << "\n";

    return result;
}

int main()
{
    const auto result = faculty(5); // counter is initialized in compiled time
    auto result2 = faculty(5); // counter is not reinitialized

    return 0;
}
