#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getSign(char* input){
  if(input[0]=='0'){
    return 0;
  }
  return 1;
}

int getExponent(char* input){
  int exponent=0;
  for(int i=1;i<9;i++){
    if(input[i]=='1'){
      exponent+=pow(2,8-i);
    }
  }
  return exponent;
}

double getMantissa(char* input){
  double mantissa=0;
  if(getExponent(input)==0){
    for(int i=9;i<32;i++){
      if(input[i]=='1'){
        mantissa+=(1.0/pow(2,i-8));
      }
    }
  }
  else{
    mantissa=1;
    for(int i=9;i<32;i++){
      if(input[i]=='1'){
        mantissa+=1/pow(2,i-8);
      }
    }
  }
  return mantissa;
}

double getNumber(char* input){
    int exponent=getExponent(input)-127;
    if(getExponent(input)==0){
      exponent+=1;
    }
    double number=getMantissa(input)*pow(2,exponent);
    if(getSign(input)==0){
      return number;
    }
    return number*-1;
}

int main(int argc, char** argv){
  if(argc!=2){
    perror("Incorrect argument amount");
    exit(-1);
  }
  int count=0;

  while(argv[1][count]!='\0'){
    count++;
  }
  if(count!=32){
    perror("Incorrect input argument");
    exit(-1);
  }

  for(int i=0;i<32;i++){
    if(argv[1][i]!='0'&&argv[1][i]!='1'){
      perror("Incorrect input argument");
      exit(-1);
    }
  }
  printf("Sign: %d\nExponent: %d\nMantissa: %.17g\nNumber: %.7g\n",getSign(argv[1]),getExponent(argv[1]),getMantissa(argv[1]),getNumber(argv[1]));
  return 0;
}
