#include "globals.hpp"

#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
// #include <CLI/CLI.hpp>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main(int argc, char** argv) {

    // CLI::App app{"Data Review Client (duc), a command line client"};
    // app.require_subcommand(1);

    // std::cout << "Hi, final project!" << '\n';
    // std::cerr << "Hi, errors!" << '\n';

    // fmt::print("The answer is {}\n", 42);

    // std::string s = "Abc\n";
    // fmt::print(fg(fmt::color::red), s); 




    auto fileStream = std::make_shared<ostream>();

    // Open stream to output file.
    pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
    {
        *fileStream = outFile;

        // Create http_client to send the request.
        http_client client(U("http://www.bing.com/"));

        // Build request URI and start the request.
        uri_builder builder(U("/search"));
        builder.append_query(U("q"), U("cpprestsdk github"));
        return client.request(methods::GET, builder.to_string());
    })

    // Handle response headers arriving.
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());

        // Write response body into the file.
        return response.body().read_to_end(fileStream->streambuf());
    })

    // Close the file stream.
    .then([=](size_t)
    {
        return fileStream->close();
    });

    // Wait for all the outstanding I/O to complete and handle any exceptions
    try
    {
        requestTask.wait();
    }
    catch (const std::exception &e)
    {
        printf("Error exception:%s\n", e.what());
    }


    // Add new options/flags here

    // CLI11_PARSE(app, argc, argv);
    
    // std::cout << "\nThanks for using dac!\n" << std::endl;
    return 0;
}
