#include <iostream>
#include <cstdint>

int main() {
    for(std::uint32_t i = 0U; i < 3U; i++){
        std::cout << i << "\n";
    }

    for(std::uint32_t i = 0U; i < 3U; ++i){
        std::cout << i << "\n";
    }

    for(std::uint32_t i = 3U; i > 0U; i--){
        std::cout << i << "\n";
    }

    for(std::uint32_t i = 3U; i > 0U; --i){
        std::cout << i << "\n";
    }

    // Explicación del post y pre increment/decrement
    // Basicamente el pre increment se ejecuta en el momento que se lee
    // El post decrement se hace al finalizar la lectura de esa sentencia
    // Ejemplo:

    std::int32_t i = 1;
    std::int32_t result = i++; // Si yo hago esto, result será igual a 1 por que
                               // el post increment se ejecuta al final despues de la asignación
    // ========================
    std::int32_t result2 = ++i; // En cambio aquí, i se aumenta +1 antes de asignarselo a result2
                                // como ya el post increment se ejecutó result2 será 3 2+1 (1 de pre increment)

    std::cout << "\nPost Increment: " << result << "\n" << "Pre Increment: " << result2 << "\n";

    // While
    while(true){
        if(i > 3){
            break;
        }

        i++;
    }

    // do while
    do {
         if(i > 3){
            break;
         }

         i++;
    } while (true);

    return 0;
}
