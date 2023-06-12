#include <stdio.h>

void inputArray(int* arr, int size) {
    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < size; i++) {
        printf("Phần tử thứ %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

void displayArray(const int* arr, int size) {
    printf("Các phần tử của mảng là:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int size;

    printf("Nhập kích thước của mảng: ");
    scanf("%d", &size);

    int array[size];

    inputArray(array, size);
    displayArray(array, size);

    return 0;
}
