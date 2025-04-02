#include <stdio.h>

int main()
{
    int arr[100], temp[100], n, mid, i, j, k, size, left, right;

    // Taking input for the array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Taking input for the array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Merge Sort without using functions
    for (size = 1; size < n; size *= 2)
    {
        for (left = 0; left < n - 1; left += 2 * size)
        {
            mid = left + size - 1;
            right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            i = left, j = mid + 1, k = left;

            // Merging two sorted parts
            while (i <= mid && j <= right)
            {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }
            // Copying remaining elements of left subarray
            while (i <= mid) 
                temp[k++] = arr[i++];

            // Copying remaining elements of right subarray
            while (j <= right)
                temp[k++] = arr[j++];

            // Copying sorted subarray back to original array
            for (i = left; i <= right; i++)
                arr[i] = temp[i];
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
