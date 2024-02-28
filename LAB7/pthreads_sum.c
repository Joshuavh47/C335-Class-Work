#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#ifdef ASIZE
	int array[ASIZE];
	#ifdef NTHREADS
	typedef struct Arguments{
		int arr[ASIZE];
		int threads;
		int size;
		int threadNum;
		int result;

	}Arguments;
	#endif
	#ifndef ASIZE
		perror("ASIZE not defined");
		exit(EXIT_FAILURE);
	#endif
#endif




#ifdef ASIZE
	#ifdef NTHREADS
		void* addArr(void* args){
			Arguments* arg=((Arguments*)args);
			if(arg->threadNum!=arg->threads-1){
				for(int i=(arg->threadNum)*(arg->size/arg->threads);i<(1+arg->threadNum)*(arg->size/arg->threads);i++){
					arg->result+=arg->arr[i];
				}
			}
			else{
				for(int i=arg->threadNum*(arg->size/arg->threads);i<arg->size;i++){
					arg->result+=arg->arr[i];
				}
			}
			pthread_exit(NULL);
			return NULL;
	
		}
	#endif
#endif


int main(int argc, char* argv[]){
	if(argc!=2){
		perror("Incorrect argument amount");
		exit(EXIT_FAILURE);
	}

	#ifdef ASIZE
		int array[ASIZE];
	#endif
	#ifndef ASIZE
		perror("ASIZE not defined");
		exit(EXIT_FAILURE);
	#endif
	#ifdef NTHREADS
		pthread_t tids[NTHREADS];
	#endif
	#ifndef NTHREADS
	perror("NTHREADS not defined");
	exit(EXIT_FAILURE);
	#endif

	#ifdef ASIZE
		for(int i=0;i<ASIZE;i++){
			array[i]=i*atoi(argv[1]);
		}
	#endif
	#ifndef ASIZE
		perror("ASIZE not defined");
		exit(EXIT_FAILURE);
	#endif
	
	#ifdef NTHREADS
		#ifdef ASIZE
			Arguments argArr[NTHREADS];
			for(int i=0;i<NTHREADS;i++){
				Arguments args;
				args.threads=NTHREADS;
				args.size=ASIZE;
				for(int i=0;i<ASIZE;i++){
					args.arr[i]=array[i];
				}
				args.threadNum=i;
				argArr[i]=args;
			}
			for(int i=0;i<NTHREADS;i++){
				if(pthread_create(&tids[i],NULL,addArr,(void *)&argArr[i])!=0){
					perror("Unable to create thread");
					exit(EXIT_FAILURE);
				}
				pthread_join(tids[i],NULL);
			}
			int total=0;
			for(int i=0;i<NTHREADS;i++){
				total+=argArr[i].result;

			}
			printf("%d\n",total);
		#endif
	#endif
	#ifndef NTHREADS
		perror("NTHREADS not defined");
		exit(EXIT_FAILURE);
	#endif
	

	return 0;
}