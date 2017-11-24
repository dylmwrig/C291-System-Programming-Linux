/*
 * Dylan Wright
 * Assignment 5 part 2: computerization of health records
 *
 * prompt for person's information, create a "HealthProfile" variable
 * display info including:
 * --first and last name
 * --gender
 * --DOB
 * --height and weight
 * --BMI
 * --maximum heart rate
 * --target heart rate range
 */

#include <stdbool.h>
#include <stdio.h>

//used to hold patient's DOB
typedef struct date
{
  int day;
  int month;
  int year;
} Date;

typedef struct patientRecord
{
  bool male;  //true if male, false if female
  char lastName[ 15 ];
  char firstName[ 15 ];
  int height; //inches
  int weight; //pounds
  Date DOB;
} PatientRecord;

//HealthProfile struct should have accessor methods with pointers to members of patientRecord
//also have members for BMI, max heart rate, and target-heart-rate range
//when outputting info for the user, only output properties of this class
typedef struct HealthProfile
{
  bool * malePtr;
  char * lastNamePtr;
  char * firstNamePtr;
  int * heightPtr;
  int * weightPtr;
  Date * DOBPtr;
  int maxHeartRate;
  int targetHeartRange;
  float BMI;
} PatientProfile; 

int main()
{
  PatientRecord patient;
  PatientProfile profile;

  printf("Enter your first name: ");
  scanf("%s", &patient.firstName);
  profile.firstNamePtr = patient.firstName;
  printf("%s", profile.firstNamePtr); 
  //printf("%c", profile.firstNamePtr[0]);

  printf("\nEnter your height in inches: ");
  scanf("%d", &patient.height);
  profile.heightPtr = &patient.height;
  printf("You entered %d", *profile.heightPtr);
  return 0;
} //end main
