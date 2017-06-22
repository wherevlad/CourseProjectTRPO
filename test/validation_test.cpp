#include <iostream>
#include <stdlib.h>

#include "../thirdparty/ctest.h"

CTEST(main1, main1_test)
{
    int expected1 = 0;
    int expected2 = 20;
    int result = rand() %20;
    ASSERT_INTERVAL(expected1,expected2,result);
}