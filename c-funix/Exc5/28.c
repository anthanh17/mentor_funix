#include <stdio.h>

int main() {
  int number;
  scanf("%d", &number);
  if (number > 0)
    printf("n is a positive number");
  else if (number < 0)
    printf("n is a negative number");
  else
    printf("n is equal to 0");

  return 0;
}
