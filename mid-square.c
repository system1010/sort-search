#include <stdio.h>
#include <time.h>

int main(int argc, char** argv[])
{
	time_t t = time(NULL);
	struct tm* aTm = localtime(&t);
	long long int key;
	for(int i=0;i<1000000;++i){
       	key = (aTm->tm_hour) * 10000000 + (aTm->tm_min) * 100000 + (aTm->tm_sec + i) * 1000 + (aTm->tm_mday) * 10 + (aTm->tm_year); 

        key = key * key; 

        key = key / 10000; 
        key = key % 100000000; 
	printf("%i\n", key);
	}
return 0;
}
