#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Minus : public TerminalExpression_Minus {
  public:
    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (const, override));
};
