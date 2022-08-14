#include "parser.h"
#include "eval.h"
class Test
{
public:
    int errors = 0;
    void test(const char* input, double expected)
{
    try
    {
        Parser p(input);
        auto result = eval(p.parse(), 0);
        if (result == expected)
        {
            std::cout << input << " = " << result << '\n';
            return;
        }
        std::cout << input << " = " << expected << " : error, got " << result << '\n';
        errors++;
    }
    catch (std::exception& e)
    {
        std::cout << input << " : exception: " << e.what() << '\n';
    }
};
void manual_test()
{
    std::cout << "Manual test. Print q for auto test" << '\n';
    char test[1000];
    gets (test);
    while (test[0]!='q')
    {
        Parser p(test);
        auto result = eval(p.parse(), 0);
        std::cout << test << " = " << result << std::endl;
        gets (test);
    }
}
};


