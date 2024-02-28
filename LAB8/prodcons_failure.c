#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int num;

void* randomNum(void* number){
	srand((unsigned int)time(NULL));
	int n=(*(int*)number);
	for(int i=0;i<n;i++){
		num=rand()%n;
		printf("writer wrote: %d\n",num);
		wait(NULL);
	}
	return NULL;
}


int main(int argc,char* argv[]){
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	if(atoi(argv[1])<=0){
		perror("Number can't be less than 0");
		exit(EXIT_FAILURE);
	}
	int n=atoi(argv[1]);
	pthread_t tid;
	
	if(pthread_create(&tid, NULL, randomNum, (void*)&n)!=0){
		perror("Unable to create thread");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;i++){
		printf("main read: %d\n",num);
	
	}
	if(pthread_join(tid, NULL)!=0){
		perror("pthread_join() error");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}