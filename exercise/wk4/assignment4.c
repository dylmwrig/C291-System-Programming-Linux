/*
 * Dylan Wright
 * Systems Programming Assignment 4
 */

#include <stdio.h>

int main()
{
  const int SIZE = 5;
  unsigned int values [5] = {2, 4, 6, 8, 10}; //wanted to initialize size to SIZE but C disallows this

  unsigned int * vPtr = NULL;

  int i;
  for (i = 0; i < SIZE; i++)
  {
    printf(" %d", values[i]);
  } //end for
  return 0;
} //end main
