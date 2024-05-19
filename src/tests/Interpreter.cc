#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <stack>

#include "../Interpreter.cpp"
#include "Mock_TerminalExpression_Minus.h"
#include "Mock_TerminalExpression_Number.h"
#include "Mock_TerminalExpression_Plus.h"

TEST(TerminalExpression_Minus, Mock) {
  Mock_TerminalExpression_Minus obj;
  std::stack<int> s;

  EXPECT_CALL(obj, Interpret(s)).Times(1);
  obj.Interpret(s);
}
