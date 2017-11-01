//factorial of a number is the product of the number with all
// the numbers below it.
//eg: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

int values[1];
int fact;

#include <stdio.h>

int main(void)
{
    int n;
    printf( "Debugging Practice 1 - Quiz 3, Q3\n\n");
    printf( "Please enter the number whose factorial you wish to find: ");
    scanf(" %d", &n);

    int factVal = factorial(n);
    printf("The factorial of %d is %d", n, factVal);

    return 0;
}


int factorial(int num)
{
    int i;
    fact = 1;
    for (i = 1; i<=num; i++)
    {
      fact *= i;
    } //end for

    return fact;
}
