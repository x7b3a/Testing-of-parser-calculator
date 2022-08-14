#include "parser.h"

std::string Parser::parse_token()
{
    while (std::isspace(*input))
        ++input;

    if (std::isdigit(*input))
    {
        std::string number;
        while (std::isdigit(*input) || *input == '.')
            number.push_back(*input++);
        return number;
    }

    static const std::string tokens[] =
    { "+", "-", "^", "*", "/", "cos", "sin", "abs", "mod", "tg", "if(","ctg","(", "){", ")","}", "while", "for"};
    for (auto& t : tokens)
    {
        if (std::strncmp(input, t.c_str(), t.size()) == 0)
        {
            input += t.size();
            return t;
        }
    }


    return "";
}

Expression Parser::parse_simple_expression()
{

    auto token = parse_token();
    //printf("\n simp token = %s\n", token.c_str());
    if (token.empty())
        throw std::runtime_error("Invalid input");
 if (token == "for")//parsing for arguments, calculating amount of iterations
    {
        input++;
        auto beginning = parse_token();
        input++;
        auto ending = parse_token();
        input++;
        auto step = parse_token();
        if (!atoi(step.c_str()))
        {
            return Expression(token,std::to_string(atoi(step.c_str())));
        };
        return Expression(token, std::to_string(((atol(ending.c_str())-atol(beginning.c_str()))/atol(step.c_str()))+1));
    }
    if (token == "("||token == "if(" )
    {
        auto result = parse();
        auto temp = parse_token();
        if (temp != ")"&&temp != "}"&&temp!= "){")
            throw std::runtime_error("Expected ')'");
        return result;
    }
    if (std::isdigit(token[0]))
        return Expression(token);

    return Expression(token, parse_simple_expression());
}

int get_priority(const std::string& binary_op)
{
    if (binary_op == "){")
        return 1;
    if (binary_op == "+")
        return 2;
    if (binary_op == "-")
        return 2;
    if (binary_op == "*")
        return 3;
    if (binary_op == "/")
        return 3;
    if (binary_op == "mod")
        return 3;
    if (binary_op == "^")
        return 4;

    return 0;
}

Expression Parser::parse_binary_expression(int min_priority)
{
    auto left_expr = parse_simple_expression();

    for (;;)
    {
        auto op = parse_token();
        //printf("\nbin token = %s\n", op.c_str());
        auto priority = get_priority(op);
        if (priority <= min_priority)
        {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse()
{
    return parse_binary_expression(0);
}

