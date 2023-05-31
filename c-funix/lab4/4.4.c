#include <stdio.h>

int main() {
    int phut;
    scanf("%d", &phut);

    float ngay = (float)phut / 60 / 24;
    float nam = ngay / 365;

    printf("so ngay: %f va so nam: %f", ngay, nam);
    return 0;
}
