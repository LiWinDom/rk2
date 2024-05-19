#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Minus : public Interpreter::TerminalExpression_Minus {
  public:
    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (override));
};
