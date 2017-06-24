#include <iostream>
#include <stdlib.h>

#include "../thirdparty/ctest.h"

CTEST(main1, main1_test)
{
	int expected1 = 8;
	int expected2 = 20;
	int result = rand() %12 + 8;
	ASSERT_INTERVAL(expected1,expected2,result);
}

CTEST(main2, main1_test)
{
	int expected1 = 8;
	int expected2 = 20;
	int result = 30;
	ASSERT_INTERVAL(expected1,expected2,result);
}
