#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int n=10;
const int m=10;
int mas_test[n][m];

void PrintMas(int **a, int n, int m);			//функция вывода массива
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);		//функция нахождение кратчайшего пути
void PrintMas1(int **a, int n, int m);

int main()
{
	srand ( time(NULL) ); 
    int n = 10, m = 10; 						//ширина и высота массива
    int mas_test[10][10] = {					//тестовый массив на время, пока не создадим генератор лабиринта
		-1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		-1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
		-1,  0, -1, -1, -1, -1, -1, -1, -1,  0,
		-1,  0, -1,  0,  0,  0, -1,  0,  0,  0,
		-1,  0, -1,  0, -1,  0, -1,  0, -1, -1,
		-1,  0, -1,  0, -1,  0, -1,  0,  0,  0,
		-1,  0, -1, -1, -1,  0, -1, -1, -1,  0,
		-1,  0,  0,  0,  0,  0, -1,  0,  0,  0,
		-1, -1, -1, -1, -1, -1, -1,  0, -1, -1,
		-1,  0,  0,  0,  0,  0,  0,  0, -1, -1 
		};
		
	
	int x_Primary = 1, y_Primary = 1;			//Начальные координаты поиска
	int x_Final = 3, y_Final = 3;				//Конечные координаты поиска

    int **a = new int *[n]; // Выделение памяти для массива
    
    for (int i=0; i<n; i++)
         a[i] = new int [m];
         

    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            a[i][j] = mas_test[i][j];
         }
    }
    
    PrintMas(a, n, m);
    
	track(a, n, m, x_Primary, y_Primary, x_Final, y_Final);
	
	PrintMas1(a, n, m);
	
    
    delete [] a; // очистка памяти
    return 0;
}


void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final){
   int dx[4] = {1, 0, -1, 0};
   int dy[4] = {0, 1, 0, -1};
   int d , k , x, y;
   bool stop;
   
//	if ( mas_test[x_Primary][y_Primary] == -1 || mas_test[x_Final][y_Final] == -1) {
//	return 0;}
    d=0;
	mas_test[x_Primary][y_Primary] == 0;
    do {
    	stop = true;
    	for(x=0; x< n; x++)
    		for(y=0; y< m; y++)
    			if(mas_test[n][m] == d){
    				for(k=0; k<4; k++){
    					int ix=x + dx[k], iy=y + dy[k];
    					if (ix >= 0 && ix<n && iy>= 0 && iy < m && mas_test[ix][iy] == 0){
    						stop = false;
    						mas_test[ix][iy] = d + 1;
						} 
					}
				}d++;
	
			}while ( !stop && mas_test[x_Final][y_Final] == 0 ); 
//    if( mas_test[x_Final][y_Final] == 0) return error;
		
}


void PrintMas(int **a, int n, int m){			
	cout << endl;
    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            if(a[i][j] == -1) cout << "8 ";
            else cout << "  ";
         }
         cout << endl;
    }
    cout << endl;
}

void PrintMas1(int **a, int n, int m){ 
 cout << endl;
for (int i=0; i<n; i++){
for (int j=0; j<m; j++){
if(a[i][j] == -1) cout << "8 ";
else if(a[i][j] > 0) cout << "1 ";
}
cout << endl;
}
cout << endl;
}
