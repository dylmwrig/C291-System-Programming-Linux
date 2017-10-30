/*Debugging quiz - File No: 4 */
/* This program should perform the duties of a basic calculator */
// Check for possible logical errors and rectify them 

#include<stdio.h>

int main(void){
	char input;
	float num1, num2, result;
	printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");
	scanf(" %c",&input);
	if(input == 'A' || input == 'S' || input == 'M' || input == 'D'){
                printf("The following numbers should be floats.");
		printf("Enter both numbers in required sequence: ");
		scanf(" %f %f",&num1,&num2);
		switch(input)
                {
			case 'A': result = num1 + num2;
                                printf("Here are num1 and num2: %f %f", num1, num2);
          			break;
			case 'S': result = num1 - num2;
          			break;
			case 'M': result = num1 * num2;
          			break;
			case 'D': if (num2 == 0)
                                {
                                  printf("Do not divide by zero.");
 				  break;
                                }
                              
                                else
                                {
                                  result = num1 / num2;		//Are there any logical errors possible? If so, how will you solve it? 
	 			  break;
                                }                			  
			default: break;
                }
          printf("The final result = %f\n", result);
	}
	else{
		printf("Please choose a valid operation\n");
	}
	return(0);
}
