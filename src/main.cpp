#include "deposit.h"

int main()
{
	srand ( time(NULL) );

    int n, m;
    int x = 5, y = 5;
    
    cout << "Введите длину и ширину матрицы(меньше 20х20 и больше 8x8):";
    
    for(;;){
		//cin >> n >> m;
		n = 10;
		m = 10;
		
		if(n > 20 || m > 20 || n < 8 || m < 8)
			cout << "Введите допустимые значения размера матрицы..";
		else
			break;
	}


    int **a = new int *[n]; // Выделение памяти для массива
    
    for (int i=0; i<n; i++)
         a[i] = new int [m];

    ofstream fout("bin/matrix.txt");
    fout.is_open();
    
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
	
	MatrixFilling(fout, a, n, m);

	track(a, n, m, 1, 1, n-2, m-2);
	

	a[1][1] = -2;
	way(a, n, m, 1, 1, n-2, m-2);

    PrintMas(a, n, m);
    
    StackCell.printStack();
    fout.close();
    delete [] a; 

    return 0;
}
#include "functio.h"