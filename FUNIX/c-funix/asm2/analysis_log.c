#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "log.txt"
#define MAXLENGTHFILE 5000

char fileStr[MAXLENGTHFILE];

int fileToStr(char* str) {
  int status;
  FILE* fp = NULL;

  fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    printf("File does not exist\n");
    return -1;
  }

  status = fread(str, MAXLENGTHFILE, 1, fp);

  // printf("Noi dung cua file log.txt: \n%s", str);

  fclose(fp);
  fp = NULL;
  return status;
}

void JsonExtract(char json[], char hoten[], char gioitinh[], char sodienthoai[],
                 char email[]) {
  //  "{\"hoten\":\"Nguyen The An\",
  //    \"gioitinh\":\"nam\",\"sodienthoai\":\"123456789\",\"email\":"
  //       "\"annt@gmail.com\"}";

  /*
  mang info dung de luu thong tin cua hoten, gioitinh, sdt, email
  */
  char info[4][100];
  int i = 0;

  /*
  info[0] luu gia tri: {"hoten":"Nguyen The An"
  info[1] luu gia tri: "gioitinh":"nam"
  info[2] luu gia tri: "sodienthoai":"123456789"
  info[3] luu gia tri: "email":"annt@gmail.com"}
  */

  // Cat chuoi Json dua vao dau ','
  char* token = strtok(json, ",");

  while (token != NULL) {
    strcpy(info[i], token);
    ++i;
    token = strtok(NULL, ",");
  }

  // trich xuat ho ten
  char* hoten_token = strtok(info[0], ":");
  // hoten_token[0] luu gia tri: {"hoten"
  // hoten_token[0] luu gia tri: "Nguyen The An"
  strcpy(hoten, strtok(NULL, ":"));

  // trich xuat gioitinh
  token = strtok(NULL, ",");
  char* gioitinh_token = strtok(info[1], ":");
  // gioitinh_token[0] luu gia tri: "gioitinh"
  // gioitinh_token[1] luu gia tri: "nam"
  strcpy(gioitinh, strtok(NULL, ":"));

  // trich xuat sodienthoai
  token = strtok(NULL, ",");
  char* sodienthoai_token = strtok(info[2], ":");
  // sodienthoai_token[0] luu gia tri: "sodienthoai"
  // sodienthoai_token[1] luu gia tri: "123456789"
  strcpy(sodienthoai, strtok(NULL, ":"));

  // trich xuat email
  token = strtok(NULL, ",");
  char* email_token = strtok(info[3], ":");
  // email_token[0] luu gia tri: "email"
  // email_token[1] luu gia tri: "annt@gmail.com"}
  strcpy(email, strtok(NULL, ":"));

  // xoa bo dau '}' nam cuoi cung cua email
  if (email[strlen(email) - 1] == '}') {
    email[strlen(email) - 1] = '\0';
  }
}

char* multi_tok(char* input, char* delimiter) {
  // Khai báo một biến static string, được sử dụng để lưu trữ trạng thái của
  // chuỗi đang được phân tích.
  static char* string;

  // Nếu tham số input không phải là NULL, string được gán bằng input. Điều này
  // xảy ra khi gọi hàm multi_tok lần đầu tiên hoặc muốn thay đổi chuỗi đang
  // được phân tích.
  if (input != NULL) string = input;

  // Kiểm tra xem string có phải là NULL hay không. Nếu là NULL, tức là đã phân
  // tích hết chuỗi và không còn mẩu tin nào nữa, hàm trả về NULL
  if (string == NULL) return string;

  // hàm strstr() để tìm vị trí của ký tự phân tách (delimiter) trong string.
  // Kết quả được lưu trữ trong con trỏ end.
  char* end = strstr(string, delimiter);

  // Nếu end là NULL, tức là không tìm thấy ký tự phân tách, chứng tỏ đã đến
  // cuối chuỗi. Trong trường hợp này, ta cần trả về mẩu tin cuối cùng và cập
  // nhật string thành NULL.
  if (end == NULL) {
    char* temp = string;
    string = NULL;
    return temp;
  }

  // Nếu end không phải là NULL, ta đã tìm thấy ký tự phân tách. Trước tiên, ta
  // gán ký tự null-terminator ('\0') cho vị trí end, từ đó tách mẩu tin từ temp
  // (bắt đầu từ đầu chuỗi) đến vị trí trước ký tự phân tách. Sau đó, cập nhật
  // string thành vị trí sau ký tự phân tách bằng cách thêm độ dài của
  // delimiter.
  char* temp = string;

  *end = '\0';
  string = end + strlen(delimiter);
  return temp;
}

