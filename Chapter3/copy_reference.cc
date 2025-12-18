#include <array>
#include <cstdint>
#include <iostream>

// c++-style arays - & to make it by reference (Represent the memory address)
template <std::size_t N>
// pass by reference input only if the data type is less than 8bytes (use const keyword for input only)
void print_array_values(const std::array<uint32_t, N>& my_array)
{
    for(std::uint32_t i = 0; i < my_array.size(); i++){
        std::cout << my_array[i] << "\n";
    }
}

// c++-style arays - & to make it by reference (Represent the memory address)
template <std::size_t N>
// in and out (parameter), no const, but reference
void double_value(std::array<uint32_t, N>& my_array)
{
    for(std::uint32_t i = 0; i < my_array.size(); i++){
        my_array[i] = my_array[i] * 2;
    }
}

int main()
{
    auto my_array2 = std::array<std::uint32_t, 5U>{1,2,3,4,5};
    std::cout << &my_array2 << "\n";
    print_array_values(my_array2);
    double_value(my_array2);
    print_array_values(my_array2);

    return 0;
}
