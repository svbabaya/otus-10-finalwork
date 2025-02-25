#include "globals.hpp"

#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <CLI/CLI.hpp>

int main(int argc, char** argv) {

    CLI::App app{"Data Review Client (dac), a command line client"};
    app.require_subcommand(1);

    std::cout << "Hi, final project!" << '\n';
    std::cerr << "Hi, errors!" << '\n';

    fmt::print("The answer is {}\n", 42);

    std::string s = "Abc\n";
    fmt::print(fg(fmt::color::red), s); 


    // Add new options/flags here

    CLI11_PARSE(app, argc, argv);
    
    std::cout << "\nThanks for using dac!\n" << std::endl;
    return 0;
}