// 1. Tính số bản tin gửi đi trong thời gian log.
int CountMessagesSent(const char* str, const char* sub) {
  int count = 0;
  int len = strlen(sub);

  if (len == 0) return 0;

  // Hàm strstr trả về con trỏ đến vị trí đầu tiên của chuỗi con trong chuỗi cha
  // hoặc NULL nếu không tìm thấy.

  // Nếu strstr trả về NULL, tức là không tìm thấy chuỗi con nữa, vòng lặp kết
  // thúc và chương trình trả về giá trị count, là số lần xuất hiện của chuỗi
  // con trong chuỗi cha.

  // Nếu strstr trả về một con trỏ hợp lệ, tức là tìm thấy chuỗi con, chúng ta
  // tăng giá trị của count lên 1 và di chuyển con trỏ str để tiếp tục tìm kiếm
  // chuỗi con từ vị trí tiếp theo. Điều này được thực hiện bằng cách cộng len
  // vào con trỏ str.

  while ((str = strstr(str, sub)) != NULL) {
    count++;
    str += len;
  }

  return count;
}

// 2. Tính số bản tin được gửi đi từ thiết bị cho trước, các bạn nhập vào các mã
// network của thiết bị sau đó, chương trình sẽ lọc ra và hiển thị các bản tin
// của thiết bị đó. Viết hàm trả về số bản tin gửi đi của từ thiết bị khi nhập
// mã network và hiển thị các bản tin của thiết bị đó.

int countMessagesSentFromNetworkCode(char* str, const char* code) {
  int count = 0;
  bool is_set = false;
  bool is_network_code = false;

  char data[18][300];
  char line_display[300];

  char* line = strtok(str, "\n");
  int i = 0;

  while (line != NULL) {
    strcpy(data[i], line);
    i++;
    line = strtok(NULL, "\n");
  }

  int j;

  for (j = 0; j < i; j++) {
    strcpy(line_display, data[j]);

    char* token = strtok(line_display, "]");
    token = strtok(NULL, "]");
    token = strtok(NULL, "]");
    // printf("\n%s ", token);

    if (strstr(token, "\"cmd\":\"set\"") != NULL) {
      is_set = true;
    } else {
      is_set = false;
    }

    token = strtok(NULL, "]");
    token = strtok(NULL, ":");
    token = strtok(NULL, "\"");

    // printf("\n%s", token);

    if (strstr(token, code) != NULL) {
      is_network_code = true;
    } else {
      is_network_code = false;
    }

    if (is_set && is_network_code) {
      printf("\n%s\n", data[j]);
      count++;
    }
  }

  printf("\n------------------------\n");
  return count;
}

int main() {
  char data_file[MAXLENGTHFILE];
  if (fileToStr(data_file) < 0) return 0;
  // printf("Noi dung cua file log.txt: \n%s", buffer);
  // printf("so ban tin: %d", CountMessagesSent(data_file, "\"cmd\":\"set\""));

  char network_code[30] = "DC53";
  printf("\nNhap dia chi nwk cua thiet bi: ");
  fgets(network_code, sizeof(network_code), stdin);
  network_code[strcspn(network_code, "\n")] =
      '\0';  // Xóa ký tự newline từ fgets

  printf("So ban tin gui di la: %d ",
         countMessagesSentFromNetworkCode(data_file, network_code));

  return 0;
}
