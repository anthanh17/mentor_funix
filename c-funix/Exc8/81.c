#include <stdio.h>

double circumference(double r) { return 2 * r * 3.14; }

int main() {
  double r;
  scanf("%lf", &r);
  printf("%f", circumference(r));
  return 0;
}
