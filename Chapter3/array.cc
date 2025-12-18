#include <array>
#include <cstdint>
#include <iostream>

// C-style array decays to a pointer when passed into a func
void print_array_values1(const std::uint32_t my_array[], const std::uint32_t len)
{
    for(std::uint32_t i = 0; i < len; i++){
        std::cout << my_array[i] << "\n";
    }
}


// c++-style arays
template <std::size_t N>
void print_array_values2(const std::array<uint32_t, N> my_array)
{
    for(std::uint32_t i = 0; i < my_array.size(); i++){
        std::cout << my_array[i] << "\n";
    }
}


int main()
{
    constexpr auto len = 5U;
    std::uint32_t my_array[len] = {};

    print_array_values1(my_array, len);

    auto my_array2 = std::array<std::uint32_t, len>{1,2,3,4,5};
    print_array_values2(my_array2);

    std::array<std::uint32_t, 8U> my_array3 = std::array<std::uint32_t, 8U>{1,2,3,4,5,6,7,8};
    print_array_values2(my_array3);

    return 0;
}
