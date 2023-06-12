#include <stdio.h>

void calculateFactorial(int num, int* result) {
    *result = 1;

    for (int i = 1; i <= num; i++) {
        *result *= i;
    }
}

int main() {
    int number;
    int factorial;

    printf("Nhap so can tinh giai thua: ");
    scanf("%d", &number);

    calculateFactorial(number, &factorial);

    printf("Giai thua cua %d la: %d\n", number, factorial);

    return 0;
}
