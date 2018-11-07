// C program for implementation of Bubble sort 
#include <stdio.h> 
#include <time.h>
void move(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 
clock_t t,t1,t2,t3;
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
for (i = 0; i < n-1; i++){	 
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]){ 
		
        t1=clock(); 
        printf("%f i=%i j=%i %i - %i > 0 ", ((double)t1)/CLOCKS_PER_SEC,i,j ,arr[j], arr[j+1]);
	printf("inversion, moving up: ");
	move(&arr[j], &arr[j+1]); 
	printArray(arr,n);
	printf("\n");	
	}else {
	t2=clock(); 
	printf("%f i-%i j=%i %i - %i < 0 ", ((double)t2)/CLOCKS_PER_SEC,i,j, arr[j], arr[j+1]);

	printf("not inversion :");	
	printArray(arr,n);
	printf("\n");
		}
		} 
}

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	t3=clock(); 
	printf("%f n=%i ", ((double)t1)/CLOCKS_PER_SEC, n);
	printArray(arr, n);
	printf("\n");
	bubbleSort(arr, n); 
	t=clock(); 
	printf("%f ", ((double)t)/CLOCKS_PER_SEC);
	printf("Sorted array: "); 
	printArray(arr, n); 
	return 0; 
} 
