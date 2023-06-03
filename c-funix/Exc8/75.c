#include <stdio.h>

void show(char name[100]) { printf("Hello %s", name); }

int main() {
  char name[100];
  scanf("%s", name);
  show(name);
  return 0;
}
