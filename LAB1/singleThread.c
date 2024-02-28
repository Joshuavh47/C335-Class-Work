#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int count(char* fileName,char* key){
  FILE* fp1;
  fp1=fopen(fileName,"r");
  int letterCount=0;
  int keyCount=0;
  char* line=malloc(sizeof(char)*1000);
  while(key[letterCount]!='\0'){
    letterCount++;
  }
  char* buff=malloc(sizeof(char)*(letterCount+1));
  while(!feof(fp1)){
    int index=0;

    for(int i=0;i<1000;i++){
      line[i]='\0';
    }
    fgets(line,999,fp1);
    while(line[index+letterCount]!='\0'){
      for(int i=0;i<letterCount;i++){
        buff[i]=line[index+i];
      }
      if(strcmp(buff,key)==0){
        keyCount++;
      }
      for(int i=0;i<letterCount+1;i++){
        buff[i]='\0';
      }
      index++;
    }


  }
  fclose(fp1);
  //printf("%d\n",keyCount);
  return keyCount;
}


int main(int argc,char** argv){
  if(argc<5){
    exit(1);
  }
  if(argv[1]==NULL||argv[2]==NULL||argv[3]==NULL||argv[4]==NULL){
    exit(1);
  }
  if(argc==5){
    double time_spent = 0.0;
    clock_t begin = clock();
    printf("%s count: %d\n%s count: %d\n",argv[2],count(argv[1],argv[2]),argv[4],count(argv[3],argv[4]));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    time_spent*=1000;
    FILE *fpOUT;
    fpOUT=fopen("README.md","w+");
    fprintf(fpOUT,"%lf",time_spent);
    fclose(fpOUT);
  }
  return 0;
}
