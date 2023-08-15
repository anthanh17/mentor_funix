#include <stdio.h>

int lenString(const char *s) {
  int len = 0;
  while (*s != '\0')
  {
    len ++;
    s++;
  }
  return len;
}


int main() {
  char text[] = "xin chao cac ban"; // 16
  printf("Length text: %d", lenString(text));

  return 0;
}
