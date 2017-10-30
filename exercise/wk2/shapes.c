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
   
    if (tolower(input) == 'b')
    {
      box();
    } //end if 

    else if (tolower(input) == 'o')
    {
      oval();
    } //end else if
    
    else if (tolower(input) == 'l')
    {
      line();
    } //end else if

    else if (tolower(input) == 't')
    {
      triangle();
    } //end else if

    else if (tolower(input) == 'h')
    {
      hut();
    } //end else if 

    //if input is undefined, keep going
    else
    {
      continue;
    } //end else 
  } //end while

  return 0;
} //end main

