#include <stdio.h>

int main() {
  int number;
  scanf("%d", &number);
  if (number < 0)
    printf("thoi tiet cong");
  else if (0 <= number < 10)
    printf("thoi tiet rat lanh");
  else if (10 <= number < 20)
    printf("thoi tiet lanh");
  else if (20 <= number < 30)
    printf("thoi tiet tuyet voi");
  else if (30 <= number < 40)
    printf("thoi tiet nong");
  else if (40 <= number)
    printf("thoi tiet rat nong");

  return 0;
}
