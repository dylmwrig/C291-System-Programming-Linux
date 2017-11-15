// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define SUITS 4
#define FACES 13
#define CARDS 5

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
   const char *wSuit[]); // dealing doesn't modify the arrays

//this function will read through the cards passed and determine the value of a given hand
//this will satisfy every requirement for part 4 of assignment 4
//no return value, prints the highest value the hand has
//the parameters are integer arrays holding the row and column indeces for each card
void findVal(const char *wFace[], const char *wSuit[], int * rows, int * columns)
{
  int i = 0, j = 0, suitCount = 0, bestCount = 0;
  bool twoPair = false; 
  int existingPairIndex = -1; //when a pair is found, mark it, in the case that there is a second pair
  //count the amount of cards with the same suit, card by card
  //because each card will count itself as matching the same suit, simply count a pair as suitCount = 2, three of a kind as suitCount = 3, etc
  for (i = 0; i < CARDS; i++)
  {
    for (j = 0; j < CARDS; j++)
    {
      //strcmp gives errors if the strings are of a different size
      //so only check equality if the size of each string is the same
      if (strlen(wSuit[rows[i]]) == strlen(wSuit[rows[j]]))
      { 
        if(strcmp(wSuit[rows[i]], wSuit[rows[j]]) == 0)
        {
          suitCount++;

          //checking for two pairs
          //we are not checking for full houses so if there are more than 2 of the same suit, stop checking for two pairs
          //
          //existingPairIndex is the index of the pair that has been found so far for comparisons
          //if they are not equal, then a second pair has been found
          if (suitCount > 2)
          {
            existingPairIndex = -1;
            twoPair = false;
          } //end if

          else if (suitCount == 2)
          {
            if ((existingPairIndex != -1) && (strcmp(wSuit[rows[existingPairIndex]], wSuit[rows[i]]) != 0))
            {
              twoPair = true;
            } //end if
  
            else
            {
              existingPairIndex = i;
            } //end else
          } //end else if
        } //end if
      } //end if
    } //end for
    if (suitCount > bestCount)
    {
      bestCount = suitCount;
    } //end if

    suitCount = 0;
  } //end for

  int minNum = 30, maxNum = -1;
  bool straight = true; 
  //check for a straight
  //columns passes in an array of integers corresponding to indeces in the faces array
  //so 0 = ace, 1 = 2, etc
  //meaning that if every number is within 4 digits of each other, there is a straight
  //first identify the smallest and largest numbers which we'll use to determine if the numbers in the array are in range
  for (int i = 0; i < CARDS; i++)
  {
    if (columns[i] < minNum)
    {
      minNum = columns[i];
    } //end if

    if (columns[i] > maxNum)
    {
      maxNum = columns[i];
    } //end if

    //a straight cannot include two of the same number
    for (int j = 0; j < CARDS; j++)
    {
      if ((columns[i] == columns[j]) && (i != j))
      {
        straight = false;
      } //end if
    } //end for
  } //end for

  if (straight)
  {
    for (int i = 0; i < CARDS; i++)
    {
      if (((columns[i] - minNum) > 4) || ((maxNum - columns[i]) > 4))
      {
        straight = false;
      } //end if
    } //end for
  } //end if

  //only print one rank, and print the one which has the highest value
  if (bestCount == 5)
  {
    printf("\n\nYou got a flush!");
  } //end if

  else if (bestCount > 3)
  {
    printf("\n\nYou got a four of a kind!");
  } //end else if
 
  else if (straight)
  {
    printf("\n\nYou got a straight!");
  } //end else if

  else if (bestCount > 2)
  {
    printf("\n\nYou got a three of a kind!");
  } //end else if
 
  else if (twoPair)
  {
    printf("\n\nYou got two pairs!");
  } //end else if

  else if (bestCount > 1)
  {
    printf("\n\nYou got a pair!");
  } //end else if 
} //end findVal

int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};

   deal(deck, face, suit); // deal the deck
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
   const char *wSuit[])
{
   //int arrays to store the indeces of the cards dealt
   int rows[CARDS], columns[CARDS];
   int rowColIndex = 0;

   // deal each of the cards
   for (size_t card = 1; card <= CARDS; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 2 == 0 ? '\n' : '\t'); // 2-column format
             
               //save the row and column of each card dealt
               columns[rowColIndex] = column;
               rows[rowColIndex] = row;
               rowColIndex++;
            } 
         } 
      } 
   }

  findVal(wFace, wSuit, rows, columns);
}

