#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Nhập chuỗi thứ nhất: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Xóa ký tự '\n' cuối cùng

    printf("Nhập chuỗi thứ hai: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Xóa ký tự '\n' cuối cùng

    printf("Chuỗi thứ nhất: %s\n", str1);
    printf("Chuỗi thứ hai: %s\n", str2);

    // Kiểm tra chuỗi
    if (strcmp(str1, str2) == 0) {
        printf("Hai chuỗi giống nhau.\n");
    } else {
        printf("Hai chuỗi khác nhau.\n");
    }

    // Nối chuỗi
    strcat(str1, str2);
    printf("Chuỗi sau khi nối: %s\n", str1);

    // Đọc độ dài chuỗi
    int length = strlen(str1);
    printf("Độ dài của chuỗi: %d\n", length);

    return 0;
}
