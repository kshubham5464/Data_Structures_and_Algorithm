#include<stdio.h>
int fact(int);
int main() {
    int num, val;
    printf("Enter the number: ");
    scanf("%d", &num);
    val = fact(num);
    printf("Factorial of %d = %d", num, val);
    return 0;
}
int fact(int n) {
    if (n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}
