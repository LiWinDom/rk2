#include <stack>
#include <vector>

// Interpreter namespace
namespace Interpreter {
    class Expression {
    public:
        virtual void Interpret(std::stack<int>& s) = 0;
    };

    class TerminalExpression_Number : public Expression {
    private:
        int number;
    public:
        TerminalExpression_Number(int number) : number(number) {}

        void Interpret(std::stack<int>& s) override {
            s.push(number);
        }
    };

    class TerminalExpression_Plus : public Expression {
    public:
        void Interpret(std::stack<int>& s) override {
            int x = s.top(); s.pop();
            int y = s.top(); s.pop();
            s.push(x + y);
        }
    };

    class TerminalExpression_Minus : public Expression {
    public:
        void Interpret(std::stack<int>& s) override {
            int x = s.top(); s.pop();
            int y = s.top(); s.pop();
            s.push(y - x);
        }
    };

    class Parser {
    private:
        std::vector<Expression*> parseTree;
    public:
        Parser(std::string s) {
            size_t pos = 0;
            std::string token;
            while ((pos = s.find(" ")) != std::string::npos) {
                token = s.substr(0, pos);
                s.erase(0, pos + 1);

                if (token == "+") {
                    parseTree.push_back(new TerminalExpression_Plus());
                }
                else if (token == "-") {
                    parseTree.push_back(new TerminalExpression_Minus());
                }
                else {
                    parseTree.push_back(new TerminalExpression_Number(std::stoi(token)));
                }
            }

            // Add the last token
            if (!s.empty()) {
                if (s == "+") {
                    parseTree.push_back(new TerminalExpression_Plus());
                }
                else if (s == "-") {
                    parseTree.push_back(new TerminalExpression_Minus());
                }
                else {
                    parseTree.push_back(new TerminalExpression_Number(std::stoi(s)));
                }
            }
        }

        int evaluate() {
            std::stack<int> context;

            for (auto e : parseTree) {
                e->Interpret(context);
            }

            return context.top();
        }

        ~Parser() {
            // Free memory allocated for Expressions
            for (auto e : parseTree) {
                delete e;
            }
        }
    };

    class Program {
    public:
        static void Main() {
            std::string expression = "4 4 2 - +";
            Parser p(expression);
            std::cout << "'" << expression << "' equals " << p.evaluate() << std::endl;
        }
    };
}
