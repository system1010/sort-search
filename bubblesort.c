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
	for (int i=0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 

unsigned long resol;
clockid_t clk_id = CLOCK_REALTIME;
const uint TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
char timestr[TIME_FMT];
struct timespec ts, res;
clock_getres(clk_id, &res);
clock_gettime(clk_id, &ts);
timespec2str(timestr, sizeof(timestr), &ts);
resol = res.tv_sec * NANO + res.tv_nsec;

B1:;	int bound = n, t;
   	
B2:;	t=0;
   	for (int j = 0; j < bound-1; j++){	   
B3:;	if (arr[j] > arr[j+1]){ 
	int temp = arr[j];
	arr[j] = arr[j+1]; 
	arr[j+1] = temp;	
   	t=j;
clock_gettime(clk_id, &ts);
timespec2str(timestr, sizeof(timestr), &ts);

	printf("%s ",timestr);
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

