#include "deposit.h"

using namespace std;


void matrix_1(int **a, int n, int m){
	
    Maze(a, n, m);

    a[n-2][m-2] = 0;
    a[n-2][m-3] = 0;
	MazeGenerator(a, n, m, 5, 5);
	for(;;){
		if(StackCell.getTop() > 0){
			MazeSteck(a, n, m);
		}
		else break;
	}
	
	track(a, n, m, 1, 1, n-2, m-2);
	
	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);
    
    StackCell.printStack();
}

void matrix_2(int **a, int n, int m){
	
    Maze(a, n, m);

    a[n-2][m-2] = 0;
    a[n-2][m-3] = 0;
	MazeGenerator(a, n, m, 5, 5);
	for(;;){
		if(StackCell.getTop() > 0){
			MazeSteck(a, n, m);
		}
		else break;
	}
	
	track(a, n, m, 1, 1, n-2, m-2);
	
	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);
    
    StackCell.printStack();
    
    
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i == j) a[i][j] = 0;
		}
		
	}
}
//matrix