#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SZ 100

float A[SZ][SZ];



int main(void){


	struct timeval timer_usec;
	long long int timestamp_usec1; /* timestamp in microsecond */
	if (!gettimeofday(&timer_usec, NULL)) {
		timestamp_usec1 = ((long long int) timer_usec.tv_sec) * 1000000ll + (long long int) timer_usec.tv_usec;
	}
	else{
		timestamp_usec1=-1;
	}
	for (int i = 0; i < SZ; i++){
    	for (int j = 0; j < SZ; j++){
      		A[i][j] = i*j;
    	}
	}

	for(int i=0;i<SZ;i++){
		for(int j=1;j<SZ;j++){
			A[i][j] = ( A[i][j-1] + A[i][j] ) / 2;
		}
	}
	long long int timestamp_usec2; /* timestamp in microsecond */
	if (!gettimeofday(&timer_usec, NULL)) {
		timestamp_usec2 = ((long long int) timer_usec.tv_sec) * 1000000ll + (long long int) timer_usec.tv_usec;
	}
	else{
		timestamp_usec2=-1;
	}
	printf("%lld\n",(timestamp_usec2-timestamp_usec1));
	return 0;

	
}
