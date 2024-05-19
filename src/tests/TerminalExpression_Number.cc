#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Interpreter.cpp"

TEST(TerminalExpression_Number, Interpret) {
  int number = 1;
  std::stack<int> stack;
  stack.push(number);

  Interpreter::TerminalExpression_Number obj(number);
  std::stack<int> s;
  EXPECT_NO_THROW(obj.Interpret(s));

  EXPECT_EQ(stack, s);
}
