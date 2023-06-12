#include <stdio.h>

int findMax(int *num1, int *num2) {
  if (*num1 > *num2) {
    return *num1;
  } else {
    return *num2;
  }
}

int main() {
  int num1, num2;
  printf("Nhập số thứ nhất: ");
  scanf("%d", &num1);
  printf("Nhập số thứ hai: ");
  scanf("%d", &num2);

  int max = findMax(&num1, &num2);
  printf("Số lớn nhất là: %d\n", max);

  return 0;
}
