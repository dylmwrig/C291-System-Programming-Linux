/*
 * Dylan Wright
 * Systems programming assignment 3
 *
 * Turtle Graphics:
 * create a "sketchpad" using a 100 by 1000 array initialized to zeroes
 * read instructions from an array
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
  //track the turtle's current position
  int curPositionX = 0;
  int curPositionY = 0;

  bool penDown = false;

  int * inputList = malloc(sizeof(int) * 50);
  int maxIndex = 0;
  const int intSize = sizeof(int);
  int sizeMod = 0; 

  while (*(inputList + sizeMod) != 9)
  {
    printf("Enter command (9 to end input): ");
    scanf(" %d", *(inputList + sizeMod));
    printf("Here is your choice: %d", *(inputList + sizeMod));    
    
    maxIndex++;
    sizeMod = maxIndex * intSize;
/*
    if (maxIndex > 48)
    {
      //do malloc stuff lol idek if all of this dumb dynamic array stuff is necessary
    } //end if
*/
  } //end while

  return 0;
} //end main
