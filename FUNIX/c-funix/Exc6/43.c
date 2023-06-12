#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        // If n is divisible by i, i is the divisor of n
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}
