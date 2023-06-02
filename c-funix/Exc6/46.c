#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int answer = 1;
    for (; b > 0; answer *= a, b--);
    printf("%d", answer);
    return 0;
}
