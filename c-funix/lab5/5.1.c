#include <stdio.h>

int main() {
  float a, b;
  scanf("%f%f", &a, &b);

  if ((a != (int)a) || (b != (int)b)) {
    printf("so vua nhap khong phai so nguyen");
  } else {
    if (a > b)
      printf("so thu nhat lon hon so thu hai");
    else if (a < b)
      printf("so thu nhat be hon so thu hai");
    else
      printf("so thu nhat bang so thu hai");
  }
  return 0;
}
