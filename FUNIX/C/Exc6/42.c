#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    // Variable that stores the value of n!
    // Note: You need to initialize it to value of 1
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    printf("%d", factorial);
    return 0;
}
