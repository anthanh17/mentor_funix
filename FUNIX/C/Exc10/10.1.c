#include <stdio.h>

int main() {
  int a = 5;
  int *p = &a;
  printf("dia chi con tro   : %p \n", &p);
  printf("dia chi cua bien a: %p \n", &a);
  printf("gia tri con tro p : %p \n", p);
  printf("gia tri con tro p tro toi: %d \n", *p);
  return 0;
}
