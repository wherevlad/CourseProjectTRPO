#include "../thirdparty/ctest.h"
#include "../src/ftest/deposit.c"
#include "../src/ftest/deposit.h"


CTEST(matrix_1, matrix_1_test)
{
    int n = 10, m = 10, i;
    int **a = (int**)malloc(n * sizeof(int*));
    
    for (i=0; i<n; i++)
         a[i] = (int*)malloc(m * sizeof(int));

    matrix_1(a, n, m);

    ASSERT_EQUAL(a[1][1], -2);
    ASSERT_EQUAL(a[n-2][m-2], -2);

    for(i=0; i<n; i++)
        free(a[i]);
    free(a);
}


CTEST(matrix_2, matrix_2_test)
{
    int n = 10, m = 10, i;
    int **a = (int**)malloc(n * sizeof(int*));
    
    for (i=0; i<n; i++)
         a[i] = (int*)malloc(m * sizeof(int));

    matrix_2(a, n, m);
    

    ASSERT_EQUAL(a[1][1], -1);
    ASSERT_EQUAL(a[n-2][m-2], -1);

    for(i=0; i<n; i++)
        free(a[i]);
    free(a);
}
