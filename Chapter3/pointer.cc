#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    auto my_age = std::uint32_t{30U}; // 0x16d5c6c28: 30
    std::cout << &my_age << "\n";

    std::uint32_t *pointer = &my_age; // 0x16d5c6c20: 0x16d5c6c28
    std::cout << &pointer << "\n";

    *pointer = 32U;
    std::cout << my_age << "\n";

    return 0;
}
