#include <iostream>
#include <cstdint>

void print_my_number(std::uint32_t number){
    std::cout << number << "\n";
}
// Templates functions son buena forma de evitar tener que escribir
// dos veces este body de la funcion
void print_my_number(double number){
    std::cout << number << "\n";
}

int main(){
    print_my_number(12345679U);
    print_my_number(12.4);

    return 0;
}
