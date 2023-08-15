#include <stdio.h>

void swapNumbers(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main() {
  int num1, num2;
  printf("Nhập số thứ nhất: ");
  scanf("%d", &num1);
  printf("Nhập số thứ hai: ");
  scanf("%d", &num2);

  printf("Trước khi hoán đổi: num1 = %d, num2 = %d\n", num1, num2);

  swapNumbers(&num1, &num2);

  printf("Sau khi hoán đổi: num1 = %d, num2 = %d\n", num1, num2);

  return 0;
}
