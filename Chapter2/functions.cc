#include <iostream>
#include <cstdint>

// function definition, the declaration could be anywhere and post the invoker
// void my_print_function();

// function definition + declaration, must be defined before of the invoker fn
void my_print_function(){
    std::cout << "Hello world \n";
}

int main(){
    my_print_function();

    return 0;
}
