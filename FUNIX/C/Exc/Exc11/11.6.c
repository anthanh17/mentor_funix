#include <stdio.h>

void concatStrings(const char* str1, const char* str2, char* result) {
    while (*str1 != '\0') {
        *result = *str1;
        str1++;
        result++;
    }

    while (*str2 != '\0') {
        *result = *str2;
        str2++;
        result++;
    }

    *result = '\0';
}

int main() {
    char string1[100] = "Hello";
    char string2[] = ", world!";
    char resultString[200];

    concatStrings(string1, string2, resultString);

    printf("Chuỗi 1: %s\n", string1);
    printf("Chuỗi 2: %s\n", string2);
    printf("Kết quả ghép chuỗi: %s\n", resultString);

    return 0;
}
