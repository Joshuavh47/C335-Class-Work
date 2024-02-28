#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countLines(char* fileName,char* key){
  FILE* fp1;
  fp1=fopen(fileName,"r");
  if(fp1==NULL){
    exit(0);
  }
  int letterCount=0;
  int keyCount=0;
  char* line=malloc(sizeof(char)*1000);
  while(key[letterCount]!='\0'){
    letterCount++;
  }
  char* buff=malloc(sizeof(char)*(letterCount+1));
  while(!feof(fp1)){
    bool found=false;
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
        found=true;
      }
      for(int i=0;i<letterCount+1;i++){
        buff[i]='\0';
      }
      index++;

    }
    if(found){
      keyCount++;
    }


  }
  fclose(fp1);
  printf("%d\n",keyCount);
  return 0;
}

int main(int argc,char** argv){
  if(argc<3){
    exit(1);
  }
  if(argv[1]==NULL||argv[2]==NULL){
    exit(1);
  }
  if(argc==3){
    countLines(argv[1],argv[2]);
  }
  return 0;
}
