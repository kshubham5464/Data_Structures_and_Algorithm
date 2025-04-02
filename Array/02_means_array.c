#include <stdio.h>
int main()
{
    int n, i, arr[20], sum = 0;
    float mean = 0.0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    mean = (float)sum / n;
    printf("Mean = %.2f", mean);
    return 0;
}