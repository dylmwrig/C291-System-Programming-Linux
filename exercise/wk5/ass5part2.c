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

#include <stdio.h>
#include <stdbool.h>//for bool data type
#include <string.h> //for strcpy

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

  //these properties are part of the HealthProfile stuct only so they don't need to be pointers
  int age;
  int maxHeartRate;
  int targetHeartRange[2]; //first element is low end of range, second element is high end
  float BMI;
} PatientProfile; 

//calculate the user's age
//just going to prompt for the date
int currentAge(Date DOB)
{
  Date currentDate;

  printf("\nWhat is the current month? ");
  scanf("%d", &currentDate.month);
  printf("\nWhat is the current day? ");
  scanf("%d", &currentDate.day);
  printf("\nWhat is the current year? ");
  scanf("%d", &currentDate.year);
  int age = (currentDate.year - DOB.year);
  //month and day checks to see if the person's birthday has happened yet
  if ((currentDate.month - DOB.month) > 0)
  {
    age--;
  } //end if

  else if ((currentDate.month - DOB.month) == 0)
  {
    if ((currentDate.day - DOB.day) > 0)
    {
      age--;
    } //end if
  } //end else if

  return age;
} //end currentAge

int maxHeartRate(int age)
{
  return (220 - age);
} //end maxHeartRate

//target heart range is 50-85% of max heart rate
//first element is the low end, second element is the high end
void targetHeartRange(int maxRate, int * heartRange)
{
  heartRange[0] = (maxRate * .5);
  heartRange[1] = (maxRate * .85);
} //end targetHeartRange

//return the patient's BMI
float BMICalc(int height, int weight)
{
  return ((weight * 703.0) / (height * height));
} //end BMICalc

void profileInput (PatientProfile * profile, PatientRecord * patient, Date * DOB)
{
  printf("Enter your first name: ");
  scanf("%s", &(patient->firstName));
  profile->firstNamePtr = patient->firstName;
  
  printf("\nEnter your last name: ");
  scanf("%s", &(patient->lastName));
  profile->lastNamePtr = patient->lastName;

  int genderInput;
  printf("\nAre you male or female? 1 for male, 2 for female: ");
  scanf("%d", &genderInput);
  if (genderInput == 1)
  {
    patient->male = true;
  } //end if 

  else
  {
    patient->male = false;
  } //end else
  profile->malePtr = &(patient->male);

  printf("\nEnter your month of birth: ");
  scanf("%d", &(DOB->month));

  printf("\nEnter your day of birth: ");
  scanf("%d", &(DOB->day));

  printf("\nEnter your year of birth: ");
  scanf("%d", &(DOB->year));

  patient->DOB = *DOB;
  profile->DOBPtr = &(patient->DOB);

  printf("\nEnter your height in inches: ");
  scanf("%d", &(patient->height));
  profile->heightPtr = &(patient->height);

  printf("\nEnter your weight in pounds: ");
  scanf("%d", &(patient->weight));
  profile->weightPtr = &(patient->weight);

  profile->age = currentAge(*(profile->DOBPtr));
  profile->maxHeartRate = maxHeartRate(profile->age);
  targetHeartRange(profile->maxHeartRate, profile->targetHeartRange);
  profile->BMI = BMICalc(*(profile->heightPtr), *(profile->weightPtr));
} //end profileInput

int main()
{
  PatientProfile profile;
  PatientProfile * profilePtr = &profile; //pointer just used to alter the profile instance
  PatientRecord patient;
  PatientRecord * patientPtr = &patient; 
  Date DOB;
  Date * DOBPtr = &DOB;

  profileInput(profilePtr, patientPtr, DOBPtr);
  printf("Outside of profileInput, first name: %s", profilePtr->firstNamePtr);  
  printf("\n\n\t\tResults\n\n");
  printf("First name: %s", profile.firstNamePtr);
  printf("\nLast name: %s", profile.lastNamePtr);
  
  //convert the boolean "male" to a printable string
  //I'm using strcpy to create printable values for some of the data
  //both to print gender and to print the BMI status
  char genderPrint[6];
  if (*(profile.malePtr))
  {
    strcpy(genderPrint, "male");
  } //end if

  else
  {
    strcpy(genderPrint, "female");
  } //end else

  printf("\nYour gender: %s", genderPrint);
  printf("\nYour DOB: %d/%d/%d", profile.DOBPtr->month, profile.DOBPtr->day, profile.DOBPtr->year);
  printf("\nYour height in inches: %d", *(profile.heightPtr));
  printf("\nYour weight in pounds: %d", *(profile.weightPtr));
  printf("\nYour BMI: %f", profile.BMI);
  printf("\nYour max heart rate: %d", profile.maxHeartRate);
  printf("\nYour target heart range: %d %d", profile.targetHeartRange[0], profile.targetHeartRange[1]);
  
  //used to print the status of the individual's BMI using the BMI values chart
  //11 character array because the longest string would be "underweight"
  char BMIPrint[11];

  if (profile.BMI > 30.0)
  {
    strcpy(BMIPrint, "Obese :(");
  } //end if

  else if (profile.BMI > 25.0)
  {
    strcpy(BMIPrint, "Overweight");
  } //end else if

  else if (profile.BMI > 18.5)
  {
    strcpy(BMIPrint, "Normal");
  } //end else if

  else
  {
    strcpy(BMIPrint, "Underweight");
  } //end else if
  printf("\n\nAccording to your BMI, you are %s", BMIPrint);

  return 0;
} //end main
