/*
 * Systems programming assignment 6
 * Dylan Wright
 *
 * Given a 7 digit number, output to a file every combination of characters possible from those numbers
 * number to letter corresponds to the following
 * 2  ABC   6  MNO
 * 3  DEF   7  PQRS
 * 4  GHI   8  TUV
 * 5  JKL   9  WXYZ
 */

#include <stdio.h>

int main()
{
  printf("Please enter a 7 digits separated by returns\n");
  int num[7];
  int i;
  for (i = 0; i < 7; i++)
  {
    scanf("%d",&num[i]);
    if (num[i] == 0 || num[i] == 1)
    {
      printf("\nSorry, no 0s or 1s allowed.");
      return 0;
    } //end if
  } //end for
  
  /*
   * so like if you had 2 3 4
   * it could return like ADG, BDG, CDG, AEG, AFG, ADH, ADI, etc etc
   */
 
  return 0;
} //end main
