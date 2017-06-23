#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

#include "stack.h"

Stack<int> StackCell(999999);

float height = 20, width = 20;

const int N = 20, M = 20;

void PrintMas(int **a, int n, int m);			//функция вывода массива
int Maze(int **a, int n, int m);				//генерация начальной матрицы
int MazeGenerator(int **a, int n, int m, int x, int y);
void StekPro(int **a, int n, int m, int x, int y);
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);		
int way(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);
void MazeSteck(int **a, int n, int m);

int matrix_1(int n, int m);

#endif