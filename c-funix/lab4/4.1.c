#include <stdio.h>

int main() {
    int number;
    printf("Nhap so can kiem tra: ");
    scanf("%d", &number);

    int kq = number >> 2 & 1;
    printf("Bit thu 3 la: %d", kq);
    return 0;
}
