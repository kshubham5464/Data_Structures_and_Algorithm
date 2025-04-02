#include <stdio.h>
int main()
{
    int i, n, num, pos, arr[10];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the elements to be inserted : ");          // which elements to be inserted
    scanf("%d", &num);
    printf("Enter the position to be inserted : ");
    scanf("%d", &pos);
    for (i = n - 1; i >= pos - 1; i--)
    {                                                    // shift elements to the right and make space for the new element
        arr[i + 1] = arr[i];                            // increse the index of each element by 1
    }
    arr[pos] = num;                                   // insert the new element at the specified position
    n++;
    printf(" After inserting %d at position %d, the array is: ", num, pos);
    for (i = 0; i < n; i++)
    {
        printf("\narr[%d] = %d", i, arr[i]);
    }
    return 0;
}
