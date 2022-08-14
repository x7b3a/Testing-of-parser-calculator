double eval(const Expression& e, int fun)
{
    int i=0;
    switch (e.args.size())
    {
    case 2:
    {
        auto a = eval(e.args[0], 0);
        auto b = eval(e.args[1], 0);
        if (e.token == "+")
            return a + b;
        if (e.token == "-")
            return a - b;
        if (e.token == "*")
            return a * b;
        if (e.token == "/")
            return a / b;
        if (e.token == "){")
                return a?b:a;
        if (e.token == "^")
            return pow(a, b);
        if (e.token == "mod")
            return (int)a % (int)b;
        throw std::runtime_error("Unknown binary operator");
    }
    case 1:
    {
        auto a = eval(e.args[0], 0);
        if (e.token == "+")
            return +a;
        if (e.token == "-")
            return -a;
        if (e.token == "sin")
            return sin(a);
        if (e.token == "abs")
            return abs(a);
        if (e.token == "sin")
            return sin(a);
        if (e.token == "cos")
            return cos(a);
        if (e.token == "tg")
            return tan(a);
        if (e.token == "ctg")
            return cos(a)/sin(a);
        if (e.token == "for")
            if (a){for (int i = 0; i < a; i++)  printf ("Iteration %d\n",i+1); return a;} else return a; //результат - число итераций
            if (e.token == "while") {if (a) while(1) printf ("Iteration %d\n",++i); else return a;};
        throw std::runtime_error("Unknown unary operator");
    }
    case 0:
        return strtod(e.token.c_str(), nullptr);
    }

    throw std::runtime_error("Unknown expression type");
}
