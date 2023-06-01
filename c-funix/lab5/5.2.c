#include <stdio.h>

int main() {
  int number;
  scanf("%d", &number);
  if (number % 2 == 0)
    printf("n is an even number");
  else
    printf("n is an odd number");
  return 0;
}
