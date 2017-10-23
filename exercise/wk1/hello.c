/*
 * hello.c
 * Dylan Wright
 * assignment 1 for systems programming 
 * print hello world, then print a . every two seconds, on the same line
 * */


#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("Hello World!\n");
  while (true)
  {
    sleep(1);
    printf(".");
    fflush(stdout); //flush the stream to print properly
  } //end while
  return(0);
} //end main
