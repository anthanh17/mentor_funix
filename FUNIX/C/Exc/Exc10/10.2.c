#include <stdio.h>

int main() {
  char *charPtr;
  int *intPtr;
  float *floatPtr;
  double *doublePtr;
  long int *longIntPtr;

  printf("Kich thuoc cua bien con tro kieu char: %lu byte\n", sizeof(charPtr));
  printf("Kich thuoc cua bien con tro kieu int: %lu byte\n", sizeof(intPtr));
  printf("Kich thuoc cua bien con tro kieu float: %lu byte\n",
         sizeof(floatPtr));
  printf("Kich thuoc cua bien con tro kieu double: %lu byte\n",
         sizeof(doublePtr));
  printf("Kich thuoc cua bien con tro kieu long int: %lu byte\n",
         sizeof(longIntPtr));

  return 0;
}
