// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
  //count the amount of cards with the same suit, card by card
  //because each card will count itself as matching the same suit, simply count a pair as suitCount = 2, three of a kind as suitCount = 3, etc
  for (i; i < CARDS; i++)
  {
    for (j; j < CARDS; j++)
    {
      //strcmp gives errors if the strings are of a different size
      //so only check equality if the size of each string is the same
      if (strlen(wSuit[rows[i]]) == strlen(wSuit[rows[j]]))
      { 
        if(strcmp(wSuit[rows[i]], wSuit[rows[j]]) == 0)
        {
          suitCount++;
        } //end if
      } //end if
    } //end for

    if (suitCount > bestCount)
    {
      bestCount = suitCount;
    } //end if

    suitCount = 0;
  } //end for
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

