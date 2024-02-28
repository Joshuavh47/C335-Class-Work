
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 3
 */
int bitAnd(int x, int y) {
  //I used de morgans law to get x&y
  return ~(~x|~y);
}

/*
 * getByte - Extract nth byte from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 6
 */
int getByte(int x, int n) {
  //I shift x over by n*8 because there are 8 bits per byte,
  //then I mask all the unneeded bits by using & 0xFF
  return (x>>(n+n+n+n+n+n+n+n))&0xFF;
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + - << >>
 *  Points: 6
 */
int byteSwap(int x, int n, int m) {
  //There are 8 bits per byte. Each left shift is like multiplying by 2, and 2^3=8.
  n = n<<3;
  m = m<<3;
  //creating a mask to take the specific bytes by shifting x by n and m.
  //since 0xFF is 1111 1111, this will create the correct mast to apply to x
  int y = 0xFF & ((x>>n) ^ (x>>m));
  //switches each bit based on the xor with the mask we just created and n and m
  x = x ^ (y<<n);
  x = x ^ (y<<m);
  return x;

}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 10
 */
int logicalShift(int x, int n) {
  //since -1 is 1111 1111 1111 1111 1111 1111 1111 1111 because of 2's compliment,
  //we can shift this to the left to make a buffer of 0s at the end and then use
  //32-n to create the necesary amount of 0s to block out the number of bits we need to
  //Then, we take the compliment of the mask so that the 0's come first and then
  //& it with the compliment of the mask to remove the extra 1's that we get from
  //the arithmetic right shift.
  int mask = ~(-1 << n) << (32 - n);
  return  ~mask & ( (x >> n) | mask);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitCount(int x) {

  return 0;


}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + - << >>
 *   Points: 15
 */
int bang(int x) {
  //shifts x 31 places to the right to get the highest value bit. On the right
  //side of the or, we take the not of the x value so that any number besides 0
  //will have the highest place value of 1. Then we shift 31 to the right so we
  //can get this value alone. if we add 1 to this value, and the highest place
  //value for x is 1, we get a number that isn't 1, otherwise, it will be equal
  //to 1. Basically, bang will only output 1 x==0.
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

/*
 * bitParity - returns 1 if x contains an odd number of 1's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitParity(int x) {
  return 0;
}
