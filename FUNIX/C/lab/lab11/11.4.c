#include <stdio.h>

void calculateSum(int *num1, int *num2, int *sum) { *sum = *num1 + *num2; }

int main() {
  int num1, num2, sum;
  printf("Nhập số thứ nhất: ");
  scanf("%d", &num1);
  printf("Nhập số thứ hai: ");
  scanf("%d", &num2);

  calculateSum(&num1, &num2, &sum);
  printf("Tổng hai số là: %d\n", sum);

  return 0;
}
