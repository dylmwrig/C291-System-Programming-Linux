//factorial of a number is the product of the number with all
// the numbers below it.
//eg: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

int values[1];
int factorial(int);

int main(void)
{
        using namespace std;
    printf( "Debugging Practice 1 - Quiz 3, Q3\n\n");
        printf( "Please enter the number whose factorial you wish to find: ");
        scanf("%d", &n);

        int fact = factorial(n);
        printf("The factorial of %f is %d", &n,factorial)

    return 0;
}
}

int factorial(int number)
{
    int factorial = 1;
    for (int i =1; i<=num; i--)
            factorial =* i;

    return fact;
}
