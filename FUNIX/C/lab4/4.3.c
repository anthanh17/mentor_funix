#include <stdio.h>

int main() {
    int ngay;
    printf("Nhap ngay: ");
    scanf("%d", &ngay);

    float so_nam = (float)ngay / 365;
    float tuan = ((float)ngay - so_nam * 365) / 7;
    float so_ngay = ngay - so_nam * 365 - tuan * 7;

    // printf("so ngay: %f va so nam: %f", ngay, nam);
    return 0;
}
