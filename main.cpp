#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

#include "stack.h"

void PrintMas(int **a, int n, int m);			//функция вывода массива
int Maze(int **a, int n, int m);				//генерация начальной матрицы
int MazeGenerator(int **a, int n, int m, int x, int y);
void StekPro(int **a, int n, int m, int x, int y);


Stack<int> StackCell(999999999);

int kol = 0;
int height = 5, width = 5;

int main()
{
	srand ( time(NULL) ); 
	
	RenderWindow window( VideoMode(1000, 600), "Test!");
    
    Clock clock;

	RectangleShape rectangle( Vector2f(height, width));
	
    int n = 40, m = 40;
    int x = 5, y = 5;
    
    //cin >> n >> m;


    int **a = new int *[n]; // Выделение памяти для массива

    
    for (int i=0; i<n; i++)
         a[i] = new int [m];
     
    
    Maze(a, n, m);
    
    //PrintMas(a, n, m);
    

	MazeGenerator(a, n, m, x, y);

    while (window.isOpen()){
		Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

		//window.clear(Color::Green);


		 for (int i=0; i<n; i++)
			 for (int j=0; j<m ; j++)
				{ 
				  if (a[i][j]==1) rectangle.setFillColor(Color(240, 170, 19));
				  //if (a[i][j]==1) rectangle.setFillColor(Color::Green);

			      if (a[i][j]==-1)  rectangle.setFillColor(Color::Green);

				  //if (a[i][j]==' ') continue;

		          rectangle.setPosition(j*height, i*width) ; 
		          window.draw(rectangle);
	       	 }
    
        window.display();
    }
    
    PrintMas(a, n, m);
    
    StackCell.printStack();
    
    delete [] a; // очистка памяти
    return 0;
}



int Maze(int **a, int n, int m){				//генерация начальной матрицы
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(((i % 2 != 0) && (j % 2 != 0)) && ((i < n-1) && (j < m-1)))
				a[i][j] = 0;
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
	
	a[x][y] = 1;

	if(x-2 >= 0){//ищутся соседи
		if(a[x-2][y] == 0){
			b[0] = 1;
			NeighborsAmount++;
		}
	}

	if(y+2 <= m){
		if(a[x][y+2] == 0){
			b[1] = 1;
			NeighborsAmount++;
		}
	}

	if(x+2 < n){
		if(a[x+2][y] == 0){
			b[2] = 1;
			NeighborsAmount++;
		}
	}

	if(y-2 >= 0){
		if(a[x][y-2] == 0){
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
				if(a[x-2][y] == 0){
					if (x-3 >= 0) a[x-1][y] = 1;
					a[x-2][y] = 1;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x-2, y);
				}
			}
			break;
		}
		case 2:{
			if(y+2 < m){
				if(a[x][y+2] == 0){
					if (y+3 <= m) a[x][y+1] = 1;
					a[x][y+2] = 1;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x, y+2);
				}
			}
			break;
		}
		case 3:{
			if(x+2 < n){
				if(a[x+2][y] == 0){
					if (x+3 <= n) a[x+1][y] = 1;
					a[x+2][y] = 1;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x+2, y);
				}
			}
			break;
		}
		case 4:{
			if(y-2 > 0){
				if(a[x][y-2] == 0){
					if (y-3 >= 0) a[x][y-1] = 1;
					a[x][y-2] = 1;
					StekPro(a, n, m, x, y);
					return MazeGenerator(a, n, m, x, y-2);
				}
			}
			break;
		}
		default: break;
	}
	
	if(StackCell.getTop() > 0){
		y = StackCell.Peek(1);
		StackCell.pop();
		x = StackCell.Peek(1);
		StackCell.pop();
		MazeGenerator(a, n, m, x, y);
	}
	
	return **a;
}

void PrintMas(int **a, int n, int m){			//функция вывода массива
	cout << endl;
    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            if(a[i][j] == -1) cout << "  ";
            else if(a[i][j] == 1) cout << "1 ";
            else if(a[i][j] == 9) cout << "+ ";
            else if(a[i][j] == 0) cout << "0 ";
            else cout << "  ";
         }
         cout << endl;
    }
    cout << endl;
}
