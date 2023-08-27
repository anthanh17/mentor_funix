#include <stdio.h>

int main() {
    double length, width;
    printf("Nhập chiều dài của hình chữ nhật: ");
    scanf("%lf", &length);

    printf("Nhập chiều rộng của hình chữ nhật: ");
    scanf("%lf", &width);

    double perimeter = 2 * (length + width);
    double area = length * width;

    printf("Chu vi của hình chữ nhật có chiều dài %.2lf và chiều rộng %.2lf là %.2lf\n", length, width, perimeter);
    printf("Diện tích của hình chữ nhật có chiều dài %.2lf và chiều rộng %.2lf là %.2lf\n", length, width, area);

    return 0;
}
