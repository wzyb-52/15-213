/* 
 * CS:APP Data Lab 
 * 
 * Carolt
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* ~(~(~x&y)&~(x&~y)) is OK too. */
  return ~(x&y) & ~(~x&~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /* !x can convert x to 1 when x is zero, while 0 when x is non-zero. */ 
  int y = !(x + 1); // y equals to 1 only if x equals to 0xFFFFFFFF.
  return !(~(x^(x+1+y)));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0xAA;
  int b = (a << 8) + a;
  int c = (b << 16) + b;
  return !~((c&x)^(~c));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* a, b, c are the sign flags for >6, 4&5, <4 bits. */
  /* int a = !(x>>6); */
  /* int b = !((x&0x30)^0x30); */
  /* int c = !(((x&0x0F)+6)>>4); */
  /* return a & b & c; */

  /* And here comes the version with 2 less operations. */
  int a = x>>6;
  int b = (x&0x30)^0x30;
  int c = ((x&0x0F)+6)>>4;
  return !(a | b | c);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* Use !x(0 or 1) to construct mask 0x0 and 0xFFFFFFFF. */
  int a = !x; // a equals to 0 or 1.
  a = ~a + 1; // fills the 32 bits using the least significant bit.
  return (a&z) + (~a&y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* x <= y is true when unsigned x + ~y doesn't cause overflow. */
  /* sf, of, and zf are sign-flag, overflow-flag, and zero-flag. */
  int a = x;
  int b = ~y + 1;
  int zf = !(x^y);
  int c = a + b;
  int sf = (c >> 31) & 1;
  int d = x >> 31;
  int e = y >> 31;
  int of = (d ^ e) & (d ^ sf) & 1;
  //printf("sf: %x, of: %x, zf: %x\n", sf, of, zf);
  return (sf^of) | zf; 
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* Only 0 and Tmin are the same as their inverse element. */
  /* Obeserve the result of x^(~x+1), find the similarity. */
  int y = ~x+1;
  return ~(((x^y)>>31)|(x>>31))&1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* To find the first or last 1? */
  int word;
  int wordMask;
  int newW;
  int byte;
  int newB;
  int hlfB;
  int newH;

  int bits;
  int flag;
  int mask;
  int addb;
  int tran;
  /* Tranverse the negative number to positive which has the same minimum
   * number of bits required to represent. For example, -16 -> 15.
   */
  mask = x >> 31;
  tran = ~(x+1) + 1;
  x = ((~mask)&x) | (mask&tran);
  /* 1. 32-bit long word to 16-bit word. */
  /* 1.1. first word. */
  wordMask = (0xFF<<8) + 0xFF;
  word = x & wordMask;
  bits = 1;
  /* 1.2. second word. */
  newW = (x>>16) & wordMask;
  flag = !newW;
  mask = ~(~flag + 1);
  bits = (17&mask) | (bits&~mask);
  word = (newW&mask) | (word&~mask);
  /* 2. 16-bit word to 8-bit byte. */
  /* 2.1. first byte. */
  byte = word & 0xFF;
  addb = 0;
  /* 2.2. second byte. */
  newB = (word>>8) & 0xFF;
  flag = !newB;
  mask = ~(~flag + 1);
  addb = 8 & mask;
  byte = (newB&mask) | (byte&~mask);
  bits = bits + addb;
  /* 3. 8-bit byte to 4-bit half-byte. */
  /* 3.1. first half-byte. */
  hlfB= byte & 0x0F;
  addb = 0;
  /* 3.2. second half-byte. */
  newH = (byte>>4) & 0x0F;
  flag = !newH;
  mask = ~(~flag + 1);
  addb = 4 & mask;
  hlfB = (newH&mask) | (hlfB&~mask);
  bits = bits + addb;
  /* Determine the exact largest 1 bit in the half-byte. */
  addb = 0;
  addb = 1 & hlfB;
  mask = (hlfB << 30) >> 31;
  addb = (mask & 2) | (~mask & addb);
  mask = (hlfB << 29) >> 31;
  addb = (mask & 3) | (~mask & addb);
  mask = (hlfB << 28) >> 31;
  addb = (mask & 4) | (~mask & addb);
  //printf("bits: %d, hlfB: %x, addb: %d\n", bits, hlfB, addb);

  return bits + addb;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned expn = uf & 0x7f800000;
  // unsigned frac = uf & 0x007fffff;
  /* Deal with the floating point number if it isn't NAN. */
  if (expn == 0) {
    /* 1. uf ranges from 0 to 1-e. */
    uf = uf << 1;
  } else if (expn != 0x7f800000) {
    /* 2. uf ranges from 1 to 1-e. */
    uf = uf + 0x00800000;
  }
  /* Restore the sign bit. */
  if (sign == 0x80000000) {
    uf = uf | 0x80000000;
  } else {
    uf = uf & 0x7fffffff;
  }
  return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned expn = uf & 0x7f800000;
  unsigned frac = uf & 0x007fffff;
  unsigned E;
  int retv;

  if (expn == 0x7f800000) {
    /* 1. Infinity and NAN. */
    retv = 0x80000000u;
  } else if (expn < 0x3f800000) {
    /* 2. uf is in the range of -1 and 1. */
    retv = 0;
  } else {
    /* 3. uf is no less than 1 and no more than -1. */
    E = (expn >> 23) - 127;
    retv = frac + 0x00800000;
    if (E < 23) {
      retv = retv >> (23 - E);
    } else if (E < 31) {
      retv = retv << (E - 23);
    } else {
      retv = 0x80000000u;
    }
    /* Considering the negative numbers. */
    if (sign == 0x80000000) {
      retv = ~retv + 1;
    }
  }
  return retv;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  unsigned retv;
  if (x < -149) {
    retv = 0;
  } else if (x <= -126) {
    /* In fact, to make the classification of situations more clear, better
     * to use "x < -126" here. And I think it's an interesting coincidence
     * that both < and <= are right here.
     */
    retv = 1 << (149 + x);
  } else if (x > 127) {
    retv = 0x7f800000;
  } else {
    retv = (x + 127) << 23;
  }
  return retv;
}
