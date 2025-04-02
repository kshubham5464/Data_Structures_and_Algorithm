#include <stdio.h>

// Function to display the array elements
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific index in the array
int indInsertion(int arr[], int size, int element, int capacity, int index) {
    // Check if the array is full
    if (size >= capacity) {
        printf("Array is full. Cannot insert element.\n");
        return -1;
    }

    // Check if the index is within the array bounds
    if (index < 0 || index > size) {
        printf("Invalid index. Please enter a valid index.\n");
        return -1;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified index
    arr[index] = element;

    return 1;
}

int main() {
    int arr[100] = {4, 65, 24, 65, 1};
    int size = 5, element = 45, index = 3;

    printf("Original array: ");
    display(arr, size);

    if (indInsertion(arr, size, element, 100, index) == 1) {
        size++;
        printf("Array after insertion: ");
        display(arr, size);
    }

    return 0;
}