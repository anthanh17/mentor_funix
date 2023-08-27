#include <stdio.h>

int compareStrings(const char* str1, const char* str2) {
    // Kiểm tra từng ký tự của hai chuỗi cho đến khi gặp ký tự null
    while (*str1 != '\0' || *str2 != '\0') {
        // Nếu ký tự của chuỗi thứ nhất nhỏ hơn ký tự của chuỗi thứ hai
        if (*str1 < *str2) {
            return -1;
        }
        // Nếu ký tự của chuỗi thứ nhất lớn hơn ký tự của chuỗi thứ hai
        else if (*str1 > *str2) {
            return 1;
        }

        // Di chuyển con trỏ đến ký tự tiếp theo trong hai chuỗi
        str1++;
        str2++;
    }

    // Hai chuỗi bằng nhau
    return 0;
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";

    int result = compareStrings(str1, str2);

    if (result == 0) {
        printf("Hai chuoi bang nhau\n");
    } else if (result < 0) {
        printf("Chuoi 1 nho hon chuoi 2\n");
    } else {
        printf("Chuoi 1 lon hon chuoi 2\n");
    }

    return 0;
}
