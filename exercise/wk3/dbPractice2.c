
#include<stdio.h>

void display(int Matrix1[3][3])
{
    int size = 3, i, j;
    for (i=0; i<size; i++) 
    {
      for (j=0; j<size; j++) 
      {
        printf("%d ,", Matrix1[i][j]);
      }
        printf("\n");
    }
}

int main(void)
{
    int size=3, i, j;
    int Matrix[size][size];

    printf("Enter 9 elements of the matrix");

    for (i=0; i<size; i++)
    {
      for (j=0; j<size; j++)
      {
          scanf(" %d", &Matrix[i][j]);
      }
    }
    display(Matrix);
    return 0;
}
