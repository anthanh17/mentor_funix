#include <stdio.h>

int main() {
    char name[100];

    printf("Nhập tên của bạn: ");
    scanf("%[^\n]", name);

    printf("Hello %s. How are you?\n", name);

    return 0;
}
