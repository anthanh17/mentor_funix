#include <stdio.h>

void copyString(const char* source, char* destination) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
}

int main() {
    char sourceString[] = "Hello, world!";
    char destinationString[100];

    copyString(sourceString, destinationString);

    printf("Chuỗi nguồn: %s\n", sourceString);
    printf("Chuỗi đích: %s\n", destinationString);

    return 0;
}
