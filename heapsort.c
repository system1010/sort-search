#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int signum(int a, int b){
	return (a-b > 0) ? 1 : ((a-b < 0) ? -1 : 0);
}
int main() 
{ 
	int arr[] = {NULL, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]),R; 
        clock_t t1;

	for (int k=0; k < n; k++) 
		printf("%d ", arr[k]); 
	printf("\n"); 

H1:;	int l=n/2+1, r=n;

H2:;	if (l>1) {l--;R=arr[l];}
	else {r--;R=arr[r], arr[r]=arr[l];}
  	if (r==1){arr[l]=R;goto exit;}
H3:;	int j=l;
H4:;	int i=j;j=2*j;
   	if (l==r) goto H6;
       	if (j>r) goto H8;
H5:;	if (arr[j]<arr[j+1]) j=j+1;
        t1 = clock();
	printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
	for (int k=0; k < n; k++) 
		printf("%d ", arr[k]); 
	printf("\n");
H6:;	if (R>=arr[j])goto H8;
H7:;	arr[i]=arr[j];
	goto H4;
H8:;	arr[i]=R;
	goto H2;
        t1 = clock();
	printf ("%f ",((double)t1)/CLOCKS_PER_SEC);
exit:;
	for (int k=0; k < n; k++) 
        	printf("%d ", arr[k]); 
	printf("\n");

	return 0;
}	

