#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		perror("Incorrect argument amount");
		exit(1);
	}
	int fd[2];
	int p=pipe(fd);
	if(p<0){
		perror("Pipe error");
		exit(1);
	}
	write(fd[1],argv[1],strlen(argv[1])+1);
	write(fd[1],argv[2],strlen(argv[2])+1);
	close(fd[1]);
	char s1[strlen(argv[1])+1];
	char s2[strlen(argv[2])+1];
	read(fd[0],s1,strlen(argv[1])+1);
	read(fd[0],s2,strlen(argv[2])+1);
	close(fd[0]);
	printf("%s\n%s\n",s1,s2);
	return 0;
	
}
