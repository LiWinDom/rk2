#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Interpreter.cpp"
#include "Mock_TerminalExpression_Number.h"
#include "Mock_TerminalExpression_Plus.h"
#include "Mock_TerminalExpression_Minus.h"

TEST(TerminalExpression_Number, Mock) {
  Mock_TerminalExpression_Number obj(0);
  std::stack<int> s;

  EXPECT_CALL(obj, Interpret(s)).Times(1);
  obj.Interpret(s);
}

TEST(TerminalExpression_Plus, Mock) {
  Mock_TerminalExpression_Plus obj;
  std::stack<int> s;

  EXPECT_CALL(obj, Interpret(s)).Times(1);
  obj.Interpret(s);
}

TEST(TerminalExpression_Minus, Mock) {
  Mock_TerminalExpression_Minus obj;
  std::stack<int> s;

  EXPECT_CALL(obj, Interpret(s)).Times(1);
  obj.Interpret(s);
}
