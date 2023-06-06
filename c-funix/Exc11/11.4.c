#include <stdio.h>

void copyArray(const int* source, int* destination, int size) {
    for (int i = 0; i < size; i++) {
        *(destination + i) = *(source + i);
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
    int sourceArray[] = {1, 2, 3, 4, 5};
    int destinationArray[5];
    int size = sizeof(sourceArray) / sizeof(sourceArray[0]);

    copyArray(sourceArray, destinationArray, size);
    displayArray(destinationArray, size);

    return 0;
}
