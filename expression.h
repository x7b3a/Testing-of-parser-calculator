#include <iostream>

struct Expression
{
    Expression(std::string token) : token(token) {}
    Expression(std::string token, Expression a) : token(token), args{ a } {}
    Expression(std::string token, Expression a, Expression b) : token(token), args{ a, b } {}

    std::string token;
    std::vector<Expression> args;
};
