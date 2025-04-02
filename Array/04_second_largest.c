#include<stdio.h>
int main() {
    int i, n, arr[30], large, second_large;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in the array :\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);         //to store the elements in the array
    }
// yaha pe phle large nikale hai
    large = arr[0];
    for(i=0; i<n; i++) {
        if(arr[i] > large) {
            large = arr[i];
        }
    }
//yaha pe second large nikale hai........jo element large ke equal hai usko eliminate bhi kiye
    second_large = arr[1];
    for(i=1; i<n; i++) {
        if(arr[i] != large) {
            if(arr[i] > second_large) {
                second_large = arr[i];
            }
        }
    }
    printf(" The second largest element is: %d\n", second_large);
    return 0;
}