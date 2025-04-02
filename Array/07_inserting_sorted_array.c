#include <stdio.h>
int main()
{
    int i, n, num, j, arr[10];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the elements to be inserted : "); // which elements to be inserted
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (arr[i] > num)
        {
            for (j = n - 1; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = num;
            break;
        }
    }
    n++;
    printf("After inserting %d, the array is: ", num);
    for (i = 0; i < n; i++)
    {
        printf("\n arr[%d] = %d", i, arr[i]);
    }
    return 0;
}