#include <stdio.h>

void reverseString(char* str) {
    // Nếu con trỏ trỏ đến NULL, thoát khỏi hàm
    if (str == NULL) {
        return;
    }

    // Con trỏ p trỏ đến đầu chuỗi
    char* p = str;

    // Tìm vị trí kết thúc chuỗi
    while (*p != '\0') {
        p++;
    }

    // Đưa con trỏ về lại cuối chuỗi
    p--;

    // In từng ký tự của chuỗi từ cuối lên đầu
    while (p >= str) {
        printf("%c", *p);
        p--;
    }
}

int main() {
    char str[] = "Hello, World!";

    printf("Chuoi goc: %s\n", str);
    printf("Chuoi dao nguoc: ");
    reverseString(str);

    return 0;
}
