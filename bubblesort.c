#include <stdio.h> 
#include <time.h>
clock_t t1,t2,t3;
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
B1:;	int bound = n, t;
   	
B2:;	t=0;
   	for (int j = 0; j < bound-1; j++){	   
B3:;	if (arr[j] > arr[j+1]){ 
	int temp = arr[j];
	arr[j] = arr[j+1]; 
	arr[j+1] = temp;	
   	t=j;
	t1=clock(); 
	printf("%f j=%i %i > %i \n", ((double)t1)/CLOCKS_PER_SEC,j ,arr[j], arr[j+1]);
   	}
   	}
B4:;   	if (t==0) {
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
	return 0;}
   	bound=t+1;
	goto B2;
}	

