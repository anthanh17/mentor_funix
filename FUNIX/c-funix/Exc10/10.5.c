#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr;

  // Cấp phát động mảng gồm 100 phần tử kiểu int
  arr = (int *)malloc(100 * sizeof(int));

  if (arr == NULL) {
    printf("Khong the cap phat bo nho.\n");
    return 1;
  }

  // Giải phóng vùng bộ nhớ đã cấp phát
  free(arr);

  return 0;
}
