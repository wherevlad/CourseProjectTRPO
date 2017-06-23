#include "deposit.h"
#include "deposit.h"

using namespace std;


int matrix_1(int n, int m){
	int a[n][m], sum = 0;

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(((i % 2 != 0) && (j % 2 != 0)) && ((i < 20-1) && (j < 20-1)))
				a[i][j] = 1;
			else a[i][j] = -1;
			sum = a[i][j];
		}
	}
	return sum;
	/*int sum = n+m;
	return sum;*/
}
//matrix