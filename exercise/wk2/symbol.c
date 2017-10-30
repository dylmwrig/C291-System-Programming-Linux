/*
 * Dylan Wright
 * Assignment 2
 * Problem 3
 * -prompt the user for a number of lines to print
 * -prompt for a symbol to print
 *
 */

#include <stdio.h>

//print the given symbol num_per_lines times
//do this on num_lines lines
//on every second print, tab one increasing time
//ie on the 2nd print, tab once, on the fourth tab twice
//do not tab on odd prints
void printSymbols(char symbol, int num_lines, int num_per_line)
{
  int i = 0;
  int tabNum = 0;
  for (i; i < num_lines; i++)
  {
   //visually, we are tabbing on each even numbered line
   //however, because arrays are zero indexed, instead check that i is odd
   if (i%2 != 0)
   {
     tabNum++;
     int k = 0;
     for (k; k < tabNum; k++)
     {
       printf("\t");
     } //end for
   } //end if
   int j = 0;
   for (j; j < num_per_line; j++)
   {
     printf("%c", symbol);
   } //end for
   printf("\n");
  } //end for
} //end printSymbols

int main()
{
  int num_lines = 0;
  int num_per_line = 0;
  char symbol = 'a';

  while (num_lines < 7)
  {
    printf("Please enter the number of lines to print: \n");
    scanf(" %d", &num_lines);
    if (num_lines < 7)
    {
      printf("The number of lines must be greater than 6. Please enter a valid number.\n");
    } //end if    
  } //end while

  printf("Please enter a symbol to be displayed: \n");
  scanf(" %c", &symbol);

  printf("Please enter a number to be printed per line (number must be between 7 and 27)");
  scanf(" %d", &num_per_line);
  if ((num_per_line < 7) || (num_per_line > 27))
  {
    num_per_line = 19;
  } //end if

  printSymbols(symbol, num_lines, num_per_line);

  return 0;
} //end main
