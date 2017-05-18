#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int n=10;
const int m=10;
int mas_test[n][m];
int d;

void PrintMas(int **a, int n, int m);			
void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final);		//ôóíêöèÿ íàõîæäåíèå êðàò÷àéøåãî ïóòè
void way(int **a,int n,int m);
int main()
{
	srand ( time(NULL) ); 
    int n = 10, m = 10; 						
    int mas_test[10][10] = {					
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
		


    int **a = new int *[n]; �
    
    for (int i=0; i<n; i++)
         a[i] = new int [m];
         

    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            a[i][j] = mas_test[i][j];
         }
    }
    
    PrintMas(a, n, m);
    cout << endl;
 
    
	track(a, n, m, 1, 2, 5, 3);
    way(a,n,m);
	
	PrintMas(a, n, m);
	
    
    delete [] a; 
    return 0;
}


void track(int **a, int n, int m, int x_Primary, int y_Primary, int x_Final, int y_Final){ 
	int d = 1, x = x_Primary, y = y_Primary; 
	int i, j; 
	a[x][y] = d; 
	d++; 

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



					if(i-1 >= 0){ 
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
				
	
				
			} 
		}
		if(a[x_Final][y_Final] > 0)	break;  
	}
	
}



void way(int **a,int n,int m){
int i, j;
int d;
int x_Primary, y_Primary;
int x_Final, y_Final;
a[x_Final][y_Final]=d; 
	for(;;){
	         for(i=d-2;i>-2,i<n-2;i--){
		      for(j=d-2;j>-2,j<m-2;j--){
		      	for(;d>-3;d--){
		      	if(a[i][j] == -3) continue;
		if(a[i][j]>-2){
					      	 	    a[x_Final][y_Final]=-5;
 	    if(i+1 < n){
 	    	if(a[x_Final+1][y_Final] < d) 
			 a[x_Final+1][y_Final] = -5;
 	    }
 	    if(i-1 >=n){
 	                           if(a[x_Final-1][y_Final] < d) 
								a[x_Final-1][y_Final] = -5 ;
 	                            
 	                       }
 	             if(j-1 >=m){  
	                           if(a[x_Final][y_Final-1] < d) 
							   a[x_Final][y_Final-1] = -5;
	                          
	                       }
	         if(j+1 < m)   {
			          
	                           if(a[x_Final][y_Final+1] < d) 
							   a[x_Final][y_Final+1] = -5;
	                       }
 	      
			
	                 }
		          }    	
			  }
      }
	
	 
	if(a[x_Primary][y_Primary]== -2) break;

}
}




void PrintMas(int **a, int n, int m){			
	cout << endl;
    for (int i=0; i<n; i++){
         for (int j=0; j<m; j++){
            if(a[i][j] == -1) cout << "||";
            else if(a[i][j] > 0) cout << a[i][j] << " ";
            else cout << "__";
         }
         cout << endl;
    }
    cout << endl;
}
