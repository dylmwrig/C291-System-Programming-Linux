/*
 * Dylan Wright
 * Assignment 2
 *
 * -Problem 2)
 * -copy paste problem 1
 * -change if else structure to switch case 
 */


/*
 * By: Dylan Wright
 * Systems Programming assignment 2
 * problem 1)
 * -prompt the user for a shape they wish to have drawn 
 * -must use if-else for interface
 * -keep prompting for shapes until user presses q
 */

#include <stdio.h>

void box()
{
  printf("********\n"
         "*      *\n"
         "*      *\n"
         "*      *\n"
         "*      *\n"
         "*      *\n"
         "*      *\n"
         "********\n");
} //end box

void oval()
{
  printf("  ***  \n"
         " *   * \n"
         "*     *\n"
         "*     *\n"
         "*     *\n"
         "*     *\n"
         "*     *\n"
         " *   * \n"
         "  ***  \n");
} //end oval

void line()
{
  int i = 0;
  for (i; i < 8; i++)
  {
    printf("*\n");
  } //end for
} //end line


void triangle()
{
  printf("       *       \n"
         "      * *      \n"
         "     *   *     \n"
         "    *     *    \n"
         "   *       *   \n"
         "  *         *  \n"
         " *           * \n"
         "***************\n");
} //end triangle

void hut()
{
  printf("    *    \n"
         "   ***   \n"
         "  *****  \n"
         " ******* \n"
         "*********\n"
         "***   ***\n"
         "***   ***\n"
         "***   ***\n");
} //end hut

int main()
{
  char input = ' ';

  //q is escape key, continue outputting until this is pressed  
  while(tolower(input) != 'q')
  {
      printf("Which would you like?\n"
             "b for box \n"
  	   "o for oval \n"
   	   "l for line \n"
             "t for triangle \n"
  	   "h for hut \n"
             "q to quit \n");
      fflush(stdout);
      scanf (" %c" ,&input); //must put a space after %c to catch the newline, seg fault otherwise
     
      input = tolower(input); //tolower ensures case insensitiviy
      switch (input)
      {
        case 'b':
          box();
          break;
        case 'o':
          oval();
          break;     
        case 'l':
          line();
          break;
        case 't':
          triangle();
          break;
        case 'h':
          hut();
          break;

       //if input is undefined, keep going
        default:
          fflush(stdin); //flush the input buffer just to be safe
          break;
      } //end switch
  } //end while
} //end main
