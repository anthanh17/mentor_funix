#include <stdio.h>

void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf("%d", &num2);

    printf("Truoc khi hoan doi: num1 = %d, num2 = %d\n", num1, num2);

    swapNumbers(&num1, &num2);

    printf("Sau khi hoan doi: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
