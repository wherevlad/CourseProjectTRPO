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
/*
CTEST(main2, main2_test)
{
	int a[20][20];
	int b[n][m];

	Maze(b, n, m);

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(((i % 2 != 0) && (j % 2 != 0)) && ((i < 20-1) && (j < 20-1)))
				a[i][j] = 1;
			else a[i][j] = -1;
		}
	}

	int a[1] = {0};
	int b[1] = {1};
	int n = 1;
	ASSERT_DATA(a, n, b, n);
}*/
