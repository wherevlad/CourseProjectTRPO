#include "conio.h"   
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int a;

int bufp,bufe;
struct{
 signed char n,m;
}buf[256];


void PrintMas(int **c, int n, int m){			
	cout << endl;
    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            if(c[i][j] == -1) cout << "8 ";
            else cout << "  ";
         }
         cout << endl;
    }
    cout << endl;
}

void Short(int n,int m,int s){
	int buf;
 if(c[n][m]<=s)return; 
 c[n][m]=s;   
 //buf[bufe].n=n;    
 //buf[bufe].m=m;    
 //bufe++; 
 getch();   
}

int Way(int *n,int *m){
 if(bufp==bufe)return 0;
 *n=buf[bufp].n;
 *m=buf[bufp].m;
 bufp++;   
 return 1;
}


void track(int a,int b,int i,int j){
//	_fmemset(trackmax,0xFF,sizeof(trackmax));
	//trackmax заполнить максимальными значениями
 int s,t,n,m; 
 bufp=bufe=0;    
 Short(a,b,0);   
 while(Way(&n,&m)){   
  if((a==i)&&(b==j)){

  }
  n=c[i][j]+c[n][m];//перебор соседних клеток
  
  if(c[m+1][n])Short(n,m+1,s); 
  if(c[m-1][n])Short(n,m-1,s);  
  if(c[m][n+1])Short(n+1,m,s); 
  if(c[m][n-1])Short(n-1,m,s); 
 }
   if(c[i][j]==-1){
  cout<<"Пути не существует"<<endl;//Добавить заливку
  return;
 }  else 
 cout<<"Путь"<<endl;//Добавить заливку

 while((n!=a)||(m!=b)){  
 //Добавить поиск соседней клетки
 
  if(c[m+1][n]<s){a=n;b=m+1;t=c[m+1][n];} 
  
  if(c[m-1][n]<s){a=n;b=m-1;t=c[m-1][n];} 
  
  if(c[m][n+1]<s){a=n+1;b=m;t=c[m][n+1];}
  if(c[m][n-1]<s){a=n-1;b=m;t=c[m][n-1];}
  n=a;m=b;s=t; 

  getch();   
 }
}

int main(){
 int s, a ,b, i, j,n,m,c;
 a=1;b=1;   // Hачальная точка
 i=3;j=3;  // Цель пути

 int **c = new int *[n];
PrintMas(c, n, m);
 track(a,b,i,j); 
 
//    
//    for (int i=0; i<n; i++)
//         a[i] = new int [m];
//         
//
//    for (int i=0; i<n; i++){
//         for (int j=0; j<m; j++){
//            a[i][j] = mas_test[i][j];
//         }
//    }
    

    
    delete [] c; 
    return 0;
}
