#include <stdio.h>
#include <string.h>

int tinhDoDaiChuoi(const char *chuoi) {
    int doDai = 0;
    while (*chuoi != '\0') {
        doDai++;
        chuoi++;
    }
    return doDai;
}

void noiChuoi(char *chuoi1, const char *chuoi2) {
    while (*chuoi1 != '\0') {
        chuoi1++;
    }
    while (*chuoi2 != '\0') {
        *chuoi1 = *chuoi2;
        chuoi1++;
        chuoi2++;
    }
    *chuoi1 = '\0';
}

int kiemTraChuoi(const char *chuoi1, const char *chuoi2) {
    while (*chuoi1 != '\0' && *chuoi2 != '\0') {
        if (*chuoi1 != *chuoi2) {
            return 0; // hai chuỗi khác nhau
        }
        chuoi1++;
        chuoi2++;
    }
    if (*chuoi1 == '\0' && *chuoi2 == '\0') {
        return 1; // hai chuỗi giống nhau
    } else {
        return 0; // hai chuỗi khác nhau
    }
}

int main() {
    char chuoi1[100], chuoi2[100];

    printf("Nhập chuỗi 1: ");
    gets(chuoi1);

    printf("Nhập chuỗi 2: ");
    gets(chuoi2);

    printf("Độ dài chuỗi 1: %d\n", tinhDoDaiChuoi(chuoi1));
    printf("Độ dài chuỗi 2: %d\n", tinhDoDaiChuoi(chuoi2));

    noiChuoi(chuoi1, chuoi2);
    printf("Chuỗi sau khi nối: %s\n", chuoi1);

    if (kiemTraChuoi(chuoi1, chuoi2)) {
        printf("Hai chuỗi giống nhau.\n");
    } else {
        printf("Hai chuỗi khác nhau.\n");
    }

    return 0;
}
