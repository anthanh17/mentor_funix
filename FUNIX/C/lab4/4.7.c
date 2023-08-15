#include <stdio.h>

int main() {
    float a;
    printf("Nhap a: ");
    scanf("%f", &a);

    float b;
    printf("Nhap b: ");
    scanf("%f", &b);

    float c;
    printf("Nhap c: ");
    scanf("%f", &c);

    float d;
    printf("Nhap d: ");
    scanf("%f", &d);

    printf("\nBinh phuong cua 4 so la: %f", (a+b+c+d) / 4);

    return 0;
}
