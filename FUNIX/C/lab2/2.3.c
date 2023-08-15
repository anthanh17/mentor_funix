#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char name[32];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello %s. How old are you?", name);
    return 0;
}
