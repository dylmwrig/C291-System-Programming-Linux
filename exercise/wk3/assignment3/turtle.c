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

/*
 * commands:
 * 1 pen up
 * 2 pen down
 * 3 turn right
 * 4 turn left
 * 5, x move forward x spaces
 * 6 print the 50-by-50 array
 * 9 halt input and print everything
 */


/*
 * move the turtle
 * moveNum represents the amount of spaces to move
 * direction is the direction turtle is facing (1 = right, 2 = down, 3 = left, 4 = up)
 */
void move(int board[100][1000], int moveNum, int direction, bool penDown)
{

} //end move

void printBoard(int board[100][1000], int positionX, int positionY)
{
  //check that the position is within bounds
  //we're printing 50x50 so do these checks to avoid seg faults
  if (positionX > 49)
  {
    positionX = 49;
  } //end if

  if (positionY > 949)
  {
    positionY = 949;
  } //end if

  int endX = (positionX + 50), endY = (positionY + 50), startX = positionX;

  for (positionY; positionY < endY; positionY++)
  { 
    for (positionX; positionX < endX; positionX++)
    {
      printf("%d", board[positionX][positionY]);
    } //end for
    positionX = startX;
    printf("\n");
  } //end for
} //end printBoard

int main()
{
  //track the turtle's current position
  int positionX = 0;
  int positionY = 0;
  int choice;
  int direction = 1; //1 = right
		     //2 = down
		     //3 = left
		     //4 = up
  int distance = -1;  

  int board[100][1000] = {0};

  bool penDown = false;
 
  char input[7]; //longest possible input will be of format 5, x where x can't be more than 3 digits

  while (choice != 9)
  {
    printf("Enter command (9 to end input): ");
    scanf(" %s", &input);
    if (input[0] == '5')
    {
      int parseIndex = 2;
      char toMove[3];
      int moveIndex = 0;
      printf(" %s", input);
      while (isdigit(input[parseIndex]))
      {
        printf("here is the char %c \n", input[parseIndex]);
        printf("Digit: %c \n", input[parseIndex]);
        toMove[moveIndex] = input[parseIndex];
        parseIndex++;
        moveIndex++;
      } //end while

      int moveNum = atoi(toMove);

      move(board, moveNum, direction, penDown);
    } //end if 

    if (choice == 1)
    {
      penDown = true;
    } //end if

    else if (choice == 2)
    {
      penDown = false;
    } //end else if

    else if (choice == 3)
    {
      if (direction == 4)
      {
        direction = 1;
      } //end if

      else
      {
        direction++;
      } //end else
    } //end else if

    else if (choice == 4)
    {
      if (direction == 1)
      {
        direction = 4;
      } //end if

      else
      {
        direction--;
      } //end else
    } //end else if

    else if (choice == 6)
    {
      printBoard(board, positionX, positionY);
    } //end else if
  } //end while 
 
  return 0;
} //end main
