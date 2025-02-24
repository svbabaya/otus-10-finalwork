#include "globals.hpp"

#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <CLI/CLI.hpp>

#include <indicators/progress_bar.hpp>
#include <thread>
#include <chrono>

int main(int argc, char** argv) {

    CLI::App app{"Data Review Client (dac), a command line client"};
    app.require_subcommand(1);

    std::cout << "Hi, final project!" << '\n';
    std::cerr << "Hi, errors!" << '\n';

    fmt::print("The answer is {}\n", 42);

    std::string s = "Abc\n";
    fmt::print(fg(fmt::color::red), s); 

    using namespace indicators;
    ProgressBar bar{
        option::BarWidth{50},
        option::Start{"["},
        option::Fill{"="},
        option::Lead{">"},
        option::Remainder{" "},
        option::End{"]"},
        option::PostfixText{"Extracting Archive"},
        option::ForegroundColor{Color::green},
        option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
    };
  
    // Update bar state
    while (true) {
        bar.tick();
        if (bar.is_completed())
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Add new options/flags here

    CLI11_PARSE(app, argc, argv);
    
    std::cout << "\nThanks for using dac!\n" << std::endl;
    return 0;
}
