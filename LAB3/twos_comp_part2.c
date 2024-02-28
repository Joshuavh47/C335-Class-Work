#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert(char* bin,char* sign){
  int total=0;
  if(strcmp(sign,"unsigned")==0){
    int count1=0;
    while(bin[count1]!='\0'){
      count1++;
    }

    for(int i=count1-1;i>=0;i--){
      total+=(bin[i]-48)*pow(2,count1-1-i);
    }
  }
  else if(strcmp(sign,"signed")==0){
    if(bin[0]=='1'){
      int count1=0;
      while(bin[count1]!='\0'){
        count1++;
      }
      total=-1*pow(2,count1-1);
      for(int i=count1-1;i>0;i--){
        total+=(bin[i]-48)*pow(2,count1-1-i);
      }
    }
    else if(bin[0]=='0'){
      int count1=0;
      while(bin[count1]!='\0'){
        count1++;
      }
      for(int i=count1-1;i>0;i--){
        total+=(bin[i]-48)*pow(2,count1-1-i);
      }
    }
  }
  return total;
}

int main(int argc, char** argv){
  if(argc==3){
    if(strcmp(argv[2],"signed")!=0&&strcmp(argv[2],"unsigned")!=0){
      perror("Invalid integer type");
      exit(-1);
    }
    int count=0;
    while(argv[1][count]!='\0'){
      if(argv[1][count]!='1'&&argv[1][count]!='0'){
        perror("Invalid binary number");
        exit(-1);
      }
      count++;
    }
    if(count<=8){
      printf("%d\n",convert(argv[1],argv[2]));
    }
    else{
      perror("Number outside of 8-bit range.");
      exit(-1);
    }
  }
  else{
    perror("Invalid amount of arguments");
    exit(-1);
  }
  return 0;
}
