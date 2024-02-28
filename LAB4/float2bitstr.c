#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
void makeNumber(double num){
  int* arr=malloc(sizeof(int)*32);
  if(num==0){
    for(int i=0;i<32;i++){
      printf("%d",arr[i]);
    }
    puts("");
    exit(1);
  }
  if(num<0){
    arr[0]=1;
  }
  else{
    arr[0]=0;
  }
  if(num<0){
    num*=-1;
  }
  if(num>=1||num<=-1){
    if(num<0){
      num*=-1;
    }
    int temp1=(int)num;
    double temp2=fmod(num,1);
    int* decBin=malloc(sizeof(int)*23);
    int count=0;
    int* tempArr=malloc(sizeof(int)*23);

    while(temp1!=0){
      tempArr[count]=temp1%2;
      temp1/=2;
      count++;
    }

    for(int i=count-1;i>=0;i--){
      decBin[count-i-1]=tempArr[i];
    }
    int decSpot=count;

    int firstOne=-1;
    for(int i=0;i<23;i++){
      if(decBin[i]==1){
        firstOne=i;
        break;
      }
    }
    int difference=decSpot-firstOne-1;
    int* decBinTemp=malloc(sizeof(int)*23);
    for(int i=firstOne+1;i<23;i++){
      decBinTemp[i-firstOne-1]=decBin[i];
    }
    temp2=fmod(num,1);
    for(int i=decSpot-1;i<23;i++){
      if(temp2*2==1){
        decBinTemp[i]=1;
        break;
      }
      else if(temp2*2>1){
        decBinTemp[i]=1;
        temp2*=2;
        temp2=fmod(temp2,1);
      }
      else if(temp2*2<1){
        decBinTemp[i]=0;
        temp2*=2;
      }
    }
    int exponent=difference+127;
    int* exponentArr=malloc(sizeof(int)*8);
    int* exponentArrTemp=malloc(sizeof(int)*8);
    int expCount=0;
    while(exponent!=0){
      exponentArrTemp[expCount]=exponent%2;
      exponent/=2;
      expCount++;
    }
    for(int i=0;i<8;i++){
      exponentArr[i]=exponentArrTemp[7-i];
    }
    for(int i=1;i<9;i++){
      arr[i]=exponentArr[i-1];
    }
    for(int i=9;i<32;i++){
      arr[i]=decBinTemp[i-9];
    }
    for(int i=0;i<32;i++){
      printf("%d",arr[i]);
    }
    puts("");
  }
  else{
    if(num<0){
      num*=-1;
    }
    
    double temp2=fmod(num,1);
    int* decBin=malloc(sizeof(int)*23);


    int firstOneCount=0;
    int count2=0;
    int offset=0;
    for(int i=0;i<23;i++){
      if(temp2*2==1){
        if(firstOneCount>=1){
          decBin[i]=1;
        }
        else{
          offset++;
          i--;
        }
        firstOneCount++;
        break;
      }
      else if(temp2*2>1){

        if(firstOneCount>=1){
          decBin[i]=1;
        }
        else{
          offset++;
          i--;
        }
        firstOneCount++;
        temp2*=2;
        temp2=fmod(temp2,1);
      }

      else if(temp2*2<1){
        if(firstOneCount>=1){
          decBin[i]=0;
        }
        else{
          offset++;
          i--;
        }
        temp2*=2;
      }
      count2++;
    }


    offset*=-1;
    int exponent=offset+127;
    int* exponentArr=malloc(sizeof(int)*8);
    int* exponentArrTemp=malloc(sizeof(int)*8);
    int expCount=0;
    while(exponent!=0){
      exponentArrTemp[expCount]=exponent%2;
      exponent/=2;
      expCount++;
    }
    for(int i=0;i<8;i++){
      exponentArr[i]=exponentArrTemp[7-i];
    }
    for(int i=1;i<9;i++){
      arr[i]=exponentArr[i-1];
    }
    for(int i=9;i<32;i++){
      arr[i]=decBin[i-9];
    }
    for(int i=0;i<32;i++){
      printf("%d",arr[i]);
    }
    puts("");
  }

}




int main(int argc,char** argv){
  if(argc!=2){
    perror("Invalid argument amount");
    exit(-1);
  }
  double number=atof(argv[1]);
  makeNumber(number);
}
