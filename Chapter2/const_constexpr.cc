#include <iostream>
#include <cstdint>

// 5! = 5 * 4 * 3 * 2 * 1
// const: read only input
constexpr std::uint64_t faculty(const std::uint8_t n)
{
    auto result = std::uint64_t{1};

    for (std::uint8_t i = 1; i <= n; i++){
        result *= i;
    }

    return result;
}

int main()
{
    // const - run time (only for integers may be compile time)
    // constexpr (c++ 17) - compile and runtime

    const auto result = faculty(5);
    constexpr auto result2 = faculty(5);

    return 0;
}
