/*
 * Systems Programming in C and Unix
 * Quiz 6
 * Dylan Wright
 */

/*
 *
  i" printf or scanf statement for each of the following:
a) Print unsigned integer 80000 left justified in a 16-digit field with 7 digits.
b) Read a hexadecimal value into variable hex.
c) Print 600 with and without a sign.
d) Print 400 in hexadecimal form preceded by 0x.
e) Read characters into array m until the letter z is encountered.
f) Print 7.402 in a 9-digit field with preceding zeros.
g) Read a time of the form hh-mm-ss, storing the parts of the time in the integer variables hour, minute and second. Skip
the dash (-) in the input stream. Use the assignment suppression character.
h) Read a string of the form "characters" from the standard input. Store the string in character array s. Eliminate the
quotation marks from the input stream.
i) Read a time of the form hh:mm:ss, storing the parts of the time in the integer variables hour, minute and second. Skip
the colons (:) in the input stream. Do not use the assignment suppression character.
*/

#include <stdio.h>

int main()
{
  printf("80000 left justified, 16 digit field, 7 digits:\n");
  printf("%-16.7u\n", 80000);
  int hex;
  printf("Enter hex value: ");
  scanf("%x", &hex);
  printf("\nPrinting 600 with sign: %+d and without sign %d\n", 600, 600);
  printf("Printing 400 in hex form: %#x\n", 400);

  printf("Enter characters, enter a z when you are finished\n");
  char m[50]; //size 50 just to be safe
  char inputChar = 'a';
  int i = 0;
  while (inputChar != 'z')
  {
    scanf("%c", &inputChar);
    m[i] = inputChar;
    i++;
  } //end while
  m[i - 1] = '\0'; //m[i - 1] will be 'z' so just replace it with a terminating character  
  printf("Here is your string: %s\n", m);
  printf("7.402 in 9 digit field: %09.3f\n", 7.402);
  int hour = 0, minute = 0, second = 0;
  printf("Enter a time in the form hh-mm-ss: ");
  scanf("%d%*c%d%*c%d", &hour, &minute, &second);
  printf("Here is your time %d %d %d", hour, minute, second);
  printf("Enter string of the form \"your input\"\n");
  char s [50];
  scanf("%*c%s%*c", s);
  printf("\nEnter time again, in the form hh:mm:ss ");
  scanf("%d:%d:%d", &hour, &minute, &second);
  printf("\nHere is your time: %d %d %d", hour, minute, second);
  return 0;
} //end main
