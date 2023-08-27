#include <stdio.h>
#include <ctype.h>

int main() {
    char input;

    printf("Nhập một ký tự: ");
    scanf("%c", &input);

    if (islower(input)) {
        printf("Ký tự sau khi chuyển đổi: %c\n", toupper(input));
    } else if (isupper(input)) {
        printf("Ký tự sau khi chuyển đổi: %c\n", tolower(input));
    } else {
        printf("Không phải ký tự chữ cái.\n");
    }

    return 0;
}
