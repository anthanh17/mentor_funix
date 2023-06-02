#include <stdio.h>

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Cac so nguyen to trong khoang tu 0 den 100 la:\n");
    for (int i = 0; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
