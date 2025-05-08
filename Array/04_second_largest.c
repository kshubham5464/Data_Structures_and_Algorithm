#include <stdio.h>

int main()
{
    int i, n, arr[30], large, second_large;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2)
    {
        printf("Need at least two elements.\n");
        return 0;
    }

    printf("Enter elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize large and second_large
    if (arr[0] > arr[1])
    {
        large = arr[0];
        second_large = arr[1];
    }
    else if (arr[0] < arr[1])
    {
        large = arr[1];
        second_large = arr[0];
    }
    else
    {
        large = second_large = arr[0]; // Both same initially
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > large)
        {
            second_large = large;
            large = arr[i];
        }
        else if (arr[i] < large && arr[i] > second_large)
        {
            second_large = arr[i];
        }
    }

    if (large == second_large)
    {
        printf("There is no second largest element (all are equal).\n");
    }
    else
    {
        printf("The second largest element is: %d\n", second_large);
    }

    return 0;
}

