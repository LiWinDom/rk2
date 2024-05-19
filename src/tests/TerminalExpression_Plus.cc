#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Interpreter.cpp"

TEST(TerminalExpression_Plus, Interpret) {
  std::stack<int> stack;
  stack.push(3);

  Interpreter::TerminalExpression_Plus obj;
  std::stack<int> s;
  s.push(2);
  s.push(1);
  EXPECT_NO_THROW(obj.Interpret(s));

  EXPECT_EQ(stack, s);
}
