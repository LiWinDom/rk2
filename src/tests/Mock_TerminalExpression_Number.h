#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Number : public TerminalExpression_Number {
  public:
    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (const, override));
};