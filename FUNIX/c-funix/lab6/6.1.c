#include <stdio.h>

int main() {
    int number;

    printf("Nhập một số tự nhiên: ");
    scanf("%d", &number);

    printf("Các số chẵn từ 1 đến %d là: ", number);

    for (int i = 1; i <= number; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
