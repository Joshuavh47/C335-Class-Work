#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

struct arguments{
	FILE* file;
	char* word;
};

void* countOccurrences(void* args){
	FILE* fptr=((struct arguments*)args)->file;
	char* word=((struct arguments*)args)->word;
	char str[100000];
	char *pos;

	int index, count;

	count = 0;

	while ((fgets(str, 100000, fptr)) != NULL){
		index = 0;

		while ((pos = strstr(str+index,word))!=NULL){
			//Since pos is the pointer to the word being found, pos is at position str+(first occurence of word)
			//Thus, if we start searching after pos-str+1, each previous occurence isn't included in the new strstr call.
			//(Which is why we set index to (pos-str+1))
			index = (pos-str) + 1;

			count++;
		}
	}
	
	printf("%s count: %d\n",word,count);
	return NULL;
}


int main(int argc,char* argv[]){
	if(argc!=5){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}
	FILE* f1;
	f1=fopen(argv[1],"r");
	if(f1==NULL){
		perror("File read error");
		exit(EXIT_FAILURE);
	}
	struct arguments* thread1Args=(struct arguments*) malloc(sizeof(struct arguments));
	thread1Args->file=f1;
	thread1Args->word=argv[2];

	FILE* f2;
	f2=fopen(argv[3],"r");
	if(f2==NULL){
		perror("File read error");
		exit(EXIT_FAILURE);
	}
	struct arguments* thread2Args=(struct arguments*) malloc(sizeof(struct arguments));
	thread2Args->file=f2;
	thread2Args->word=argv[4];

	pthread_t tid1;
	pthread_t tid2;
	int thread1=pthread_create(&tid1,NULL,countOccurrences,(void*)thread1Args);
	pthread_join(tid1,NULL);
	int thread2=pthread_create(&tid2,NULL,countOccurrences,(void*)thread2Args);
	pthread_join(tid2,NULL);
	if(thread1!=0||thread2!=0){
		perror("Error creating thread(s)");
		exit(EXIT_FAILURE);
	}
	return 0;
	
}

