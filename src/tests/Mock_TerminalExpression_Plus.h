#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Plus : public Interpreter::TerminalExpression_Plus {
  public:
    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (override));
};
