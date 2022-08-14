#include "test.h"
#include <iostream>
#include <string>
#include <stdlib.h>
int main()
{
    Test test;
    test.manual_test();
    std::cout << "Results:" << '\n';
    test.test("if(2^8){500+200*2}",900);
    test.test("if(24*0){900}",0);
    test.test("if(0){777}",0);
    test.test("if(sin(0)){900}",0);
    test.test("sin(0)", 0);
    test.test("cos(0)", 1);
    test.test("2.4+1.6",4);
    test.test("2,4+1,6",4);
    test.test("2.4+1,6",4);
    test.test("-0+0",0);
    test.test("-2147483647-1",-2147483648);
    test.test("-2147483647-2",-2147483649);
    test.test("2147483647+1",2147483648);
    test.test("11111111",11111111);
    std::cout << "Done with " << test.errors << " errors.\n";
    system("PAUSE");
}
