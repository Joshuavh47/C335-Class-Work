#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

int num;
sem_t w_mutex;
sem_t r_mutex;

void* randomNum(void* number){
	srand((unsigned int)time(NULL));
	int n=(*(int*)number);
	for(int i=0;i<n;i++){
		sem_wait(&w_mutex);
		num=rand()%n;
		printf("writer wrote: %d\n",num);
		sem_post(&r_mutex);

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
	if(sem_init(&r_mutex,1,0)!=0||sem_init(&w_mutex,1,1)!=0){
		perror("Semaphore initialization error");
		exit(EXIT_FAILURE);
	}
	
	pthread_t tid;
	
	if(pthread_create(&tid, NULL, randomNum, (void*)&n)!=0){
		perror("Unable to create thread");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;i++){
		sem_wait(&r_mutex);
		printf("main read: %d\n",num);
		sem_post(&w_mutex);
	}

	if(pthread_join(tid, NULL)!=0){
		perror("pthread_join() error");
		exit(EXIT_FAILURE);
	}
	sem_destroy(&w_mutex);
	sem_destroy(&r_mutex);
	
	return 0;
}