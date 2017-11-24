/*
 * Dylan Wright
 * Systems Programming Assignment 5
 */

#include <stdio.h>

//struct given with assignment
struct customer 
{
  char lastName[ 15 ];
  char firstName[ 15 ];
  unsigned int customerNumber;
  struct 
  {
    char phoneNumber[ 11 ];
    char address[ 50 ];
    char city[ 15 ];
    char state[ 3 ];
    char zipCode[ 6 ];
  } personal;
//member initialization used for testing
} customerRecord = { "Castle", "Frank", 10, {"1234123", "In The Hole", "Big Hole", "BIG", "123456"}} , *customerPtr;

int main()
{
  customerPtr = &customerRecord;
  //part a
  printf("Last name: %s", customerRecord.lastName);
  //part b
  printf("\nLast name using pointer: %s", customerPtr->lastName);
  //part c
  printf("\nFirst name: %s", customerRecord.firstName);
  //part d
  printf("\nFirst name using pointer: %s", customerPtr->firstName);
  //part e  
  printf("\nCustomer Number: %d", customerRecord.customerNumber);
  //part f
  printf("\nCustomer Number using pointer: %d", customerPtr->customerNumber);
  //part g
  printf("\nPhone number of personal of customerRecord: %s", customerRecord.personal.phoneNumber);
  //part h
  printf("\nPhone number of personal using pointer: %s", customerPtr->personal.phoneNumber);
  //part i
  printf("\nAddress of personal of customerRecord: %s", customerRecord.personal.address);
  //part j
  printf("\nAddress of personal using pointer: %s", customerPtr->personal.address);
  //part k
  printf("\nCity of personal of customerRecord: %s", customerRecord.personal.city);
  //part l
  printf("\nCity of personal using pointer: %s", customerPtr->personal.city);
  //part m
  printf("\nState of personal of customerRecord: %s", customerRecord.personal.state);
  //part n
  printf("\nState of personal using pointer: %s", customerPtr->personal.state);
  //part o
  printf("\nzipCode of personal of customerRecord: %s", customerRecord.personal.zipCode);
  //part p
  printf("\nzipCode of personal using pointer: %s", customerPtr->personal.zipCode);

  return 0;
} //end main
