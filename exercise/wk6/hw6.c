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
void printLetters(int phoneNum[7], int indexes[7], FILE * file)
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
    //fprintf(file, "%c",c[indexes[i]]);
    printf("%c",c[indexes[i]]);
  } //end for
  printf("\n");
} //end printLetters

//return the max index given the phone number (because certain digits have four letters associated with them)
int findMaxIndex(int num)
{
  if (num == 7 || num == 9)
  {
    return 3;
  } //end if

  else
  {
    return 2;
  } //end else
} //end findMaxIndex

//reset every element in the array to 0 except for those specified
//dontReset1 is the same as stableIndex, dontReset2 is (usually) the same as incIndex
void resetArr(int a[7], int dontReset1, int dontReset2)
{
  int i;
  for (i = 0; i < 7; i++)
  {
    if ((i != dontReset1) && (i != dontReset2))
    {
      a[i] = 0;
    } //end if
  } //end for
} //end resetArr

//permute a list of digits between 0 and 3 
//to determine the index of the character used in the printLetters function above
//phoneNum is a parameter so we can call printLetters, and so we know the max index size (2 or 3)
//have a "stable number" which will start on the far left of the array
//
//through an iteration of a loop, the number will not change but every single other one will iterate
//do this in sequential order: ie ind[1] should increase, then the number after that, until all are max index
//when every other number is max index, increase the stable number
//when this stable number reaches the max index (3 if # is 7 or 9, 2 otherwise)
//make the next index the next stable number, and continue until the final index is both the stable number and has reached its max index
void permute(int phoneNum[7], FILE * file)
{
  int i, j, maxIndex; //maxIndex is either 2 or 3 depending on if the # is 7, 9, or anything else
  int stableIndex = 0, dontReset = 0, stableMaxIndex = findMaxIndex(phoneNum[stableIndex]);
  int ind[7] = {0};
  int incIndex = 1; //index of the element which will be changed 
 
  //index array is initialized to all zeroes so call printLetters immediately
  printLetters(phoneNum, ind, file);
  while (1)
  {
    //the max index is either 2 or 3
    //if increasing the value of the index makes it go beyond bounds, move to the next element
    maxIndex = findMaxIndex(phoneNum[ind[incIndex]]);
    if (ind[incIndex] + 1 > maxIndex)
    {
      //if there is no next element to go on to, reset the array to all 0s, except for the stable index
      //increase the stableIndex val by one, and start the incrementer at the far left
      if (incIndex + 1 == 7)
      {
        if (stableIndex == dontReset)
        {
          resetArr(ind, stableIndex, stableIndex);
          dontReset++;
        } //end if

        else
        {
          maxIndex = findMaxIndex(phoneNum[ind[dontReset]]);
          if (ind[dontReset] + 1 > maxIndex)
          {
            if (dontReset + 1 == 7)
            {
              resetArr(ind, stableIndex, stableIndex);
              incIndex = 0;
              ind[stableIndex]++;
              dontReset = 0;
            } //end if

            else
            {
              dontReset++;
              resetArr(ind, stableIndex, dontReset);
            } //end else
          } //end if

          else
          {
            ind[dontReset]++;
            resetArr(ind, stableIndex, dontReset);
          } //end else
        } //end else

        //if the stableIndex value is both at its max value and at the end of the array
        //we have processed the entire thing
        //
        //if we haven't processed the entire thing, find the new max index of that value and keep going
        if (ind[stableIndex] > stableMaxIndex)
        {
          ind[stableIndex]--;
          stableIndex++;
          if (stableIndex == 7)
          {
            break;
          } //end if

          else
          {
            dontReset = 0;
            resetArr(ind, stableIndex, stableIndex);
            stableMaxIndex = findMaxIndex(phoneNum[stableIndex]);
          } //end else
        } //end if
      } //end if

      else
      {  
        while ((incIndex == stableIndex) || (incIndex == dontReset))
        {
          incIndex++; 
        } //end while
      } //end else

/*
      //just a safeguard
      maxIndex = findMaxIndex(phoneNum[ind[incIndex]]);
      if (ind[incIndex] == maxIndex)
      {
        incIndex++;
      }
*/
    } //end if
    ind[incIndex]++;
    printLetters(phoneNum, ind, file);
  } //end while 
} //end permute

int main()
{
  int nums[7] = {9,8,7,6,5,4,3};
  int indexes[7] = {0,0,0,0,0,0,0};
  char fileName[50];
  FILE * file;

  printf("First enter a file name with extension for results to be saved to: ");
  scanf("%s", fileName);
  file = fopen(fileName, "w");
  rewind(file);
  if (file == NULL)
  {
    printf("File did not open properly, now exiting");
    return 0;
  }

  fclose(file);
  
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

  permute(num, file); 
  fclose(file);

  return 0;
} //end main
