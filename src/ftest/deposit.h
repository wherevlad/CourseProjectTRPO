#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <malloc.h>

void matrix_1(int **a, int n, int m);
void matrix_2(int **a, int n, int m);
int way(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);

#endif