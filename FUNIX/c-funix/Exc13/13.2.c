#include <stdio.h>
#include <ctype.h>

int main() {
    char file_name[100];
    printf("Nhập tên file: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r+");
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            c = toupper(c);
            fseek(file, -1, SEEK_CUR);
            fputc(c, file);
        }
    }

    fclose(file);

    printf("Chuyển đổi thành công.\n");

    return 0;
}
