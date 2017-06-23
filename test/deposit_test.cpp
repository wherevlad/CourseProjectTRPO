#include <iostream>

using namespace std;

#include "../thirdparty/ctest.h"
#include "../src/deposit.cpp"
#include "../src/deposit.h"

CTEST(matrix_1, matrix_1_test)
{
    int sum = 0;

    int **b = new int *[N]; // Выделение памяти для массива
    
    for (int i=0; i<N; i++)
         b[i] = new int [M];

    Maze(b, N, M);

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			sum = b[i][j];
		}
	}

    int expected = sum;
    int result = matrix_1(20, 20);
    ASSERT_EQUAL(expected, result);
}


#include "../src/functio.h"