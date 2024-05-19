#pragma once
#include <gmock/gmock.h>

class Mock_TerminalExpression_Plus : public TerminalExpression_Plus {
  public:
    MOCK_METHOD((void), Interpret, (std::stack<int>& s), (const, override));
};
