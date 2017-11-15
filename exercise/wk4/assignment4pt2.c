/*
 * Dylan Wright
 * Systems programming assignment 4 part 2
 */

#include <stdio.h>

int main()
{
  long value1 = 200000, value2;

  //part a
  long * lPtr = NULL;
  
  //part b
  lPtr = &value1;

  //part c
  printf("Value at lPtr: %d", *lPtr);

  //part d
  *lPtr = value2;
 
  //part e
  printf("\nlPtr after reassignment %d", *lPtr);
 
  //part f
  printf("\nAddress of value1 %p", &value1);

  //part g
  printf("\nAddress in lPtr %p", lPtr);
  return 0;
} //end main
