/*
 * Dylan Wright
 * Systems Programming Assignment 4
 */

#include <stdio.h>

int main()
{
  //part a
  const int SIZE = 5;
  unsigned int values [5] = {2, 4, 6, 8, 10}; //wanted to initialize size to SIZE but C disallows this

  //part b
  unsigned int * vPtr = NULL;

  //part c
  int i;
  for (i = 0; i < SIZE; i++)
  {
    printf(" %d", values[i]);
  } //end for

  //part d
  vPtr = values;
  vPtr = &values[0];
  printf("\nPart E\n");

  //part e
  for (i = 0; i < SIZE; i++)
  {
    printf(" %d", *(vPtr + i));
  } //end for
  
  printf("\nParg F\n");

  //part f 
   for (i = 0; i < SIZE; i++)
  {
    printf(" %d", *(values + i));
  } //end for

  printf("\nPart G\n");

  //part g
  for (i = 0; i < SIZE; i++)
  {
    printf(" %d", vPtr[i]);
  } //end for 
 
  //part h
  printf("\nElement 5 using array subscript: %d "
                           "pointer/offset: %d "
                          
, values[4], *(vPtr + 4));

  //part i
  printf("\nThe address referenced by vPtr + 3 is the 4th element of the array, or values[3], with the value of 8, here is that value: %d", *(vPtr + 3));

  //part j
  vPtr = &values[4];
  printf("\nThe address referenced by vPtr -= 4 is the base address of the array, or the first element, here is that value: %d", *(vPtr -= 4));

  return 0;
} //end main
