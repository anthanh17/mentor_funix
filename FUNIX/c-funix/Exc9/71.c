#include<stdio.h>
#include<string.h>

int main() {
    char a[100], b[100];
    scanf("%s%s", a, b);
    if (strcmp(a, b) == 0) {
        printf("two people having the same name");
    } else {
        printf("two people don't have the same name");
    }
    return 0;
}
