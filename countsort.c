#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
int signum(int a, int b){
return (a-b > 0) ? 1 : ((a-b < 0) ? -1 : 0);
}
int main(){ 
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 46, 51, 765, 665, 33, 7, 39};

  	int n = sizeof(arr)/sizeof(arr[0]);
	int output[n]; 
        int count[sizeof(arr)/sizeof(arr[0])]={0}, i, j; 
	clock_t t,t2,t3;
	t = clock();
	      
	for(i = n-1;i>=1; --i) 
	        for (j=i-1;j>=0;--j){
			t3=clock()-t; 
			if (signum(arr[i], arr[j])==1)
			{
			++count[i];
			printf("%f %i - %i > 0", ((double)t3)/CLOCKS_PER_SEC, arr[i],arr[j]);
			for (int k = 0; k < n; ++k)
			printf(" %i",count[k]); 
			printf("  inversion\n");

			}else{
			++count[j];
			printf("%f %i - %i < 0", ((double)t3)/CLOCKS_PER_SEC, arr[i],arr[j]);
			for (int k = 0; k < n; ++k)
			printf(" %i",count[k]);
			printf("  not inversion\n");

			}
			}
	for (i = 0; i < n; ++i)
	output[count[i]] = arr[i]; 
	
	for (i=0;i<n;++i)
		printf("%i ", output[i]);
        printf("\n");
	t2=clock()-t; 
	printf("sec: %f ", ((double)t2)/CLOCKS_PER_SEC);
	printf("end\n");
	return 0; 
} 
