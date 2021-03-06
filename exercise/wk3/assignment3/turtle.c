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

  if (direction == 1) //right
  {
    endX += moveNum;
    if (penDown)
    {
      for (posX; posX < endX; posX++)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end if

  else if (direction == 2) //down
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

  else if (direction == 3) //left
  {
    endX -= moveNum;
    if (endX < 0) //disallow negative values
    {
      endX = 0; 
    } //end if

    if (penDown)
    {
      for (posX; posX > endX; posX--)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 4) //up
  {
    endY -= moveNum;
    if (endY < 0) //disallow negative values
    {
      endY = 0;
    } //end if

    if (penDown)
    {
      for (posY; posY > endY; posY--)
      {
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  //
  //diagonal functionality
  //
  else if (direction == 5) //up right
  {
    endX += moveNum;
    endY -= moveNum;

    if (penDown)
    {
      for (posY; posY > endY; posY--)
      {
        posX++;
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 6) //down right
  {
    endX += moveNum;
    endY += moveNum;

    if (penDown)
    {
      for (posY; posY < endY; posY++)
      {
        posX++;
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 7) //down left
  {
    endX -= moveNum;
    endY += moveNum;

    if (penDown)
    {
      for (posY; posY < endY; posY++)
      {
        posX--;
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if

  else if (direction == 8) //up left
  {
    endX -= moveNum;
    endY -= moveNum;

    if (penDown)
    {
      for (posY; posY > endY; posY--)
      {
        posX--;
        board[posX][posY] = 1;
      } //end for
    } //end if
  } //end else if
  position[0] = endX;
  position[1] = endY;
} //end move

void printBoard(int board[100][1000], int positionX, int positionY)
{
  //check that the position is within bounds
  //we're printing 50x50 so do these checks to avoid seg faults
  if (positionX > 50)
  {
    positionX = 50;
  } //end if

  if (positionY > 950)
  {
    positionY = 950;
  } //end if

  int endX = (positionX + 49), endY = (positionY + 49), startX = positionX;

  printf("\n");
  for (positionY; positionY < endY; positionY++)
  { 
    for (positionX; positionX < endX; positionX++)
    {
      if (board[positionX][positionY] == 1)
      {
        printf("*");
      } //end if
  
      else
      {
        printf(" ");
      } //end if
    } //end for
    positionX = startX; //reset sentry variable
    printf("\n");
  } //end for
} //end printBoard

//additional functionality, draw a shape
void drawShape(int board[100][1000])
{
  int choice;
  printf("What shape would you like to draw?\n"
         "1 - square\n"
         "2 - rectangle\n"
         "3 - diamond\n");
  scanf(" %d", &choice);
  if (choice == 1)
  {
    printf("\nWhat width would you like for each side?\n");
    scanf(" %d", &choice);
    int moveNum = choice;
    int pos[2];
    move(board, 0, 0, moveNum, 1, true, pos);
    move(board, pos[0], pos[1], moveNum, 2, true, pos);
    move(board, pos[0], pos[1], moveNum, 3, true, pos);
    move(board, pos[0], pos[1], moveNum, 4, true, pos);
    
    printBoard(board, 0, 0);
  } //end if
 
  else if (choice == 2)
  {
    printf("\nWhat width would you like?\n");
    scanf(" %d", &choice);
    int width = choice;
    printf("\nWhat height would you like?\n");
    scanf(" $d", &choice);
    int height = choice;
    int pos[2];
    move(board, 0, 0, width, 1, true, pos);
    move(board, pos[0], pos[1], height, 2, true, pos);
    move(board, pos[0], pos[1], width, 3, true, pos);
    move(board, pos[0], pos[1], height, 4, true, pos);
    
    printBoard(board, 0, 0);
  } //end else if
 
  else if (choice == 3)
  {
    printf("\nWhat width would you like?\n");
    scanf(" %d", &choice);
    int pos[2];
    move(board, choice, 0, choice, 6, true, pos);
    move(board, pos[0], pos[1], choice, 7, true, pos);
    move(board, pos[0], pos[1], choice, 8, true, pos);
    move(board, pos[0], pos[1], choice, 5, true, pos);
    
    printBoard(board, 0, 0);
  } //end if

} //end drawShape

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
    printf("Enter command:\n"
           "1 pen up \n"
           "2 pen down\n"
           "3 turn right\n"
           "4 turn left\n"
           "5, x move in current direction by x spaces\n"
           "6 print the 50-by-50 array\n"
           "7 draw a shape\n"
           "9 halt input and print everything\n");
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
        penDown = false;
      } //end if
  
      else if (choice == 2)
      {
        penDown = true;
      } //end else if
  
      else if (choice == 3) //turn right, each right turn adds one to direction
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
  
      else if (choice == 4) //turn left, each left turn subtracts one from direction
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

      else if (choice == 7)
      {
        drawShape(board);
      } //end else if
    } //end else
  } //end while 
 
  printBoard(board, positionX, positionY);

  return 0;
} //end main
