#include <gtest/gtest.h>
#include <string>

#include "./lis.h"

TEST(SplitStrTest, SplitStr1) {
  auto input = std::string("hello world");
  std::vector<std::string> expected;
  expected.push_back(std::string("hello"));
  expected.push_back(std::string("world"));
  auto actual = split_str(input);

  for (int i = 0; i < expected.size(); i++) {
    EXPECT_STREQ(expected[i].c_str(), actual[i].c_str());
  }
}

TEST(SplitStrTest, SplitStr2) {
  auto input = std::string("   nice day !  ");
  std::vector<std::string> expected;
  expected.push_back(std::string("nice"));
  expected.push_back(std::string("day"));
  expected.push_back(std::string("!"));
  auto actual = split_str(input);

  for (int i = 0; i < expected.size(); i++) {
    EXPECT_STREQ(expected[i].c_str(), actual[i].c_str());
  }
}

TEST(TokenizeTest, Tokenize) {
  auto input = std::string("(- 3 4)");
  std::vector<std::string> expected;
  expected.push_back(std::string("("));
  expected.push_back(std::string("-"));
  expected.push_back(std::string("3"));
  expected.push_back(std::string("4"));
  expected.push_back(std::string(")"));
  auto actual = tokenize(input);

  for (std::size_t i = 0; i < expected.size(); i++) {
    EXPECT_STREQ(expected[i].c_str(), actual[i].c_str());
  }
}
