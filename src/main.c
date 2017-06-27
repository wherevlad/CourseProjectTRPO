#include "deposit.h"
#include "deposit.c"

int main()
{
	srand ( time(NULL) );

    int n = 10, m = 10, i, j;
    int x = 5, y = 5;
    
    int b[10][10] = {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
		-1,  0,  0,  0, -1,  0,  0,  0, -1, -1, 
		-1,  0, -1,  0, -1,  0, -1,  0, -1, -1, 
		-1,  0, -1,  0, -1,  0, -1,  0, -1, -1, 
		-1,  0, -1,  0, -1, -1, -1,  0, -1, -1, 
		-1,  0, -1,  0,  0,  0, -1,  0, -1, -1, 
		-1,  0, -1, -1, -1, -1, -1,  0, -1, -1, 
		-1,  0,  0,  0,  0,  0,  0,  0, -1, -1, 
		-1, -1, -1, -1, -1, -1, -1,  0,  0, -1, 
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1 
    };


    int **a = (int**)malloc(n * sizeof(int*));
    
    for (i=0; i<n; i++)
         a[i] = (int*)malloc(m * sizeof(int));

    for (i = 0; i < n; i++){
    	for (j = 0; j < m; j++){
    		a[i][j] = b[i][j];
    	}
    }

	track(a, n, m, 1, 1, n-2, m-2);
	

	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);

    PrintMas(a, n, m);
    

    for(i=0; i<n; i++)
        free(a[i]);
    free(a);

    return 0;
}
