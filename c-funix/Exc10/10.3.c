#include <stdio.h>

int main() {
  int num = 1;
  int *ptr1 = &num;
  int *ptr2;
  int *ptr3 = 0;

  printf("gia tri con tro ptr1: %p \n", ptr1);
  printf("gia tri con tro ptr2: %p \n", ptr2);
  printf("gia tri con tro ptr3: %p \n", ptr3);

  return 0;
}
