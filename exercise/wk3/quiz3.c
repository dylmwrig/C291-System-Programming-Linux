/* Instructions:
 *
 *1. Following on from what you have learnt in class today, write a program to return the grade associated with a range of marks.

  2. The range of marks and the associated grades are as follows:
     a. 91-100 = A
     b. 81-90 = B
     c. 71-80 = C
     d. less than or equal to 70 is a fail grade and should be given an F
     e. greater than 100 is invalid and your code should print "Invalid"
  
  3. Use the skeleton code provided below to create a new function "printGrade" with its appropriate 
     data type for input of marks. For example, printGrade(<data type> marks). 
  
  4. Use print statements in your function to display the grade. For example, if the input marks is 77, the output should read: 

	"Your grade is : C"

  5. Please adhere to standard C syntax conventions and use comments to explain your code. Failure to do so will result in a penalty.
 *
 *
 * */


#include<stdio.h>

//take in an array of number grades
//print letter grades corresponding to each number
void printGrade(int marks)
{
  if (marks > 100)
  {
    printf("Invalid");
  } //end if

  else if (marks > 90)
  {
    printf("You got an A!");
  } //end else if

  else if (marks > 80)
  {
    printf("You got a B!");
  } //end else if

  else if (marks > 70)
  {
    printf("You got a C!");
  } //end else if

  else
  {
    printf("You got an F :(");
  } //end else
} //end printGrade

int main(void){

	char ch;
        int marks;
	do{
		printf("Enter marks:" );
                scanf(" %d",&marks);
		printGrade(marks);
		printf("\nDo you want to continue? (Y/N)");
		scanf(" %c",&ch); //do not modify this.
	}while(ch == 'y'|| ch == 'Y');
	return 0;
}
