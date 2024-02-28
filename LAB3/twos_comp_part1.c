#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compliment(int num){
  char* out=malloc(sizeof(char)*9);
  out[8]='\0';
  for(int i=0;i<9;i++){
    out[i]='\0';
  }
  if (num==0){
    return "00000000";
  }
  else if(num>0){
    out[0]='0';
    for(int i=7;i>0;i--){
      out[i]=(num%2)+48;
      num/=2;
    }
  }
  else if(num<0){
    num+=128;

    for(int i=7;i>=1;i--){
      out[i]=(num%2)+48;
      num/=2;
    }
    out[0]='1';
  }
  return out;
}

int main(int argc, char** argv){
  if(argc==2){
    if(atoi(argv[1])>=-128&&atoi(argv[1])<=127){
      printf("%s\n",compliment(atoi(argv[1])));
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
