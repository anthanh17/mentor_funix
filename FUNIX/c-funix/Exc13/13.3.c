#include <stdio.h>
#include <stdlib.h>

void printFileReverse(FILE *file) {
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long pos = ftell(file);

    while (pos > 0) {
        pos--;
        fseek(file, pos, SEEK_SET);
        char c = fgetc(file);

        // Để tránh hiển thị ký tự null (EOF) cuối cùng của file
        if (pos == 0 && c == '\0') {
            break;
        }

        printf("%c", c);
    }

    fclose(file);
}

int main() {
    char file_name[100];
    printf("Nhập tên file: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");
    printFileReverse(file);

    return 0;
}
