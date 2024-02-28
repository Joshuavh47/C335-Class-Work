#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void* thread1(void* str){
	char*s=(char*)str;
	printf("Concat String: %s Example\n",s);
	return NULL;
}

void* thread2(void* num){
	int temp=*((int*)num);
	#ifdef INCCNT
		printf("Count: %d\n",INCCNT+temp);
	#endif
	return NULL;
}

int main(int argc, char* argv[]){
	if(argc!=3){
		perror("Incorrect number of arguments");
		exit(EXIT_FAILURE);
	}
	#ifndef INCCNT
		perror("INCNT must be defined");
		exit(EXIT_FAILURE);
	#endif
	pthread_t tid1;
	if(pthread_create(&tid1,NULL,thread1,argv[1])!=0){
		perror("Error creating thread");
		exit(EXIT_FAILURE);
	}
	pthread_join(tid1,NULL);
	pthread_t tid2;
	int temp=atoi(argv[2]);
	if(pthread_create(&tid2,NULL,thread2,&temp)!=0){
		perror("Error creating thread");
		exit(EXIT_FAILURE);
	}
	pthread_join(tid2,NULL);
	
	return 0;
}