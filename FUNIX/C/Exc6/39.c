#include<stdio.h>

int main() {
    int a, b;
    // sum is the variable that stores the sum of all numbers from a to b
    // Note: you need to initialize variable sum to zero
    int sum = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        sum = sum + i;
    }
    printf("%d", sum);
    return 0;
}
