#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Interpreter.cpp"

TEST(TerminalExpression_Minus, Interpret) {
  std::stack<int> stack;
  stack.push(1);

  Interpreter::TerminalExpression_Minus obj;
  std::stack<int> s;
  s.push(2);
  s.push(1);
  EXPECT_NO_THROW(obj.Interpret(s));

  EXPECT_EQ(stack, s);
}
