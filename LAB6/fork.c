#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i;

int main(int argc, char* argv[]){
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(1);
	}
	i=atoi(argv[1]);
	int f=fork();
	printf("%s\n","Hello World");
	if(f<0){
		perror("Fork error");
		exit(1);
	}
	if(f==0){
		printf("Child: %d\n",i-1);
	}
	else{
		printf("Parent: %d\n",i+1);
	}
	return 0;
}
