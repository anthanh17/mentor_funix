#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define PI 3.14159265

double distance_angle[6] = {0};
double median[3] = {0};
double centroid[2] = {0};

double calculate_distance(double xA, double yA, double xB, double yB) {
  return sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
}

double calculate_angle(double side1, double side2, double side3) {
  double angle = acos((pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) /
                      (2 * side1 * side2));
  return angle * (180 / PI);
}

bool kiemtra_tamgiac(double xA, double yA, double xB, double yB, double xC,
                     double yC) {
  // Kiểm tra điều kiện tồn tại tam giác
  if ((xA == xB && yA == yB) || (xA == xC && yA == yC) ||
      (xB == xC && yB == yC)) {
    return false;  // Hai điểm trùng nhau, không tạo thành tam giác
  }

  double slope1 = (yB - yA) / (xB - xA);
  double slope2 = (yC - yA) / (xC - xA);

  // Kiểm tra điều kiện không thẳng hàng
  if (slope1 == slope2) {
    return false;  // Ba điểm thẳng hàng, không tạo thành tam giác
  }
  return true;
}

void goccanh_tamgiac(double xA, double yA, double xB, double yB, double xC,
                     double yC) {
  // Tính độ dài các cạnh của tam giác
  double AB = calculate_distance(xA, yA, xB, yB);
  double BC = calculate_distance(AB, yB, xC, yC);
  double CA = calculate_distance(xC, yC, xA, yA);

  // Tính góc của tam giác
  double angleA = calculate_angle(CA, AB, BC);
  double angleB = calculate_angle(AB, BC, CA);
  double angleC = calculate_angle(BC, CA, AB);

  // [AB, BC, CA, góc A, góc B, góc C]
  distance_angle[0] = AB;
  distance_angle[1] = BC;
  distance_angle[2] = CA;
  distance_angle[3] = angleA;
  distance_angle[4] = angleB;
  distance_angle[5] = angleC;
}

// Tính vector từ hai điểm
void calculateVector(int x1, int y1, int x2, int y2, int* vector) {
  vector[0] = x2 - x1;
  vector[1] = y2 - y1;
}

// Tính tích vô hướng của hai vector
int dotProduct(int* vector1, int* vector2) {
  return vector1[0] * vector2[0] + vector1[1] * vector2[1];
}

// Xác định loại tam giác
void xet_tam_giac(int ax, int ay, int bx, int by, int cx, int cy) {
  int vectorAB[2], vectorBC[2], vectorCA[2];

  calculateVector(ax, ay, bx, by, vectorAB);
  calculateVector(bx, by, cx, cy, vectorBC);
  calculateVector(cx, cy, ax, ay, vectorCA);

  int dotABBC = dotProduct(vectorAB, vectorBC);
  int dotABCA = dotProduct(vectorAB, vectorCA);

  if (dotABBC == 0 || dotABCA == 0) {
    printf("Tam giac ABC la tam giac vuong");
    if (dotABBC == 0 && dotABCA == 0) {
      printf(" can.\n");
    } else {
      printf(".\n");
    }
  } else if (dotABBC == dotABCA) {
    printf("Tam giac ABC la tam giac deu.\n");
  } else {
    printf("Tam giac ABC la tam giac thuong.\n");
  }
}

// Tính diện tích tam giác dựa trên công thức định lý Pick
double dientich_tamgiac(int ax, int ay, int bx, int by, int cx, int cy) {
  int area = 0;

  area = 0.5 * abs((ax * (by - cy)) + (bx * (cy - ay)) + (cx * (ay - by)));

  return area;  // Diện tích tam giác
}

// Tính đường cao của tam giác
double duongcao_tamgiac(int ax, int ay, int bx, int by, int cx, int cy) {
  double sideAB = calculate_distance(ax, ay, bx, by);
  double sideBC = calculate_distance(bx, by, cx, cy);
  double sideCA = calculate_distance(cx, cy, ax, ay);

  // Sử dụng công thức đường cao của tam giác
  double s = (sideAB + sideBC + sideCA) / 2;
  double altitude =
      (2 * sqrt(s * (s - sideAB) * (s - sideBC) * (s - sideCA))) / sideBC;

  return altitude;
}

// Tính đường trung tuyến của tam giác
void trungtuyen_tamgiac(int ax, int ay, int bx, int by, int cx, int cy) {
  median[0] = calculateDistance(ax, ay, (bx + cx) / 2, (by + cy) / 2);
  median[1] = calculateDistance(bx, by, (ax + cx) / 2, (ay + cy) / 2);
  median[2] = calculateDistance(cx, cy, (ax + bx) / 2, (ay + by) / 2);
}

// Tính đường trọng tâm của tam giác
void calculateCentroid(int ax, int ay, int bx, int by, int cx, int cy) {
  centroid[0] = (ax + bx + cx) / 3.0;
  centroid[1] = (ay + by + cy) / 3.0;
}

int main() {
  double xA, yA, xB, yB, xC, yC;

  printf("Nhap toa do diem A: ");
  scanf("%lf %lf", &xA, &yA);
  printf("Nhap toa do diem B: ");
  scanf("%lf %lf", &xB, &yB);
  printf("Nhap toa do diem C: ");
  scanf("%lf %lf", &xC, &yC);

  return 0;
}
