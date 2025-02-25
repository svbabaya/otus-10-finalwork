cmake_minimum_required(VERSION 3.8)

project(otus_final_work CXX)

include(FetchContent)

FetchContent_Declare(
    googletest 
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG v1.16.0
    )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.1.3
    )
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    cli11_proj
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
    )
FetchContent_MakeAvailable(cli11_proj)

file(GLOB proj_sources src/*.cpp)
file(GLOB test_sources test/*.cpp)

add_executable(
    duc 
    ${proj_sources}
    )

add_executable(
    duc_test 
    ${test_sources}
    )

target_include_directories(
    duc_test
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )

target_link_libraries(
    duc_test 
    GTest::gtest_main
    )

target_link_libraries(
    duc 
    fmt::fmt
    CLI11::CLI11
    )

set_target_properties(duc PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(duc_test PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        duc PRIVATE 
        /W4
    )
    target_compile_options(
        duc_test PRIVATE 
        /W4
    )
else ()
    target_compile_options(
        duc PRIVATE 
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
    )
    target_compile_options(
        duc_test PRIVATE 
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
    )
endif ()
