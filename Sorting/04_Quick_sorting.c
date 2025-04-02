#include<stdio.h>
#define size 100
int partition(int arr[], int beg, int end);
void quicksort(int arr[], int beg, int end);
void main() {
    int arr[size], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int partition(int arr[], int beg, int end) {
    int left, right, loc, flag, temp;
    loc = left = beg;
    right = end;
    flag = 0;
    while (flag != 1) {
        while (arr[loc] <= arr[right] && loc != right) {
            right--;
        }
        if (loc == right) {
            flag = 1;
        }
        else if (arr[loc] > arr[right]) {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        if (flag != 1) {
            while (arr[loc] >= arr[left] && loc != left) {
                left++;
            }
            if (loc == left) {
                flag = 1;
            }
            else if (arr[loc] < arr[left]) {
                temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}
void quicksort(int arr[], int beg, int end) {
    int loc, temp;
    if (beg < end) {
        loc = partition(arr, beg, end);
        quicksort(arr, beg, loc - 1);
        quicksort(arr, loc + 1, end);
    }
}