#include <stdio.h>

int main() {
    int a;
    printf("Nhap a: ");
    scanf("%d", &a);

    int b;
    printf("Nhap b: ");
    scanf("%d", &b);

    int c;
    printf("Nhap c: ");
    scanf("%d", &c);

    int d;
    printf("Nhap d: ");
    scanf("%d", &d);

    printf("\nBinh phuong cua %d la: %d", a, a * a);
    printf("\nBinh phuong cua %d la: %d", b, b * b);
    printf("\nBinh phuong cua %d la: %d", c, c * c);
    printf("\nBinh phuong cua %d la: %d", d, d * d);

    return 0;
}
