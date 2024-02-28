#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <semaphore.h>

char buffer[5];
sem_t empty,full;
pthread_mutex_t m1;
int count=0;


void* upper(void* args){


	int tid=*((int*)args);
	
	for(int i=0;i<5;i++){
		char c=rand()%26+65;
		sem_wait(&empty);
		pthread_mutex_lock(&m1);
		buffer[count]=c;
		printf("writer ID: %d, char written: %c\n",tid,c);
		count++;
		pthread_mutex_unlock(&m1);
		sem_post(&full);
	}
	return NULL;
}

void* lower(void* args){

	int tid=*((int*)args);
	
	for(int i=0;i<5;i++){
		char c=rand()%26+97;
		sem_wait(&empty);
		pthread_mutex_lock(&m1);
		buffer[count]=c;
		printf("writer ID: %d, char written: %c\n",tid,c);
		count++;
		pthread_mutex_unlock(&m1);
		sem_post(&full);
	}

	
	return NULL;
}

void* reader(void* args){
	int tid=*((int*)args);
	
	for(int i=0;i<5;i++){
		sem_wait(&full);
		pthread_mutex_lock(&m1);
		printf("reader ID: %d, char read: %c\n",tid,buffer[count-1]);
		count--;
		pthread_mutex_unlock(&m1);
		sem_post(&empty);
	}


	return NULL;
}

int main(int argc,char*argv[]){
	if(argc!=1){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	(void)argv[0];
	srand((unsigned int)time(NULL));
	pthread_t tids[8];
	if(sem_init(&empty,1,5)!=0||sem_init(&full,1,0)!=0){
		perror("Semaphore initialization error");
		exit(EXIT_FAILURE);
	}
	if(pthread_mutex_init(&m1, NULL)!=0){
		perror("Mutex initialization error");
		exit(EXIT_FAILURE);
	}
	int ids[8];
	for(int i=0;i<8;i++){
		if(i<2){
			ids[i]=i;
			if(pthread_create(&tids[i],NULL,lower,(void*)&ids[i])!=0){
				perror("Unable to create thread");
				exit(EXIT_FAILURE);
			}
		}
		else if(i>=2&&i<4){
			ids[i]=i;
			if(pthread_create(&tids[i],NULL,upper,(void*)&ids[i])!=0){
				perror("Unable to create thread");
				exit(EXIT_FAILURE);
			}
		}
		else if(i>=4&&i<8){
			ids[i]=i-4;
			if(pthread_create(&tids[i],NULL,reader,(void*)&ids[i])!=0){
				perror("Unable to create thread");
				exit(EXIT_FAILURE);
			}
		}
	}

	for(int i=0;i<8;i++){
		if(pthread_join(tids[i],NULL)!=0){
			perror("Unable to join thread");
			exit(EXIT_FAILURE);
		}
	}


	return 0;
}