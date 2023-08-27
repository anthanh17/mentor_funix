#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    // Variable that stores the sum of all numbers from a to b
    // Note: you need to initialize variable sum to zero
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 1) {
            // sum += i means sum = sum + i
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}
