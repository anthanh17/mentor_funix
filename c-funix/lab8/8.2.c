#include <stdio.h>

char board[3][3];  // Bảng Tic Tac Toe 3x3

// Khởi tạo bảng
void initializeBoard() {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// In bảng hiện tại
void printBoard() {
  int i, j;
  for (i = 0; i < 3; i++) {
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i != 2) {
      printf("---|---|---\n");
    }
  }
}

// Kiểm tra xem có người chiến thắng hay không
int checkWin() {
  int i;

  // Kiểm tra theo hàng và cột
  for (i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if (board[i][0] == 'X')
        return 1;  // Người chơi X chiến thắng
      else if (board[i][0] == 'O')
        return 2;  // Người chơi O chiến thắng
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      if (board[0][i] == 'X')
        return 1;  // Người chơi X chiến thắng
      else if (board[0][i] == 'O')
        return 2;  // Người chơi O chiến thắng
    }
  }

  // Kiểm tra theo đường chéo
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if (board[0][0] == 'X')
      return 1;  // Người chơi X chiến thắng
    else if (board[0][0] == 'O')
      return 2;  // Người chơi O chiến thắng
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    if (board[0][2] == 'X')
      return 1;  // Người chơi X chiến thắng
    else if (board[0][2] == 'O')
      return 2;  // Người chơi O chiến thắng
  }

  return 0;  // Không có người chiến thắng
}

// Kiểm tra xem bảng đã đầy hay chưa
int isBoardFull() {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == ' ') return 0;  // Bảng chưa đầy
    }
  }
  return 1;  // Bảng đã đầy
}

// Thực hiện lượt chơi
void playTurn(char player) {
  int row, col;

  printf("Lượt chơi của người chơi %c\n", player);
  printf("Nhập vị trí (hàng, cột): ");
  scanf("%d%d", &row, &col);

  // Kiểm tra xem vị trí đã hợp lệ chưa và bảng tại vị trí đó chưa được đánh
  while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
    printf("Vị trí không hợp lệ. Vui lòng nhập lại: ");
    scanf("%d%d", &row, &col);
  }

  board[row][col] = player;
}

int main() {
  int currentPlayer = 1;  // 1: Người chơi X, 2: Người chơi O
  int gameStatus = 0;  // 0: Đang chơi, 1: Người chơi X chiến thắng, 2: Người
                       // chơi O chiến thắng, 3: Hòa

  initializeBoard();

  printf("Chào mừng đến với trò chơi Tic Tac Toe!\n");

  while (gameStatus == 0) {
    printBoard();
    playTurn(currentPlayer == 1 ? 'X' : 'O');

    gameStatus = checkWin();

    if (gameStatus == 0 && isBoardFull()) {
      gameStatus = 3;  // Hòa
    }

    currentPlayer = (currentPlayer == 1)
                        ? 2
                        : 1;  // Chuyển lượt chơi cho người chơi tiếp theo
  }

  printBoard();

  // In kết quả
  if (gameStatus == 1) {
    printf("Người chơi X chiến thắng!\n");
  } else if (gameStatus == 2) {
    printf("Người chơi O chiến thắng!\n");
  } else {
    printf("Hòa!\n");
  }

  return 0;
}
