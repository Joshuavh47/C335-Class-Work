#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


void printUpper(){
	printf("%c\n",(char)(rand()%26+65));
}

void printLower(){
	printf("%c\n",(char)(rand()%26+97));
}

int main(int argc,char*argv[]){
	srand((unsigned int)time(NULL));
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	if(strcmp(argv[1],"-l")==0){
		for(int i=0;i<10;i++){
			printLower();
		}
	}
	else if(strcmp(argv[1],"-u")==0){
		for(int i=0;i<10;i++){
			printUpper();
		}
	}
	else{
		perror("Incorrect argument provided (use\"-l\" or \"-u\"");
		exit(EXIT_FAILURE);
	}
	return 0;
}