#include <stdio.h>
#include <stdlib.h>  // Needed for dynamic memory allocation

int main()
{
    int n, i, flag = 1, temp, gap_size;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[100];  // Avoids garbage values and buffer overflow

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    gap_size = n;

    while (gap_size > 1 || flag == 1)
    {
        gap_size = (int)(gap_size / 2);  // Reduce gap size
        if (gap_size < 1) gap_size = 1;    // Ensure minimum gap size is 1

        flag = 0; // Reset swap flag

        for (i = 0; i < (n - gap_size); i++)
        {
            if (arr[i] > arr[i + gap_size])
            {
                temp = arr[i + gap_size];
                arr[i + gap_size] = arr[i];
                arr[i] = temp;
                flag = 1; // Swap occurred, keep sorting
            }
        }
    }

    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
