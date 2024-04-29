#include "../stringutils.h"
#include <gtest/gtest.h>

TEST(SplitString, splitInWords)
{
  string s = "this is a test";
  auto tokens = splitInWords(s, ' ');
  EXPECT_EQ(tokens.size(), 4);
  EXPECT_EQ(tokens[0], "this");
  EXPECT_EQ(tokens[1], "is");
  EXPECT_EQ(tokens[2], "a");
  EXPECT_EQ(tokens[3], "test");
}

TEST(SplitString, splitString_commas)
{
  string s = "this,is,a,test";
  auto tokens = splitInWords(s, ',');
  EXPECT_EQ(tokens.size(), 4);
  EXPECT_EQ(tokens[0], "this");
  EXPECT_EQ(tokens[1], "is");
  EXPECT_EQ(tokens[2], "a");
  EXPECT_EQ(tokens[3], "test");
}

TEST(SplitStringParenthesis, onelevel)
{
  string s = "(this)(is a test)";
  auto tokens = splitInParenthesesGroups(s); // -> {"this", "is a test"}
  EXPECT_EQ(tokens.size(), 2);
  if (tokens.size() != 2)
    return;
  EXPECT_EQ(tokens[0], "this");
  EXPECT_EQ(tokens[1], "is a test");
}

TEST(SplitStringParenthesis, twolevel)
{
  string s = "(this)(is (a test))";
  auto tokens = splitInParenthesesGroups(s); // -> {"this", "is (a test)"}
  EXPECT_EQ(tokens.size(), 2);
  if (tokens.size() != 2)
    return;
  EXPECT_EQ(tokens[0], "this");
  EXPECT_EQ(tokens[1], "is (a test)");
}

TEST(SplitStringParenthesis, outofparenthesis)
{
  string s = "this (is)(a test)";
  auto tokens = splitInParenthesesGroups(s); // -> {"is", "a test"}
  EXPECT_EQ(tokens.size(), 2);
  if (tokens.size() != 2)
    return;
  EXPECT_EQ(tokens[0], "is");
  EXPECT_EQ(tokens[1], "a test");
}