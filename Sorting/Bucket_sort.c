#include <stdio.h>

#define MAX 100  // Max elements
#define BUCKETS 10  // Number of buckets

int main() {
    int arr[MAX], n, i, j, k;
    int bucket[BUCKETS][MAX], count[BUCKETS] = {0};

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int index = arr[i] / BUCKETS;  // Find bucket index
        bucket[index][count[index]++] = arr[i];
    }

    // Sort each bucket using simple sorting (Insertion Sort)
    for (i = 0; i < BUCKETS; i++) {
        for (j = 1; j < count[i]; j++) {
            int temp = bucket[i][j];
            k = j - 1;
            while (k >= 0 && bucket[i][k] > temp) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = temp;
        }
    }

    // Merge buckets back into the array
    k = 0;
    for (i = 0; i < BUCKETS; i++)
        for (j = 0; j < count[i]; j++)
            arr[k++] = bucket[i][j];

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
