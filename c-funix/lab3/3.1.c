#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  int c = 2 * (a + b);
  int d = a * b;

  printf("Chu vi HCN co chieu dai %d va chieu rong %d la %d\n", a, b, c);
  printf("Dien tic HCN co chieu dai %d va chieu rong %d la %d\n", a, b, d);
  return 0;
}
