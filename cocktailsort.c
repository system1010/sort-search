#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
        int i, j, gatilho, k;
	do {
        for(i = 0; i < n/2; i++)
        {
        gatilho = 0;
        for(j = i; j < n-i-1; j++)
        {
        if(arr[j] >arr[j+1])
        {
        int temp = arr[j];
        arr[j] = arr[j+1]; 
        arr[j+1] = temp;   
        gatilho = 1;
        }
        }
	for(k = n-2-i; k > i; k--)
	{
	if(arr[k] < arr[k-1])
	{
	int temp = arr[k];
	arr[k] = arr[k-1]; 
	arr[k-1] = temp;   
	gatilho = 1;
	}
	}
        }
	} while(gatilho == 1);
	for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
        printf("\n"); 


return 0;


}
