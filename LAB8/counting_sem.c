#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <semaphore.h>

sem_t semaphore;

void* printA(){
	sem_wait(&semaphore);
	printf("%s\n","A");
	return NULL;
}

void* printB(){
	sem_wait(&semaphore);
	printf("%s\n","B");
	return NULL;
}

void* printC(){
	sem_wait(&semaphore);
	printf("%s\n","C");
	return NULL;
}

int main(int argc,char* argv[]){
	if(argc!=1){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	(void)argv[0];
	if(sem_init(&semaphore,1,2)!=0){
		perror("Error creating semaphore");
		exit(EXIT_FAILURE);
	}
	sem_post(&semaphore); // FIX for code issue
	pthread_t tid1,tid2,tid3;
	if(pthread_create(&tid1,NULL,printA,(void*)NULL)!=0){
		perror("Unable to create thread");
		exit(EXIT_FAILURE);
	}
	
	if(pthread_create(&tid2,NULL,printB,(void*)NULL)!=0){
		perror("Unable to create thread");
		exit(EXIT_FAILURE);
	}
	
	if(pthread_create(&tid3,NULL,printC,(void*)NULL)!=0){
		perror("Unable to create thread");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid1,NULL)!=0){
		perror("Unable to join thread");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid2,NULL)!=0){
		perror("Unable to join thread");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(tid3,NULL)!=0){
		perror("Unable to join thread");
		exit(EXIT_FAILURE);
	}
	sem_destroy(&semaphore);
	return 0;
}