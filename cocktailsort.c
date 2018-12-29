#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{ 
	int arr[] = {6, 4, 5, 2, 3, 1, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
        int i, j, k;
	clock_t t1;
        for (i=0; i < n; i++) 
		printf("%d ", arr[i]); 
        printf("\n"); 
	for(i = 0; i < n/2; i++)
        {
        for(j = i; j < n-i-1; j++)
        {
        if(arr[j]-arr[j+1]>0)
        {
        int temp = arr[j];
        arr[j] = arr[j+1]; 
        arr[j+1] = temp;   
        t1 = clock();
	printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
	printf("j=%i [%i-%i<0] ", j, arr[j], arr[j+1]);
	for (int l=0; l < n; l++) 
		printf("%d ", arr[l]); 
	printf("\n"); 
        }
        }
	for(k = n-2-i; k > i; k--)
	{
	if(arr[k]- arr[k-1]<0)
	{
	t1 = clock();
        printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
        printf("k=%i [%i-%i<0] ", k, arr[k], arr[k-1]);
	int temp = arr[k];
	arr[k] = arr[k-1]; 
	arr[k-1] = temp;
     	for (int l=0; l < n; l++) 
        	printf("%d ", arr[l]); 
        printf("\n"); 
	}
	}
   	int T[7]={0};
        	for (int g = 0; g<=n;g++)
        		for (int j = 0;j<=g - 1;j++)
                        	if (arr[j] > arr[g]) T[arr[g]-1]++;
	printf("inversion table: ");
	for (int l=0; l < n; l++) 
      		printf("%d ", T[l]); 
        printf("\n"); 
        }
	for (int i=0; i < n; i++) 
        	printf("%d ", arr[i]); 
        printf("\n"); 
return 0;
}
