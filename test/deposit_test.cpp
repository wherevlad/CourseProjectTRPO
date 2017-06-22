#include <iostream>

using namespace std;

#include "../thirdparty/ctest.h"
#include "../src/deposit.cpp"

CTEST(one, one_test)
{
    int a = 20;
    int b = 20;
    int expected = a+b ;
    int result = one(b,a);
    ASSERT_EQUAL(expected, result);
}