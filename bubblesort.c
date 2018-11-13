#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NANO 1000000000L

// buf needs to store 30 characters
int timespec2str(char *buf, uint len, struct timespec *ts) {
int ret;
struct tm t;
tzset();
if (localtime_r(&(ts->tv_sec), &t) == NULL)
return 1;
ret = strftime(buf, len, "%F %T", &t);
if (ret == 0)
return 2;
len -= ret - 1;
ret = snprintf(&buf[strlen(buf)], len, ".%09ld", ts->tv_nsec);
if (ret >= len)
return 3;
return 0;
}
int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
              clock_t t1;

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
	goto B2;
}	

