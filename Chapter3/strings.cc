#include <array>
#include <cstdint>
#include <iostream>
#include <string>


int main(){
    char single_character = 'a';
    char my_text1[] = "Richard";
    char my_text2[] = {'R', 'i', 'c', 'h', 'a', 'r', 'd', '\0'};
    auto my_text3 = std::array<char, 8>{'R', 'i', 'c', 'h', 'a', 'r', 'd'};

    auto my_text4 = std::string{"Richard"};
    std::cout << my_text4.size() << '\n';
    my_text4.append(" Lozada");
    std::cout << my_text4.size() << '\n';

    // Whats used in modern c++?
    // my_text1
    // my_text4

    return 0;
}
