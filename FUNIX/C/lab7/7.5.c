#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        // Hoán đổi hai phần tử
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int a[101];
  int n, i;

  do {
    printf("Nhap n: \n");
    scanf("%d", &n);
  } while (n <= 0);

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("ban dau\n");
  for (i = 0; i < n; i++) {
    printf("%d", a[i]);
  }

  bubbleSort(a, n);

  printf("\nDãy số sau khi sắp xếp theo chiều giảm dần: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}
