#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void PrintMas(int **a, int n, int m);			//функция вывода массива
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);		//функция нахождение кратчайшего пути


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
    
    //PrintMas(a, n, m);
    
	track(a, n, m, x_Primary, y_Primary, x_Final, y_Final);
    
    delete [] a; // очистка памяти
    return 0;
}


void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final){
	int d = 0;									//уровень волны

}


void PrintMas(int **a, int n, int m){			//функция вывода массива
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
