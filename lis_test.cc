#include <gtest/gtest.h>
#include "lis.h"

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");

    EXPECT_EQ(8+5, 13);
}
