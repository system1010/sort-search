#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main() 
{ 
	int arr[] = {6, 5, 4, 2, 3, 1, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	clock_t t1;

	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 

B1:;	int bound = n, t;
   	
B2:;	for(;;){
   	t=0;
   	for (int j = 0; j < bound-1; j++){	   
B3:;	if (arr[j]- arr[j+1]>0){ 
	int temp = arr[j];
	arr[j] = arr[j+1]; 
	arr[j+1] = temp;	
   	t=j;
	t1 = clock();
        printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
	printf("j=%i [%i-%i<0] ", j, arr[j], arr[j+1]);
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
   	}
   	}
B4:;   	if (t==0) {
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
	return 0;}
   	bound=t+1;
	int T[7]={0};
	for (int i = 0; i<=n;i++)
		for (int j = 0;j<=i - 1;j++)
			if (arr[j] > arr[i]) T[arr[i]-1]++;

	printf("inversion table: ");
	for (int i=0; i < n; i++) 
	                printf("%d ", T[i]); 
        printf("\n"); 
	};
}	

