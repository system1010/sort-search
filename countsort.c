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
int signum(int a, int b){
return (a-b > 0) ? 1 : ((a-b < 0) ? -1 : 0);
}
int main(){ 
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 46, 51, 765, 665, 33, 7, 39};
	clockid_t clk_id = CLOCK_REALTIME;
	const uint TIME_FMT = strlen("2012-12-31 12:59:59.123456789") + 1;
	char timestr[TIME_FMT];
	struct timespec ts, res;
	clock_getres(clk_id, &res);
	clock_gettime(clk_id, &ts);
	timespec2str(timestr, sizeof(timestr), &ts);
		unsigned long resol = res.tv_sec * NANO + res.tv_nsec;
		printf("%s\n", timestr);




  	int n = sizeof(arr)/sizeof(arr[0]);
	int output[n]; 
        int count[sizeof(arr)/sizeof(arr[0])]={0}, i, j; 
	      
	for(i = n-1;i>=1; --i) 
	for (j=i-1;j>=0;--j){
	if (signum(arr[i], arr[j])==1)
	{
	++count[i];
    clock_gettime(clk_id, &ts);
            timespec2str(timestr, sizeof(timestr), &ts);
		                    unsigned long resol = res.tv_sec * NANO + res.tv_nsec;
	                    printf("%s ", timestr);

	printf("i=%i j=%i %i > %i",i,j, arr[i],arr[j]);
	for (int k = 0; k < n; ++k)
	printf(" %i",count[k]); 
	printf("  inversion count i\n");
	}else{
	++count[j];
	    clock_gettime(clk_id, &ts);
	            timespec2str(timestr, sizeof(timestr), &ts);
			                    unsigned long resol = res.tv_sec * NANO + res.tv_nsec;
		                    printf("%s ", timestr);
	printf("i=%i j=%i %i < %i",i,j, arr[i],arr[j]);
	for (int k = 0; k < n; ++k)
	printf(" %i",count[k]);
	printf("  not inversion count j\n");
	}
	}
	for (i = 0; i < n; ++i)
	output[count[i]] = arr[i]; 
	
	for (i=0;i<n;++i)
		printf("%i ", output[i]);
        printf("\n");
	return 0; 
} 
