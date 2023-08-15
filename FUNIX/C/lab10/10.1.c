#include <stdio.h>

int main() {
  int intValue = 10;
  float floatValue = 3.14;
  char charValue = 'A';

  int *intPtr = &intValue;
  float *floatPtr = &floatValue;
  char *charPtr = &charValue;

  printf("Địa chỉ và giá trị của biến con trỏ int:\n");
  printf("Địa chỉ: %p\n", (void *)&intPtr);
  printf("Giá trị: %p -> %d\n\n", (void *)intPtr, *intPtr);

  printf("Địa chỉ và giá trị của biến con trỏ float:\n");
  printf("Địa chỉ: %p\n", (void *)&floatPtr);
  printf("Giá trị: %p -> %.2f\n\n", (void *)floatPtr, *floatPtr);

  printf("Địa chỉ và giá trị của biến con trỏ char:\n");
  printf("Địa chỉ: %p\n", (void *)&charPtr);
  printf("Giá trị: %p -> %c\n", (void *)charPtr, *charPtr);

  return 0;
}
