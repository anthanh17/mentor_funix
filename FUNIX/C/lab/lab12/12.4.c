#include <stdio.h>

int searchElement(int* arr, int size, int target) {
    // Duyệt qua từng phần tử của mảng
    for (int i = 0; i < size; i++) {
        // Nếu phần tử hiện tại trùng khớp với phần tử cần tìm kiếm
        if (*(arr + i) == target) {
            return i;  // Trả về vị trí của phần tử
        }
    }

    return -1;  // Không tìm thấy phần tử trong mảng
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

    int target;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &target);

    int index = searchElement(arr, size, target);

    if (index != -1) {
        printf("Tim thay phan tu %d tai vi tri %d trong mang.\n", target, index);
    } else {
        printf("Khong tim thay phan tu %d trong mang.\n", target);
    }

    return 0;
}
