// product of two given matrix
#include <stdio.h>
int main()
{
    int i, j, k, mat1[3][3], mat2[3][3], product[3][3];
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Product of the two matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n"); 
    }
    return 0;
}