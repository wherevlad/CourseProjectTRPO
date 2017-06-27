#ifndef FUNCTIO_H
#define FUNCTIO_H

void matrix_1(int **a, int n, int m){
	int i, j;
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

    for (i = 0; i < n; i++){
    	for (j = 0; j < m; j++){
    		a[i][j] = b[i][j];
    	}
    }
	
	track(a, n, m, 1, 1, n-2, m-2);
	
	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);

}


int way(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final){ 
	int d = a[x_Final][y_Final];

	a[x_Final][y_Final] = -2;

				
	if((x_Final+1 < n) && (a[x_Final+1][y_Final] == d - 1))
			way(a, n, m, x_Primary, y_Primary, x_Final+1, y_Final);
			
	else if((x_Final-1 >= 0) && (a[x_Final-1][y_Final] == d - 1))
			way(a, n, m, x_Primary, y_Primary, x_Final-1, y_Final);
		
	else if((y_Final-1 >= 0) && (a[x_Final][y_Final-1] == d - 1))
			way(a, n, m, x_Primary, y_Primary, x_Final, y_Final-1);
		
	else if((y_Final+1 < m) && (a[x_Final][y_Final+1] == d - 1))
			way(a, n, m, x_Primary, y_Primary, x_Final, y_Final+1);
	return 0;
}




void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final){ 
	int d = 1, x = x_Primary, y = y_Primary; 
	int i, j; 
	a[x][y] = d; 
	
	d++;
	for(;;){
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				if(a[i][j] == -1) continue; 

				if(a[i][j] > 0){
					if(i+1 < n){ 
						d = a[i][j] + 1; 
						if(a[i+1][j] < d && a[i+1][j] != -1 && a[i+1][j] == 0){
							a[i+1][j] = d; 
						}

					} 



					if(i-1 < n){ 
						d = a[i][j] + 1; 
						if(a[i-1][j] < d && a[i-1][j] != -1 && a[i-1][j] == 0){
							a[i-1][j] = d; 
						}
					} 



					if(j-1 >= 0){ 
						d = a[i][j] + 1; 
						if(a[i][j-1] < d && a[i][j-1] != -1 && a[i][j-1] == 0){
							a[i][j-1] = d; 
						}
					}


					if(j+1 < m){ 
						d = a[i][j] + 1; 
						if(a[i][j+1] < d && a[i][j+1] != -1 && a[i][j+1] == 0){
							a[i][j+1] = d; 
						}
					}
				}
				if(d == 1) break;
			}
			if(d == 1) break;
		}
		if(a[x_Final][y_Final] > 0)	break; 
	}
}


void PrintMas(int **a, int n, int m){			//функция вывода массива
	int i, j;
	printf("\n");
    for (i=0; i<n; i++){
         for (j=0; j<m; j++){
            if(a[i][j] == -1) printf("||");
            else if(a[i][j] >= 0 && a[i][j] < 10){ printf("%d", a[i][j]); printf(" ");}
            else if(a[i][j] >= 10) printf("%d", a[i][j]);
            else if(a[i][j] == -2) printf("+ ");
            else printf("%d", a[i][j]);
         }
         printf("\n");
    }
    printf("\n");
}


#endif
