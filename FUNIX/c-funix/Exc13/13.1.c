#include <stdio.h>

int main() {
    char file_name[100];
    printf("Nhập tên file: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return 1;
    }

    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    fclose(file);

    printf("Số dòng trong file: %d\n", count);

    return 0;
}
