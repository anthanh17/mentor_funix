#include <stdio.h>

int main() {
    int number;
    printf("Nhap so can kiem tra: ");
    scanf("%d", &number);

    int kq = (1 << 4) | number;
    printf("KQ la: %d", kq);
    return 0;
}
