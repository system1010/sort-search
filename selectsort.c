#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]), Ki=0, i, j, l; 
        clock_t t1;

	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
   	l=n;
S1:;   	for(;;){
   	l--;
   	for (j = l; j>=0 ; j--){	   
S2:;	if (Ki<arr[j]){Ki=arr[j];i=j;}
	t1 = clock();
   	printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
	printf("j=%i [%i-%i>0] Ki=%i  ", j, arr[j], arr[j-1], Ki);
	for (int i=0; i < n; i++) 
	printf("%d ", arr[i]); 
	printf("\n"); 
  	}
S3:;	if (Ki==0) goto S4;
   	int temp = arr[l];
        arr[l] = Ki; 
        arr[i] = temp;
	Ki=0;
   	}
S4:;
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
	return 0;
}
