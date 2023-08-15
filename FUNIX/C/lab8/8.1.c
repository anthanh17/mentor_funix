#include <math.h>
#include <stdio.h>

// Hàm tìm ước chung lớn nhất của hai số nguyên không âm
int findGCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Hàm tính giá trị tuyệt đối của một số (float)
float absoluteValue(float num) {
  if (num < 0) {
    return -num;
  } else {
    return num;
  }
}

// Hàm tính giai thừa của một số nguyên dương
int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Hàm tính khoảng cách giữa hai điểm A(Ax, Ay) và B(Bx, By) trong không gian
// Oxy
float distance(float Ax, float Ay, float Bx, float By) {
  float dx = Bx - Ax;
  float dy = By - Ay;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  // Test các hàm
  int gcd = findGCD(24, 36);
  printf("Ước chung lớn nhất của 24 và 36: %d\n", gcd);

  float absValue = absoluteValue(-3.14);
  printf("Giá trị tuyệt đối của -3.14: %f\n", absValue);

  int fact = factorial(5);
  printf("5! = %d\n", fact);

  float dist = distance(1.0, 2.0, 4.0, 6.0);
  printf("Khoảng cách giữa hai điểm A(1, 2) và B(4, 6): %f\n", dist);

  return 0;
}
