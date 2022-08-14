#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>
#include <tuple>
#include "expression.h"

   class Parser
{
public:
    explicit Parser(const char* input) : input(input) {};
    Expression parse();

private:
    std::string parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);
    const char* input;
};




