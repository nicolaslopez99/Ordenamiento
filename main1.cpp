#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;
void intercambio(int a[],int min,int i){
	int aux;
	aux=a[i];
	a[i]=a[min];
	a[min]=aux;
}
void seleccion (int a[], int N){
int i,j,min;
   for (i=0;i<N-1; i++){
   min = i;
   for (j=i+1;j<N; j++)
   if(a[j]<a[min]) min = j;
   intercambio(a, min, i);
   }

}

void insercion (int  a[], int N){
int i,j; 
int v;
  for (i=1; i<=N-1; i++){
  j=i; 
  v=a[j];
  while(a[j-1]>v && j>0){
  a[j]=a[j-1];
  j--;
  }
  a[j]= v;
  }

}
void burbuja (int a[], int N){
int i,j;
  for (i=N-1; i>=0; i--)
     for(j=1; j<=i; j++)
           if(a[j-1]> a[j]) intercambio(a,j-1,j);

}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main() {
	for(int n=10;n<=500;n=n+10){
		int a[n];

	//for(int i=0;i<n;i++){
	//	a[i]=i;
	//}
	for(int i=n-1;i>=0;i--){
		a[i]=i;
	}
	

	LARGE_INTEGER t_ini, t_fin;
	double secs;
	QueryPerformanceCounter(&t_ini);

	//seleccion(a,n);
	insercion(a,n);
	//burbuja(a,n);

	QueryPerformanceCounter(&t_fin);
	secs = performancecounter_diff(&t_fin, &t_ini);
	printf("%.16g \n", secs * 1000.0);
	}
return 0;
}
