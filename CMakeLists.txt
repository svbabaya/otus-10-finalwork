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

file(GLOB proj_sources src/*.cpp)
file(GLOB test_sources test/*.cpp)

add_executable(
    main 
    ${proj_sources}
    )

add_executable(
    main_test 
    ${test_sources}
    )

target_include_directories(
    main_test 
    PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )

target_link_libraries(
    main_test 
    GTest::gtest_main
    )

target_link_libraries(
    main 
    fmt::fmt
    )

set_target_properties(main PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(main_test PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(
        main PRIVATE 
        /W4
    )
    target_compile_options(
        main_test PRIVATE 
        /W4
    )
else ()
    target_compile_options(
        main PRIVATE 
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
    )
    target_compile_options(
        main_test PRIVATE 
        -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion
    )
endif ()