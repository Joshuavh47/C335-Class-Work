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
	int f1=fork();
	if(f1<0){
		perror("Fork error");
		exit(1);
	}
	if(f1>0){
		close(fd[0]);
		write(fd[1],argv[1],strlen(argv[1])+1);
		write(fd[1],argv[2],strlen(argv[2])+1);
		close(fd[1]);
		wait(NULL);
	}
	else{
		close(fd[1]);
		char* arg1=malloc(sizeof(char)*(strlen(argv[1])+1));
		char* arg2=malloc(sizeof(char)*(strlen(argv[2])+1));
		read(fd[0],arg1,strlen(argv[1])+1);
		read(fd[0],arg2,strlen(argv[2])+1);
		close(fd[0]);
		if(strlen(arg1)==0||strlen(arg2)==0){
			perror("Impropper argument entered");
			exit(1);
		}
		if(strncmp("/bin/",arg1,5)!=0){
			char temp[strlen(arg1)+1];
			strcpy(temp,arg1);
			arg1=malloc(sizeof(char)*(strlen(arg1)+6));
			strcpy(arg1,"/bin/");
			strcat(arg1,temp);
		}
		int ex=execl(arg1,arg1,arg2,NULL);
		if(ex<0){
			perror("Ececl error");
			exit(1);
		}

	}
	return 0;

}
