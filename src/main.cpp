#include "globals.hpp"

#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>

int main() {
    std::cout << "Hi, final project!" << '\n';
    std::cerr << "Hi, errors!" << '\n';

    fmt::print("The answer is {}\n", 42);

    std::string s = "Abc\n";
    fmt::print(fg(fmt::color::red), s);  

}
