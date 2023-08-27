#include <stdio.h>
#include <string.h>

int kiemTraChuoiCon(const char *chuoi, const char *chuoiCon) {
    int i, j;
    int doDaiChuoi = strlen(chuoi);
    int doDaiChuoiCon = strlen(chuoiCon);

    for (i = 0; i <= doDaiChuoi - doDaiChuoiCon; i++) {
        for (j = 0; j < doDaiChuoiCon; j++) {
            if (chuoi[i + j] != chuoiCon[j]) {
                break;
            }
        }
        if (j == doDaiChuoiCon) {
            return 1; // chuỗi con được tìm thấy trong chuỗi gốc
        }
    }

    return 0; // chuỗi con không xuất hiện trong chuỗi gốc
}

int main() {
    char chuoi[100];
    char chuoiCon[100];

    printf("Nhập chuỗi: ");
    gets(chuoi);

    printf("Nhập chuỗi con: ");
    gets(chuoiCon);

    if (kiemTraChuoiCon(chuoi, chuoiCon)) {
        printf("Chuỗi con \"%s\" xuất hiện trong chuỗi \"%s\".\n", chuoiCon, chuoi);
    } else {
        printf("Chuỗi con \"%s\" không xuất hiện trong chuỗi \"%s\".\n", chuoiCon, chuoi);
    }

    return 0;
}
