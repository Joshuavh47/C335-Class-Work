#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char** argv){
	if((argv[1]==NULL)||(((strcmp(argv[1],"printf")==0)||(strcmp(argv[1],"fprintf")==0))&&argc!=3)||((strcmp(argv[1],"scanf")==0)&&argc!=2)){
		printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if(strcmp(argv[1],"scanf")!=0&&strcmp(argv[1],"printf")!=0&&strcmp(argv[1],"fprintf")!=0){
		printf("Error: Unknown argument\n");
                exit(EXIT_FAILURE);
	}
	if(strcmp(argv[1],"printf")==0){
		printf("You entered: %s\n",argv[2]);
	}
	FILE* fp;
	if(strcmp(argv[1],"fprintf")==0&&(fp=fopen("print.txt","w"))!=NULL){
		fprintf(fp,"%s",argv[2]);
		fclose(fp);
	}
//	else if(fp==NULL){
//		printf("Error: Couldn't create file\n");
//              exit(EXIT_FAILURE);
//	}
	if(strcmp(argv[1],"scanf")==0){
		char* input=malloc(sizeof(char)*1000);
		printf("%s","Please enter your input: ");
		scanf("%[^\n]",input);
		printf("You entered: %s\n",input);
		free(input);
	}
	return 0;
}
