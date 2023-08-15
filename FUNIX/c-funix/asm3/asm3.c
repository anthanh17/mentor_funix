#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

// Khởi tạo hàng đợi
void initQueue(Queue *q) {
  q->front = 0;
  q->rear = -1;
}

// Kiểm tra xem hàng đợi có rỗng hay không?
int isEmpty(Queue q) { return (q.rear < q.front); }

// Kiểm tra xem hàng đợi đã đầy chưa?
int isFull(Queue q) {
  if ((q.rear - q.front) == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

// Thêm phần tử vào cuối (rear) của hàng đợi.
void enQueue(Queue *q, point_t *x) {
  if (!isFull(*q)) {
    if (q->rear == MAX - 1) {
      for (int i = q->front; i <= q->rear; i++) {
        q->data[i - q->front] = q->data[i];
      }

      q->rear = MAX - q->front - 1;
      q->front = 0;
    }

    q->rear = q->rear + 1;
    q->data[q->rear] = *x;
  }
}

// Lấy phần tử đầu (front) ra khỏi hàng đợi.
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

/* -------------------------------------------------------------------------- */
// Kiểm tra điểm bất kỳ có tọa độ nằm trong ma trận hay không?
bool checkCoordinate(int x, int y) {
  return (x >= 0 && x < MAX_ROW && y >= 0 && y < MAX_COLUMN);
}

// Tìm các điểm xung quanh của điểm được xét có giá trị bằng 1
void findSurroundingPoint(int dong, int cot, point_t surroundingPnt[4],
                          int *count) {
  // khởi tạo số biến đếm số lượng các nút có thể đi được quanh 1 vị trí

  int tempCnt = 0;

  // kiểm tra xem vị trí điểm bên phải có đến được không?

  if ((checkCoordinate(dong, cot + 1) == true) &&
      (matrix[dong][cot + 1].value == 1)) {
    surroundingPnt[tempCnt] = matrix[dong][cot + 1];

    tempCnt++;
  }

  // kiểm tra xem vị trí điểm bên dưới có đến được không?

  if ((checkCoordinate(dong + 1, cot) == true) &&
      (matrix[dong + 1][cot].value == 1)) {
    surroundingPnt[tempCnt] = matrix[dong + 1][cot];

    tempCnt++;
  }

  // kiểm tra xem vị trí điểm bên trái có đến được không?

  if ((checkCoordinate(dong, cot - 1) == true) &&
      (matrix[dong][cot - 1].value == 1)) {
    surroundingPnt[tempCnt] = matrix[dong][cot - 1];

    tempCnt++;
  }

  // kiểm tra xem vị trí điểm bên trên có đến được không?

  if ((checkCoordinate(dong - 1, cot) == true) &&
      (matrix[dong - 1][cot].value == 1)) {
    surroundingPnt[tempCnt] = matrix[dong - 1][cot];

    tempCnt++;
  }

  *count = tempCnt;
}

// Định nghĩa cấu trúc của một nút trong linked list
struct Node {
  point_t data;
  struct Node *next;
};

// Hàm để thêm một nút vào đầu danh sách liên kết
void push(struct Node **head_ref, point_t new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Ham tim duong ngan nhat bang thuat toan BFS
void shortestPathBFS(int destinationX, int destinationY) {
  // Các hướng di chuyển: lên, xuống, trái, phải
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  Queue q;
  initQueue(&q);
  enQueue(&q, &matrix[0][0]);
  matrix[0][0].visited = true;

  // Duyệt tất cả map theo chiều rộng
  while (!isEmpty(q)) {
    point_t temp = deQueue(&q);
    point_t *current = &matrix[temp.row][temp.column];

    // Kiểm tra nếu đã đến điểm đích
    if (current->row == destinationX && current->column == destinationY) {
      break;
    }

    // Xet cac huong di chuyen
    for (int i = 0; i < 4; ++i) {
      int newX = current->row + dx[i];
      int newY = current->column + dy[i];

      if (checkCoordinate(newX, newY) && !matrix[newX][newY].visited &&
          matrix[newX][newY].value == 1) {
        // thêm vào queue đển duyêt các phần tử xung quanh
        enQueue(&q, &matrix[newX][newY]);
        // đánh dấu điểm này là đã thăm
        matrix[newX][newY].visited = true;
        // đánh dấu điểm cha phụ vụ mục đích truy vết sau này
        matrix[newX][newY].prev = current;
      }
    }  // end for
  }    // end while

  // Sau khi duyệt xong ta truy vết để tìm đường đi ngắn nhất
  // Tồn tại 1 đường đi đến điểm đích
  if (matrix[destinationX][destinationY].visited) {
    point_t current = matrix[destinationX][destinationY];
    struct Node *head = NULL;
    int count = 0;

    while (current.row != 0 || current.column != 0) {
      push(&head, current);
      current = *current.prev;
      count++;
    }
    push(&head, matrix[0][0]);
    count++;

    printf("\nDuong di ngan nhat tu O(0,0) den A co do dai la %d o:\n", count);
    while (head != NULL) {
      printf(" -> (%d, %d)", head->data.row, head->data.column);
      head = head->next;
    }

  } else {
    printf("\nKhong co duong di tu diem (0,0) đến điểm đích \n");
  }  // end if - else
}

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
      matrix[i][j].value = temp[i][j];
      matrix[i][j].prev = NULL;
    }
  }

  printf("\nCHUONG TRINH TIM DUONG NGAN NHAT TU O(0,0) DEN A(dong, cot): \n");
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
  shortestPathBFS(dong, cot);

  return 0;
}
