#include <stdio.h>

void swapArrays(int* arr1, int* arr2, int size) {
    // Duyệt qua từng phần tử của mảng và hoán đổi giá trị
    for (int i = 0; i < size; i++) {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int size;
    printf("Nhap so luong phan tu trong cac mang: ");
    scanf("%d", &size);

    int arr1[size];
    int arr2[size];

    printf("Nhap cac phan tu cua mang 1:\n");
    for (int i = 0; i < size; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Nhap cac phan tu cua mang 2:\n");
    for (int i = 0; i < size; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    printf("Mang 1 truoc khi hoan doi: ");
    printArray(arr1, size);
    printf("Mang 2 truoc khi hoan doi: ");
    printArray(arr2, size);

    swapArrays(arr1, arr2, size);

    printf("Mang 1 sau khi hoan doi: ");
    printArray(arr1, size);
    printf("Mang 2 sau khi hoan doi: ");
    printArray(arr2, size);

    return 0;
}
