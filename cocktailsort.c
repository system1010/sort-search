#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void cocktail_sort(int *v, int n)
{
	int i, j, gatilho, k;
	do {
	for(i = 0; i < n/2; i++)
	{
		gatilho = 0;
		for(j = i; j < n-i-1; j++)
		{
			if(*(v+j) > *(v+j+1))
			{
				swap(v+j, v+j+1);
				gatilho = 1;
			}
		}
		for(k = n-2-i; k > i; k--)
		{
			if(*(v+k) < *(v+k-1))
			{
				swap(v+k, v+k-1);
				gatilho = 1;
			}
		}

	}
} while(gatilho == 1);

}

void main(){
int arr[]={7,5,3,8,5,2,9};
int n = 7;
cocktail_sort(*arr,n);




return 0;


}
