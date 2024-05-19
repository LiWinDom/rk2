#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Interpreter.cpp"
using Interpreter::Parser;

TEST(Parser, evaluatePlus) {
  auto obj = Parser("1 2 +");
  EXPECT_EQ(obj.evaluate(), 3);
}

TEST(Parser, evaluateMinus) {
  auto obj = Parser("1 2 -");
  EXPECT_EQ(obj.evaluate(), -1);
}

TEST(Parser, evaluateComplex) {
  auto obj = Parser("4 2 - 4 +");
  EXPECT_EQ(obj.evaluate(), 6);
}
