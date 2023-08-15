#include <stdio.h>

int maxOfArray(int arr[], int n) {
  int maxValue = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }
  return maxValue;
}

int main() {
  int n1, n2;
  int arr1[1000], arr2[1000];
  scanf("%d", &n1);
  for (int i = 0; i < n1; i++) {
    scanf("%d", &arr1[i]);
  }
  scanf("%d", &n2);
  for (int i = 0; i < n2; i++) {
    scanf("%d", &arr2[i]);
  }

  printf("%d %d", maxOfArray(arr1, n1), maxOfArray(arr2, n2));

  return 0;
}
