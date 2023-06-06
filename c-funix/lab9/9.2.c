#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void bubbleSortStrings(char arr[][MAX_SIZE], int n) {
    int i, j;
    char temp[MAX_SIZE];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    int n, i;
    char strings[MAX_SIZE][MAX_SIZE];

    printf("Nhập số lượng chuỗi: ");
    scanf("%d", &n);

    printf("Nhập các chuỗi:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    bubbleSortStrings(strings, n);

    printf("\nChuỗi sau khi sắp xếp:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
