#include <stdio.h>

int main() {
  int num = 1;

  printf("gia tri bien num truoc khi thay doi: %d \n", num);
  int *ptr1 = &num;
  *ptr1 = 9;
  printf("gia tri bien num sau khi thay doi: %d \n", num);

  return 0;
}
