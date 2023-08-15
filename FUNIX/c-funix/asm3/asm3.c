#include <stdbool.h>
#include <stdio.h>

#define MAX_ROW 9
#define MAX_COLUMN 9
#define MAX 10

typedef struct POINT {
  int row;  // tọa độ x của nút

  int column;  // tọa độ y của nút

  int value;  // giá trị 0 hoặc 1 của nút

  bool visited;  // đánh dấu nút đã được đi qua

  // con trỏ trỏ đến nút liền trước đó trước khi đi đến nút này
  struct POINT *prev;
} point_t;

point_t matrix[MAX_ROW][MAX_COLUMN];

// ---------------------------------------------------------------------
// Setup Queue

typedef struct {
  point_t data[MAX];  // lưu trữ các nút

  int front;  // chỉ số đầu của hàng đợi

  int rear;  // chỉ số cuối của hàng đợi

} Queue;

// Hàm 1: Khởi tạo hàng đợi
void initQueue(Queue *q) {
  q->front = 0;
  q->rear = -1;
}

// Hàm 2: Kiểm tra xem hàng đợi có rỗng hay không? Hàng đợi rỗng là hàng đợi mà
// chỉ số của đầu của hàng đợi lớn hơn chỉ số cuối của hàng đợi
int isEmpty(Queue q) { return (q.rear < q.front); }

// Hàm 3: Kiểm tra xem hàng đợi đã đầy chưa? Hàng đợi được xem là đầy là khi chỉ
// số cuối của hàng đợi lớn hơn số lượng phần tử tối đa mà hàng đợi có thể chứa
int isFull(Queue q) {
  if ((q.rear - q.front) == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

// Hàm 4: Thêm phần tử vào cuối (rear) của hàng đợi.
void enQueue(Queue *q, point_t x) {
  if (!isFull(*q)) {
    if (q->rear == MAX - 1) {
      for (int i = q->front; i <= q->rear; i++) {
        q->data[i - q->front] = q->data[i];
      }

      q->rear = MAX - q->front - 1;
      q->front = 0;
    }

    q->rear = q->rear + 1;
    q->data[q->rear] = x;
  }
}

//  Hàm 5: Lấy phần tử đầu (front) ra khỏi hàng đợi.
point_t deQueue(Queue *q) {
  point_t d;

  if (!isEmpty(*q)) {
    d = q->data[q->front];
    q->front = q->front + 1;
  }

  if (q->front > q->rear) {
    initQueue(q);
  };

  return d;
}

// Hàm kiểm tra điểm bất kỳ có tọa độ nằm trong ma trận đã khai báo hay không
bool checkCoordinate(int dong, int cot) {
  bool ret = false;

  if ((0 <= dong < MAX_ROW) && (0 <= cot < MAX_COLUMN)) {
    ret = true;
  }

  return ret;
}

// Tìm các điểm xung quanh của điểm được xét nằm trên đường đi từ điểm nguồn
// O(0,0) đến điểm đích có giá trị bằng 1
// void findSurroundingPoint(int dong, int cot, point_t surroundingPnt[4],
//                           int *count) {
//   // khởi tạo số biến đếm số lượng các nút có thể đi được quanh 1 vị trí

//   int tempCnt = 0;

//   // kiểm tra xem vị trí điểm bên phải có đến được không?

//   if ((checkCoordinate(dong, cot + 1) == true) &&
//       (matrix[dong, cot + 1].value == 1)) {
//     surroundingPnt[tempCnt] = matrix[dong, cot + 1];

//     tempCnt++;
//   }

//   // kiểm tra xem vị trí điểm bên dưới có đến được không?

//   if ((checkCoordinate(dong + 1, cot) == true) &&
//       (matrix[dong + 1, cot].value == 1)) {
//     surroundingPnt[tempCnt] = matrix[dong + 1, cot];

//     tempCnt++;
//   }

//   // kiểm tra xem vị trí điểm bên trái có đến được không?

//   if ((checkCoordinate(dong, cot - 1) == true) &&
//       (matrix[dong, cot - 1].value == 1)) {
//     surroundingPnt[tempCnt] = matrix[dong, cot - 1];

//     tempCnt++;
//   }

//   // kiểm tra xem vị trí điểm bên trên có đến được không?

//   if ((checkCoordinate(dong - 1, cot) == true) &&
//       (matrix[dong - 1, cot].value == 1)) {
//     surroundingPnt[tempCnt] = matrix[dong - 1, cot];

//     tempCnt++;
//   }

//   *count = tempCnt;
// }

int main() {
  int temp[MAX_COLUMN][MAX_ROW] = {
      {1, 0, 0, 0, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 1, 0, 0, 1},
      {0, 1, 0, 1, 1, 0, 1, 0, 1}, {0, 1, 1, 0, 0, 1, 0, 1, 1},
      {0, 0, 1, 0, 1, 0, 1, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 1, 1, 0}};

  int i, j;
  for (i = 0; i < MAX_COLUMN; i++) {
    for (j = 0; j < MAX_ROW; j++) {
      matrix[i][j].row = i;
      matrix[i][j].column = j;
      matrix[i][j].visited = false;
      matrix[i][j].prev = NULL;
      matrix[i][j].value = temp[i][j];
    }
  }

  printf("\nCHUONG TRINH TIM DUONG NGAN NHAT TU O(0,0) DEN A(dong, cot):");
  printf("\nMa tran 9x9 bieu dien cho mat phang 2 chieu: \n");
  for (i = 0; i < MAX_COLUMN; i++) {
    for (j = 0; j < MAX_ROW; j++) {
      matrix[i][j].row = i;
      printf("%d ", matrix[i][j].value);
    }
    printf("\n");
  }

  int dong = 6;
  int cot = 6;
  printf("\nDuong di ngan nhat tu O(0,0) den A la: \n");

  // TODO(annt, nhap matrix va tim duong ngan nhat)

  return 0;
}
