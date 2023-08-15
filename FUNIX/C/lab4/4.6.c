#include <stdio.h>

int main() {
    int a;
    printf("Nhap a: ");
    scanf("%d", &a);

    int b;
    printf("Nhap b: ");
    scanf("%d", &b);

    printf("\nChia 2 so la: %f", (float)a / (float)b);

    return 0;
}
