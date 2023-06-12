#include <stdio.h>
#include <ctype.h>

void loaiBoKyTuKhongChuCai(char *chuoi) {
    int i, j = 0;

    for (i = 0; chuoi[i] != '\0'; i++) {
        if (isalpha(chuoi[i])) {
            chuoi[j] = chuoi[i];
            j++;
        }
    }

    chuoi[j] = '\0';
}

int main() {
    char chuoi[100];

    printf("Nhập chuỗi: ");
    gets(chuoi);

    loaiBoKyTuKhongChuCai(chuoi);

    printf("Chuỗi sau khi loại bỏ ký tự ngoại trừ chữ cái: %s\n", chuoi);

    return 0;
}
