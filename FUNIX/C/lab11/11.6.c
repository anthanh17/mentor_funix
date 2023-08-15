#include <stdio.h>

void addNumbers(int* a, int* b, int* sum) {
    *sum = *a + *b;
}

int main() {
    int num1, num2, sum;

    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf("%d", &num2);

    addNumbers(&num1, &num2, &sum);

    printf("Tong: %d\n", sum);

    return 0;
}
