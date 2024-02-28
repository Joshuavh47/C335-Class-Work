#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(1);
	}
	int p[2];
	int pipe1=pipe(p);
	if(pipe1<0){
		perror("Pipe error");
		exit(1);
	}
	int fork1=fork();
	if(fork1<0){
		perror("Fork error");
		exit(1);
	}
	if(fork1>0){
		close(p[0]);
		write(p[1], argv[1],strlen(argv[1])+1);
		close(p[1]);
	}
	if(fork1==0){
		close(p[1]);
		char s[strlen(argv[1])+1];
		read(p[0],s,strlen(argv[1])+1);
		close(p[0]);
		printf("%s\n",s);
	}
	return 0;

}
