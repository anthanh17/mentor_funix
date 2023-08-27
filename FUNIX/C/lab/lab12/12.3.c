#include <stdio.h>

int findMaxNumber(int* arr, int size) {
    // Kiểm tra điều kiện đặc biệt khi mảng rỗng
    if (size == 0) {
        return 0;
    }

    // Con trỏ max trỏ đến phần tử đầu tiên của mảng
    int* max = arr;

    // Duyệt qua từng phần tử của mảng
    for (int i = 1; i < size; i++) {
        // Nếu phần tử hiện tại lớn hơn phần tử lớn nhất đã tìm thấy trước đó
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }

    return *max;
}

int main() {
    int size;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &size);

    int arr[size];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int max = findMaxNumber(arr, size);
    printf("So lon nhat trong mang la: %d\n", max);

    return 0;
}
