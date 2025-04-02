#include<stdio.h>
int main() {
    int i, n, arr[20], small, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the Elements : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    small = arr[0];
    pos = 0;
    for(i=0; i<n; i++) {
        if(arr[i]<small) {
            small = arr[i];
            pos = i;
        }
    }
    printf("The smallest element is %d at position %d", small, pos+1);
    return 0;
}