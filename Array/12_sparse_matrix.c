// sparse matrix find and display
#include <stdio.h>
int main()
{
    int i, j, k, n, m, c, a[10][10], b[10][10], r[10][10], count = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == b[i][j])
            {
                count++;
            }
        }
    }
    if (count == n * m)
    {
        printf("The two matrices are identical.\n");
    }
    else
    {
        printf("The two matrices are not identical.\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (a[i][j] != b[i][j])
                {
                    r[i][j] = a[i][j] - b[i][j];
                }
            }
        }
        printf("The difference matrix is:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", r[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}