#include<stdio.h>
int main() {
    int i, n, arr[20];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("arr[%d] : ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("The array elements are : ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);

    }
    return 0;
}