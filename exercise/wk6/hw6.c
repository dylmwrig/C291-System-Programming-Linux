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

//print the letters
//phoneNum is the original number inputted by the user
//indexes is one instance of a permutation of 7 digits
//where each element is an index between 0 and 3
//printLetters prints the associated letter corresponding to the current number in phoneNum
//and its index (ie if phoneNum[0] = 2 and indexes[0] = 1, print 'B'
void printLetters(int phoneNum[7], int indexes[7])
{
  char c [4];
  int i;
  for (i = 0; i < 7; i++)
  {
    switch (phoneNum[i])
    {
      case 2:
        c[0] = 'A';
        c[1] = 'B';
        c[2] = 'C';
        break;
      case 3:
        c[0] = 'D';
        c[1] = 'E';
        c[2] = 'F';
        break;
      case 4:
        c[0] = 'G';
        c[1] = 'H';
        c[2] = 'I';
        break;
      case 5:
        c[0] = 'J';
        c[1] = 'K';
        c[2] = 'L';
        break;
      case 6:
        c[0] = 'M';
        c[1] = 'N';
        c[2] = 'O';
        break;
      case 7:
        c[0] = 'P';
        c[1] = 'Q';
        c[2] = 'R';
        c[3] = 'S';
        break;
      case 8:
        c[0] = 'T';
        c[1] = 'U';
        c[2] = 'V';
        break;
      case 9:
        c[0] = 'W';
        c[1] = 'X';
        c[2] = 'Y';
        c[3] = 'Z';
        break;
    } //end switch
    printf("%c",c[indexes[i]]);
  } //end for
} //end printLetters

int main()
{
  int nums[7] = {9,8,7,6,5,4,3};
  int indexes[7] = {0,0,0,0,0,0,0};
  printLetters(nums, indexes);

  printf("Please enter 7 single digits separated by returns\n");
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
 
    if (num[i] > 9)
    {
      printf("\nOnly single digits allowed.");
      return 0;
    } //end if
  } //end for

  
  return 0;
} //end main
