#include "bitops.h"


/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
  return x&y;
}

/*
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
  return x|y;
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
  return x^y;
}


/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
  //use 0xFF<<(8*b) to pad 1111 1111 with the necesary amount of 0s, then take
  //the compliment to make it so all of the bytes are 0xF except for the one we
  //just manipulated, then take the & with x to make the bits in the correct byte
  //equal to 0x0;
  x =x&~(0xFF << (8*b));
  return x;
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {

  //we do the same thing as in masking_or, except instead of taking the &, we
  //use | to set the bits regardless of their initial value. We don't use ~
  //because we want every bit except for the bits in the correct byte to be 0
  //so that everything stays the same except for the byte we are trying to manipulate.
  x =x|(0xFF << (8*b));
  return x;
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b){
  //The same concept as masking_or except using the ^ operator to toggle bits
  //because 0xFF=1111 1111, and 1^1=0 and 0^1=1 (flips each bit in the given byte)
  x =x^(0xFF << (8*b));
  return x;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
  return x<<sc;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
  return x>>sc;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
  return ~x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
  //for every bit in the 4 byte int (32 bits total,) I shifted right 31 place
  //values to get the last bit, then multiplied by 10 to move the place value of
  //the result 1 spot to the left. I repeat this, then multiply by -1 and
  //divide by 10 to account for the signed nature of the number.
  int result=(x>>31);
  result*=10;
  result+=(x<<1)>>31;
  result*=10;
  result+=(x<<2)>>31;
  result*=10;
  result+=(x<<3)>>31;
  result*=10;
  result+=(x<<4)>>31;
  result*=10;
  result+=(x<<5)>>31;
  result*=10;
  result+=(x<<6)>>31;
  result*=10;
  result+=(x<<7)>>31;
  result*=10;
  result+=(x<<8)>>31;
  result*=10;
  result+=(x<<9)>>31;
  result*=10;
  result+=(x<<10)>>31;
  result*=10;
  result+=(x<<11)>>31;
  result*=10;
  result+=(x<<12)>>31;
  result*=10;
  result+=(x<<13)>>31;
  result*=10;
  result+=(x<<14)>>31;
  result*=10;
  result+=(x<<15)>>31;
  result*=10;
  result+=(x<<16)>>31;
  result*=10;
  result+=(x<<17)>>31;
  result*=10;
  result+=(x<<18)>>31;
  result*=10;
  result+=(x<<19)>>31;
  result*=10;
  result+=(x<<20)>>31;
  result*=10;
  result+=(x<<21)>>31;
  result*=10;
  result+=(x<<22)>>31;
  result*=10;
  result+=(x<<23)>>31;
  result*=10;
  result+=(x<<24)>>31;
  result*=10;
  result+=(x<<25)>>31;
  result*=10;
  result+=(x<<26)>>31;
  result*=10;
  result+=(x<<27)>>31;
  result*=10;
  result+=(x<<28)>>31;
  result*=10;
  result+=(x<<29)>>31;
  result*=10;
  result+=(x<<30)>>31;
  result*=10;
  result+=(x<<31)>>31;
  result*=10;
  result/=10;
  result*=-1;
  printf("%d\n",result);
}
