#include <stdio.h>
int smallest(int arr[], int k, int n);
void selecton_sort(int arr[], int n);
void main(int argc, char *argv[])
{
    int arr[10], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i + 1);
        scanf("%d", &arr[i]);
    }
    selecton_sort(arr, n);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int smallest(int arr[], int k, int n)
{
    int pos = k, small = arr[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}
void selecton_sort(int arr[], int n)
{
    int pos, temp, i;
    for (i = 0; i < n - 1; i++)
    {
        pos = smallest(arr, i, n);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}