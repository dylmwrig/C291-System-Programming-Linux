/*Debugging quiz - File No: 1 */
/* The program should print the sum of all even numbers between 1 to 100 */

#include<stdio.h>

int main(void){
  int limit = 100, sum;
  for(int counter = 3; counter < limit; counter = counter+3){
    sum = sum+counter;
  printf("Sum = %d\n", counter);
  }