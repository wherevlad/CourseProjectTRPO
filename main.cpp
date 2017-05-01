#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef STACK_H
#define STACK_H
 
#include <cassert> // для assert
#include <iostream>
 
#include <iomanip> // для setw

using namespace std;
 
template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
public:
    Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор
 
    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack();         // вывод стека на экран
    inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline int getStackSize() const;  // получить размер стека
    inline T *getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке
};
 
// реализация методов шаблона класса STack
 
// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под стек
    top = 0; // инициализируем текущий элемент нулем;
}
 
// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
    size(otherStack.getStackSize()) // инициализация константы
{
    stackPtr = new T[size]; // выделить память под новый стек
    top = otherStack.getTop();
 
    for(int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}
 
// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}
 
// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
    // проверяем размер стека
    assert(top < size); // номер текущего элемента должен быть меньше размера стека
 
    stackPtr[top++] = value; // помещаем элемент в стек
}
 
// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
    // проверяем размер стека
    assert(top > 0); // номер текущего элемента должен быть больше 0
 
    stackPtr[--top]; // удаляем элемент из стека
}
 
// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  //
  assert(nom <= top);
 
  return stackPtr[top - nom]; // вернуть n-й элемент стека
}
 
// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
    for (int ix = top - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}
 
// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}
 
// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
    return stackPtr;
}
 
// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}
 
#endif // STACK_H


void PrintMas(int **a, int n, int m);			//функция вывода массива
int Maze(int **a, int n, int m);				//генерация начальной матрицы
int MazeGenerator(int **a, int n, int m, int x, int y);
void StekPro(int **a, int n, int m, int x, int y);

typedef struct cell{ //структура, хранящая координаты клетки в матрице
    int x;
    int y;
}cell;

typedef struct cellString{ 
    int x;
    int y;
    unsigned int size;
} cellString;

Stack<int> StackCell(999999999);

int main()
{
	srand ( time(NULL) ); 
	
    int n, m;
    int x = 5, y = 5;
    
    cin >> n >> m;

    int **a = new int *[n]; // Выделение памяти для массива

    
    for (int i=0; i<n; i++)
         a[i] = new int [m];
     
    
    Maze(a, n, m);
    
    //PrintMas(a, n, m);
    

	MazeGenerator(a, n, m, x, y);

   // StekPro(a, n, m, 5, 5);
    
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
				cout << "    " << side << endl;
				for(int i = 0; i < 4; i++){
					if(b[i] == 1) side--;
					if(side == 0){ i++; side = i; break;}
				}
				break;
			}
			case 3:{
				side = rand() % 3 + 1;
				cout << "    " << side << endl;
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

	cout << NeighborsAmount << "    " << side << endl;
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
