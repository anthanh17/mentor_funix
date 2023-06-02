#include <stdio.h>

int main() {
    int numberToGuess;
    int guess;

    printf("Nhập số cần đoán: ");
    scanf("%d", &numberToGuess);

    printf("Hãy đoán số: ");

    do {
        scanf("%d", &guess);

        if (guess != numberToGuess) {
            printf("Sai rồi. Hãy đoán lại: ");
        }
    } while (guess != numberToGuess);

    printf("Bạn đã đoán đúng!\n");

    return 0;
}
