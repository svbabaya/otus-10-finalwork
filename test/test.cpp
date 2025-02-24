#include "globals.hpp"
#include <gtest/gtest.h>

TEST(vars, equal) {
    int a{0};
    int b{10};
    int expected{0};
    int actual = a * b + 1;
    ASSERT_EQ(expected, actual);
}
