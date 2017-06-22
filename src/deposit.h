#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace sf;

#include "stack.h"

void PrintMas(int **a, int n, int m);			//функция вывода массива
int Maze(int **a, int n, int m);				//генерация начальной матрицы
int MazeGenerator(int **a, int n, int m, int x, int y);
void StekPro(int **a, int n, int m, int x, int y);
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);		
int way(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);
void MazeSteck(int **a, int n, int m);

int one(int &n, int m);
/*
int one(int &d, int ye);
int two(int &d, int ye);
int three(int &d, int ye);
int four(int &d, int ye);
*/
#endif
