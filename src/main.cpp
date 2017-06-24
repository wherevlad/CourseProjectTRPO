#include "deposit.h"

int main()
{
	srand ( time(NULL) );
	
	
    int n = N, m = M;
    int x = 5, y = 5;
    
    cout << "Введите длину и ширину матрицы(меньше 20х20 и больше 8x8):";
    
    for(;;){
		cin >> n >> m;
		
		if(n > 20 || m > 20 || n < 8 || m < 8)
			cout << "Введите допустимые значения размера матрицы..";
		else
			break;
	}


    int **a = new int *[n]; // Выделение памяти для массива
    
    for (int i=0; i<n; i++)
         a[i] = new int [m];
     
    
    Maze(a, n, m);


    a[n-2][m-2] = 0;
    a[n-2][m-3] = 0;
	MazeGenerator(a, n, m, x, y);
	for(;;){
		if(StackCell.getTop() > 0){
			MazeSteck(a, n, m);
		}
		else break;
	}
	

	track(a, n, m, 1, 1, n-2, m-2);
	

	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);


    PrintMas(a, n, m);
    
    StackCell.printStack();
    
    delete [] a; 
    return 0;
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
	int kk = 1;
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
		if(a[kk][kk] > 0 || a[kk][kk] == -1){ cout << kk << endl; kk ++;
		}
		if(a[x_Final][y_Final] > 0)	break; 
	}
}



int Maze(int **a, int n, int m){				//генерация начальной матрицы
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(((i % 2 != 0) && (j % 2 != 0)) && ((i < n-1) && (j < m-1)))
				a[i][j] = 1;
			else a[i][j] = -1;
		}
	}
	return **a;
}

void StekPro(int **a, int n, int m, int x, int y){

	if(x-2 >= 0){
		if(a[x-2][y] == 0){
			StackCell.push(x);
			StackCell.push(y);
		}
	}

	if(y+2 <= m){
		if(a[x][y+2] == 0){
			StackCell.push(x);
			StackCell.push(y);
		}
	}

	if(x+2 < n){
		if(a[x+2][y] == 0){
			StackCell.push(x);
			StackCell.push(y);
		}
	}

	if(y-2 >= 0){
		if(a[x][y-2] == 0){
			StackCell.push(x);
			StackCell.push(y);
		}
	}
}

int MazeGenerator(int **a, int n, int m, int x, int y){
	int b[4] = {0, 0, 0, 0}, NeighborsAmount = 0;
	int side;// = rand() % 4 + 1;
	
	a[x][y] = 0;

	if(x-2 >= 0){//ищутся соседи
		if(a[x-2][y] == 1){
			b[0] = 1;
			NeighborsAmount++;
		}
	}

	if(y+2 <= m){
		if(a[x][y+2] == 1){
			b[1] = 1;
			NeighborsAmount++;
		}
	}

	if(x+2 < n){
		if(a[x+2][y] == 1){
			b[2] = 1;
			NeighborsAmount++;
		}
	}

	if(y-2 >= 0){
		if(a[x][y-2] == 1){
			b[3] = 1;
			NeighborsAmount++;
		}
	}
//////////////////////////определяется рандомный сосед
	if(NeighborsAmount > 0){
		switch (NeighborsAmount){
			case 1:{
				for(int i = 0; i < 4; i++){
					if(b[i] == 1){ i++; side = i; break;}
				}
				break;
			}
			case 2:{
				side = rand() % 2 + 1;
				for(int i = 0; i < 4; i++){
					if(b[i] == 1) side--;
					if(side == 0){ i++; side = i; break;}
				}
				break;
			}
			case 3:{
				side = rand() % 3 + 1;
				for(int i = 0; i < 4; i++){
					if(b[i] == 1) side--;
					if(side == 0){ i++; side = i; break;}
				}
				break;
			}
			case 4:{
				side = rand() % 4 + 1;
				break;
			}
			default:{ 
				side = 0; 
				break;
			}
		}
	}

	switch (side){
		case 1:{
			if(x-2 > 0){
				if(a[x-2][y] == 1){
					if (x-3 >= 0) a[x-1][y] = 0;
					a[x-2][y] = 0;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x-2, y);
				}
			}
			break;
		}
		case 2:{
			if(y+2 < m){
				if(a[x][y+2] == 1){
					if (y+3 <= m) a[x][y+1] = 0;
					a[x][y+2] = 0;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x, y+2);
				}
			}
			break;
		}
		case 3:{
			if(x+2 < n){
				if(a[x+2][y] == 1){
					if (x+3 <= n) a[x+1][y] = 0;
					a[x+2][y] = 0;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x+2, y);
				}
			}
			break;
		}
		case 4:{
			if(y-2 > 0){
				if(a[x][y-2] == 1){
					if (y-3 >= 0) a[x][y-1] = 0;
					a[x][y-2] = 0;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x, y-2);
				}
			}
			break;
		}
		default: break;
	}
	
	return **a;
}

void MazeSteck(int **a, int n, int m){
	if(StackCell.getTop() > 0){
		int y = StackCell.Peek(1);
		StackCell.pop();
		int x = StackCell.Peek(1);
		StackCell.pop();
		MazeGenerator(a, n, m, x, y);
	}
}

void PrintMas(int **a, int n, int m){			//функция вывода массива
	cout << endl;
    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            if(a[i][j] == -1) cout << "||";
            else if(a[i][j] >= 0 && a[i][j] < 10) cout << a[i][j] << " ";
            else if(a[i][j] >= 10) cout << a[i][j];
            else if(a[i][j] == -2) cout << "+ ";
            else cout << a[i][j];
         }
         cout << endl;
    }
    cout << endl;
}
