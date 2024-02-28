#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int main(int argc, char* argv[]){
	int fd[2];
	#ifdef ASIZE
		int array[ASIZE];
	#endif
	#ifndef ASIZE
		perror("ASIZE is not defined");
		exit(0);
	#endif
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	if(pipe(fd)==-1){
		perror("Unable to create pipe");
		exit(EXIT_FAILURE);
	}
	#ifdef ASIZE
		for(int i=0;i<ASIZE;i++){
			array[i]=i*atoi(argv[1]);
		}
	#endif
	#ifndef ASIZE
		perror("ASIZE is not defined");
		exit(0);
	#endif
	

	int pid=fork();

	#ifdef ASIZE
		int middle=ASIZE/2;	
	#endif
	#ifndef ASIZE
		perror("ASIZE is not defined");
		exit(0);
	#endif
	if(pid==0){
		close(fd[0]);
		int* tot1=(int*)malloc(sizeof(int*));
		*tot1=0;
		#ifdef ASIZE
			for(int i=0;i<middle;i++){
				*tot1+=array[i];
			}
		#endif
		#ifndef ASIZE
			perror("ASIZE is not defined");
			exit(0);
		#endif
		write(fd[1],tot1,sizeof(int*));
		close(fd[1]);
	}
	else if(pid>0){
		close(fd[1]);
		int* temp=(int*)malloc(sizeof(int*));
		int* tot2=(int*)malloc(sizeof(int*));
		read(fd[0],temp,sizeof(int*));
		#ifdef ASIZE
			for(int i=middle;i<ASIZE;i++){
				*tot2+=array[i];
			}
		#endif
		#ifndef ASIZE
			perror("ASIZE is not defined");
			exit(0);
		#endif
		
		printf("%d\n",*temp+*tot2);
		close(fd[0]);
	}
	else{
		perror("Process error");
		exit(EXIT_FAILURE);
	}
	return 0;
}