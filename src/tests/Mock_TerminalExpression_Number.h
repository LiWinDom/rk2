#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Number : public Interpreter::TerminalExpression_Number {
  public:
    Mock_TerminalExpression_Number(int number) : TerminalExpression_Number(number) {}

    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (override));
};
