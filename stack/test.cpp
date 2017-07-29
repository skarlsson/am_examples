#include <iostream>
#include <gtest/gtest.h>
#include "stack.h"


TEST(STACK, str) {
  stack<std::string> s({"the", "yogurt", "is", "cursed"});
  EXPECT_EQ(s.size(), (size_t) 4);
  EXPECT_EQ(s.str(), "[the, yogurt, is, cursed]");
}


TEST(STACK, size) {
  stack<int> s(2, 200);
  EXPECT_EQ(s.size(),  (size_t) 2);
  s.push(22);
  EXPECT_EQ(s.size(),  (size_t) 3);
  s.pop();
  EXPECT_EQ(s.size(),  (size_t) 2);
  s.pop();
  EXPECT_EQ(s.size(),  (size_t) 1);
  s.pop();
  EXPECT_EQ(s.size(),  (size_t) 0);
}


TEST(STACK, value) {
  stack<int> s(2, 200);
  s.push(22);
  EXPECT_EQ(s.pop(),  22);
  EXPECT_EQ(s.pop(),  200);
  EXPECT_EQ(s.pop(),  200);
  s.push(22);
  EXPECT_EQ(s.pop(),  22);
  EXPECT_EQ(s.size(),  (size_t) 0);
}


TEST(STACK, reverse) {
  stack<int> s(2, 200);
  s.push(22);
  s.reverse();
  EXPECT_EQ(s.pop(),  200);
  EXPECT_EQ(s.pop(),  200);
  EXPECT_EQ(s.pop(),  22);
  s.push(22);
  EXPECT_EQ(s.pop(),  22);
  EXPECT_EQ(s.size(),  (size_t) 0);
}

TEST(STACK, clear) {
  stack<int> s(2, 200);
  s.push(22);
  EXPECT_EQ(s.size(), (size_t) 3);
  s.clear();
  EXPECT_EQ(s.size(), (size_t) 0);
}


TEST(STACK, reverse_string) {
  stack<std::string> s({"the", "yogurt", "is", "cursed"});
  EXPECT_EQ(s.size(), (size_t) 4);
  s.reverse();
  EXPECT_EQ(s.pop(),  "the");
  EXPECT_EQ(s.pop(),  "yogurt");
  EXPECT_EQ(s.pop(),  "is");
  EXPECT_EQ(s.pop(),  "cursed");
}


