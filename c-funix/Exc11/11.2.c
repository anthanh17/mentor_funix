#include <stdio.h>

void square(int* num) {
    *num = (*num) * (*num);
}

int main() {
    int number;

    printf("Nhập một số nguyên: ");
    scanf("%d", &number);

    square(&number);

    printf("Bình phương của số là: %d\n", number);

    return 0;
}
