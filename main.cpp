#include "random_example/main_random_example.h"
#include "random_example_optimized/main_random_example.h"

#include <iostream>

int main()
{
    std::cout << random_main_23() << std::endl;
    std::cout << random_main_17() << std::endl;
    std::cout << random_main_c_style() << std::endl;
    std::cout << random_main_23_optimized() << std::endl;
    std::cout << random_main_17_optimized() << std::endl;
    std::cout << random_main_c_style_optimized() << std::endl;
}