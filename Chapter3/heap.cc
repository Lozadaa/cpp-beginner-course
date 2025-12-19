#include <array>
#include <cstdint>
#include <iostream>

int main()
{
    // Stack variables and memory flow
    const auto len = std::size_t{5};
    std::uint32_t my_stack_variable[len] = {1,2,3,4,5};


    // Heap variables and memory flow
    auto len2 = std::size_t{};
    std::cout << "Write any number" << "\n";
    std::cin >> len2;

    std::uint32_t* my_heap_variable = new std::uint32_t[len2]; 
    
    if(my_heap_variable){
        for(std::size_t i = 0; i < len2; i++){
            my_heap_variable[i] = i;
        }

        for(std::size_t i = 0; i < len2; i++){
            std::cout << my_heap_variable[i] << '\n';
        }
    }

    // clean up and free up memory
    delete[] my_heap_variable;
    my_heap_variable = nullptr;

    return 0;
}
