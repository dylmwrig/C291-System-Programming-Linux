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
 * position[2] is essentially the return, just fill it with the resulting x and y position
 */
void move(int board[100][1000], int posX, int posY, int moveNum, int direction, bool penDown, int * position)
{
  int endX = posX;
  int endY = posY;
  if (direction == 1)
  {
    endX += moveNum;
    if (penDown)
    {
      for (posX; posX > endX; posX++)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end if

  else if (direction == 2)
  { 
    endY += moveNum;
    if (penDown)
    {
      for (posY; posY < endY; posY++)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 3)
  {
    endX -= moveNum;
    if (penDown)
    {
      for (posX; posX > endX; posX--)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 4)
  {
    endY -= moveNum;
    if (penDown)
    {
      for (posY; posY > endY; posY--)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else

  position[0] = endX;
  position[1] = endY;
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
      if (board[positionX][positionY] == 1)
      {
        printf("*");
      } //end if
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
        toMove[moveIndex] = input[parseIndex];
        parseIndex++;
        moveIndex++;
      } //end while

      int moveNum = atoi(toMove);

      int newPos[2];
      move(board, positionX, positionY, moveNum, direction, penDown, newPos);
      positionX = newPos[0];
      positionY = newPos[1];
    } //end if 

    else
    {
      choice = (input[0] - '0'); //standard way to convert char to int in c
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

        printf("Direction is: %d", direction);
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
    } //end else
  } //end while 
 
  return 0;
} //end main
