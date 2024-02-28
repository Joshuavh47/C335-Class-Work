#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc!=3){
		perror("invalid argument amount");
		exit(1);
	}
	char* s=malloc(sizeof(char)*(5+strlen(argv[1])+1));
	strcpy(s,"/bin/");
	strcat(s,argv[1]);
	int ex=execl(s,s,argv[2],NULL);
	if(ex<0){
		perror("Execl error");
		exit(1);
	}
	return 0;
}
