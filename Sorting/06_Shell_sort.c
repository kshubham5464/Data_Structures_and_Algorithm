#include <stdio.h>
int main()
{
    int arr[10] = {-1};
    int i, j, n, flag = 1, temp, gap_size;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    gap_size = n;
    while (flag == 1 || gap_size > 1)
    {
        flag = 0;
        gap_size = (gap_size + 1) / 2;
        for (i = 0; i < (n - gap_size); i++)
        {
            if (arr[i] > arr[i + gap_size])
            {
                temp = arr[i + gap_size];
                arr[i + gap_size] = arr[i];
                arr[i] = temp;
                flag = 0;
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
