#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

double distance_angle[6] = {0};
double median[3] = {0};
double centroid[2] = {0};
double duong_cao[3] = {0};

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
  double BC = calculate_distance(xB, yB, xC, yC);
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

  // Tính độ dài các cạnh của tam giác
  double AB = calculate_distance(ax, ay, bx, by);
  double BC = calculate_distance(bx, by, cx, cy);
  double CA = calculate_distance(cx, cy, ax, ay);

  // Tính góc của tam giác
  double angleA = calculate_angle(CA, AB, BC);
  double angleB = calculate_angle(AB, BC, CA);
  double angleC = calculate_angle(BC, CA, AB);

  if (dotABBC == 0 || dotABCA == 0) {
    printf("Tam giac ABC la tam giac vuong");
    if (dotABBC == 0 && dotABCA == 0) {
      printf(" can ");
      if (angleA == 90)
        printf(" tai A \n");
      else if (angleB == 90)
        printf(" tai B \n");
      else if (angleC == 90)
        printf(" tai C \n");

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
double duongcao_tamgiac(double x1, double y1, double x2, double y2, double x3,
                        double y3) {
  // Đường cao h₁ từ điểm A:
  double h1 = fabs((x2 - x3) * (y1 - y2) - (x1 - x2) * (y2 - y3)) /
              sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
  // Đường cao h₂ từ điểm B:
  double h2 = fabs((x3 - x1) * (y2 - y3) - (x2 - x3) * (y3 - y1)) /
              sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
  // Đường cao h₃ từ điểm C:
  double h3 = fabs((x1 - x2) * (y3 - y1) - (x3 - x1) * (y1 - y2)) /
              sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

  duong_cao[0] = h1;
  duong_cao[1] = h2;
  duong_cao[2] = h3;
}

// Tính đường trung tuyến của tam giác
void trungtuyen_tamgiac(double ax, double ay, double bx, double by, double cx,
                        double cy) {
  median[0] = calculate_distance(ax, ay, (bx + cx) / 2, (by + cy) / 2);
  median[1] = calculate_distance(bx, by, (ax + cx) / 2, (ay + cy) / 2);
  median[2] = calculate_distance(cx, cy, (ax + bx) / 2, (ay + by) / 2);
}

// Tính đường trọng tâm của tam giác
void tam_tamgiac(double ax, double ay, double bx, double by, double cx,
                 double cy) {
  centroid[0] = (ax + bx + cx) / 3.0;
  centroid[1] = (ay + by + cy) / 3.0;
}

void giaima_tamgiac(double ax, double ay, double bx, double by, double cx,
                    double cy) {
  if (kiemtra_tamgiac(ax, ay, bx, by, cx, cy)) {
    printf("--------------------------------------------”\n");
    printf("Toa do 3 diem A, B, C hop thanh mot tam giac”\n");

    printf("1. So do co ban cua tam giac: \n");
    goccanh_tamgiac(ax, ay, bx, by, cx, cy);

    printf("  Chieu dai canh AB: %.2lf \n", distance_angle[0]);
    printf("  Chieu dai canh BC: %.2lf \n", distance_angle[1]);
    printf("  Chieu dai canh CA: %.2lf \n", distance_angle[2]);

    printf("  Goc A: %.2lf \n", distance_angle[3]);
    printf("  Goc A: %.2lf \n", distance_angle[4]);
    printf("  Goc A: %.2lf \n", distance_angle[5]);

    // tính chất của tam giác ABC
    xet_tam_giac(ax, ay, bx, by, cx, cy);
    printf("\n--------------------------------------------”\n");
    // diện tích của tam giác ABC
    printf("2. Dien tich cua tam giac ABC: %.2lf \n",
           dientich_tamgiac(ax, ay, bx, by, cx, cy));
    printf("--------------------------------------------”\n");
    // duong cao
    printf("3. So do nang cao tam giac ABC \n");
    duongcao_tamgiac(ax, ay, bx, by, cx, cy);
    printf("Do dai duong cao tu dinh A: %.2lf \n", duong_cao[0]);
    printf("Do dai duong cao tu dinh B: %.2lf \n", duong_cao[1]);
    printf("Do dai duong cao tu dinh C: %.2lf \n", duong_cao[2]);

    // trung tuyen
    trungtuyen_tamgiac(ax, ay, bx, by, cx, cy);
    printf("Do dai trung tuyen tu dinh A: %.2lf \n", median[0]);
    printf("Do dai trung tuyen tu dinh B: %.2lf \n", median[1]);
    printf("Do dai trung tuyen tu dinh C: %.2lf \n", median[2]);
    printf("--------------------------------------------”\n");
    // tam tam giac
    tam_tamgiac(ax, ay, bx, by, cx, cy);
    printf("4. Toa do diem dac biet cua tam giac ABC \n");
    printf("Toa do trong tam [%.2lf, %.2lf] \n", centroid[0], centroid[1]);

  } else {
    printf("A, B, C khong hop thanh mot tam giac\n");
  }
}

int main() {
  double xA, yA, xB, yB, xC, yC;

  printf("Nhap toa do diem A: \n");
  printf("xA: ");
  scanf("%lf", &xA);
  printf("yA: ");
  scanf("%lf", &yA);

  printf("Nhap toa do diem B: \n");
  printf("xB: ");
  scanf("%lf", &xB);
  printf("yB: ");
  scanf("%lf", &yB);

  printf("Nhap toa do diem C: \n");
  printf("xC: ");
  scanf("%lf", &xC);
  printf("yC: ");
  scanf("%lf", &yC);

  printf("Toa do diem A da nhap: A(%.2lf, %.2lf) \n", xA, yA);
  printf("Toa do diem B da nhap: B(%.2lf, %.2lf) \n", xB, yB);
  printf("Toa do diem C da nhap: C(%.2lf, %.2lf) \n", xC, yC);

  giaima_tamgiac(xA, yA, xB, yB, xC, yC);

  return 0;
}
