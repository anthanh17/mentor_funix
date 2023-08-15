#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
  char string_file[MAXLENGTHFILE];
  strcpy(string_file, str);

  int count = 0;
  bool is_set = false;
  bool is_network_code = false;

  char data[18][300];
  char line_display[300];

  char* line = strtok(string_file, "\n");
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

// [Yêu cầu nâng cao] Câu 3: Tính số công tắc có trao đổi thông tin với bộ điều
// khiển trung tâm trong thời gian Log. Mỗi công tắc có 1 địa chỉ Network và
// Endpoint riêng biệt, trường "type" là "switch". Viết hàm hiển thị số lượng và
// địa chỉ của công tắc đã trao đổi thông tin với bộ điều khiển trung tâm trong
// thời gian Log.

int kiemTraChuoiCon(char arr[], char sub[]) {
  int len1 = strlen(arr);
  int len2 = strlen(sub);

  // Duyệt qua mảng arr để tìm chuỗi con sub
  for (int i = 0; i <= len1 - len2; i++) {
    int j;
    for (j = 0; j < len2; j++) {
      if (arr[i + j] != sub[j]) {
        break;
      }
    }
    if (j == len2) {
      return 1;  // Tìm thấy chuỗi con
    }
  }

  return 0;  // Không tìm thấy chuỗi con
}

void CalculateNumberSwitchesExchangeInfo(char* str) {
  char string_file[MAXLENGTHFILE];
  strcpy(string_file, str);

  struct Info {
    char network_addres[50];
    char endpoint[10];
  } store[20];

  char data[18][300];

  char* line = strtok(string_file, "\n");
  int i = 0;

  while (line != NULL) {
    strcpy(data[i], line);
    i++;
    line = strtok(NULL, "\n");
  }

  int j;

  //   bool is_switch = false;
  int index = 0;
  bool is_same = false;

  int k = 0;

  for (j = 0; j < i; j++) {
    char* token = strtok(data[j], "[");
    token = strtok(NULL, "[");
    token = strtok(NULL, ",");
    // printf("\n%s ", token);

    if (strstr(token, "\"type\":\"switch\"") != NULL) {
      token = strtok(NULL, "-");
      token = strtok(NULL, "]");

      char* code = strtok(token, ":");
      char* subcode1 = strtok(NULL, "-");
      char* subcode2 = strtok(NULL, "-");

      // Xu ly subcode2 căt bo " trong 1"
      char* end = subcode2 + strlen(subcode2) - 1;
      *end = '\0';

      k = 0;
      do {
        if (strcmp(store[k].network_addres, code) == 0) {
          is_same = true;
          break;
        }

        k++;
      } while (k < index);

      if (is_same) {
        is_same = false;
        continue;
      } else {
        strcpy(store[index].network_addres, code);
        strcpy(store[index].endpoint, subcode2);
        index++;
        is_same = false;
      }

    } else {
      continue;
    }
  }

  for (i = 0; i < index; i++) {
    printf("\nThiet bi %d co dia chi la: NWK - %s, ENDPOINT - %s", i + 1,
           store[i].network_addres, store[i].endpoint);
  }
}

// [Yêu cầu nâng cao] Câu 4: Tính số bản tin gửi đi bị lỗi, không nhận phản hồi
// lại. Dựa vào "reqid", các bạn cần tìm ra số bản tin gửi đi mà không nhận được
// phản hồi. Viết hàm trả về giá trị số bản tin gửi đi bị lỗi.

int CountMessagesError(char* str) {
  int count = 0;

  char string_file[MAXLENGTHFILE];
  strcpy(string_file, str);

  char data[18][300];

  char* line = strtok(string_file, "\n");
  int i = 0;

  while (line != NULL) {
    strcpy(data[i], line);
    i++;
    line = strtok(NULL, "\n");
  }

  int e = 0;
  char even[9][10];  // chan

  int o = 0;
  char odd[9][10];  // le

  int j;
  for (j = 0; j < i; j++) {
    if (j % 2 == 0) {
      char* token = strtok(data[j], "[");
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      // printf("\n%s ", token);
      strcpy(even[e], token);
      e++;
      // printf("\n------------------------");
    } else {
      char* token = strtok(data[j], "[");
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      // printf("\n%s ", token);
      strcpy(odd[o], token);
      o++;
      // printf("\n------------------------");
    }
    // break;
  }
  int k;
  for (k = 0; k < 9; k++) {
    if (strcmp(even[k], odd[k]) != 0) {
      count++;
    }
  }

  return count;
}

// Câu 5: Tính độ trễ lớn nhất giữa bản tin gửi đi và bản tin phản hồi, tính
// bằng mili giây (ms). Dựa vào trường thời gian, các bạn có thể tính bằng cách
// lấy thời gian phản hồi trừ đi thời gian gửi đi, không tính đến các bản tin
// lỗi. Viết hàm tìm độ trễ lớn nhất giữa các bản tin gửi đi và bản tin phản
// hồi.

void removeFirstTwoChars(char* str) {
  str += 2;

  while (*str) {
    *(str - 2) = *str;
    str++;
  }
  *(str - 2) = '\0';
}

int calc_mili(const char* str) {
  char chuoi[256];
  strcpy(chuoi, str);

  char* token;

  char h[10];
  char m[10];
  char s[10];

  // Tách thành phần giờ
  token = strtok(chuoi, ":");
  // printf("Giờ: %s\n", token);
  strcpy(h, token);

  // Tách thành phần phút
  token = strtok(NULL, ":");
  // printf("Phút: %s\n", token);
  strcpy(m, token);

  // Tách thành phần giây
  token = strtok(NULL, ":");
  // printf("Giây: %s\n", token);
  strcpy(s, token);

  return atoi(h) * 3600000 + atoi(m) * 60000 + atoi(s) * 1000;
}

int DelayMax(char* str) {
  int maxdelay = 0;

  char string_file[MAXLENGTHFILE];
  strcpy(string_file, str);

  char data[18][300];

  char* line = strtok(string_file, "\n");
  int i = 0;

  // split line
  while (line != NULL) {
    strcpy(data[i], line);
    i++;
    line = strtok(NULL, "\n");
  }

  // split time and reqid
  struct Info {
    char time_raw[20];
    char reqid[10];
  } temp[18];

  int j;
  for (j = 0; j < i; j++) {
    if (j % 2 == 0) {
      char* token = strtok(data[j], "]");
      token = strtok(NULL, "-");
      token = strtok(NULL, "-");
      token = strtok(NULL, "]");
      strcpy(temp[j].time_raw, token);
      removeFirstTwoChars(temp[j].time_raw);
      // printf("\ntime %d: %s ", j, temp[j].time_raw);

      // reqid
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      strcpy(temp[j].reqid, token);
      // printf("\nreqid %d: %s ", j, temp[j].reqid);
    } else {
      char* token = strtok(data[j], "]");
      token = strtok(NULL, "-");
      token = strtok(NULL, "-");
      token = strtok(NULL, "]");
      strcpy(temp[j].time_raw, token);
      removeFirstTwoChars(temp[j].time_raw);
      // printf("\ntime %d: %s ", j, temp[j].time_raw);

      // reqid
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      strcpy(temp[j].reqid, token);
      // printf("\nreqid %d: %s ", j, temp[j].reqid);
    }
  }

  int k;
  for (k = 0; k < 18;) {
    if (strcmp(temp[k].reqid, temp[k + 1].reqid) == 0) {
      // printf("\nreqid %d: %s ", k, temp[k].time_raw);
      // printf("\nreqid %d: %s \n", k + 1, temp[k+1].time_raw);
      int total = calc_mili(temp[k + 1].time_raw) - calc_mili(temp[k].time_raw);

      if (total > maxdelay) {
        maxdelay = total;
      }
    }
    k += 2;
  }

  return maxdelay;
}

// Câu 6: Tính thời gian trễ trung bình trong khoảng thời gian log, tương tự câu
// 5 thời gian trễ trung bình này chỉ tính trên các bản tin điều khiển thành
// công. Viết hàm tính độ trễ trung bình trong khoảng thời gian log, là giá trị
// trung bình cộng giữa các độ trễ của bản tin gửi đi và bản tin phản hồi.

int DelayTB(char* str) {
  char string_file[MAXLENGTHFILE];
  strcpy(string_file, str);

  char data[18][300];

  char* line = strtok(string_file, "\n");
  int i = 0;

  // split line
  while (line != NULL) {
    strcpy(data[i], line);
    i++;
    line = strtok(NULL, "\n");
  }

  // split time and reqid
  struct Info {
    char time_raw[20];
    char reqid[10];
  } temp[18];

  int j;
  for (j = 0; j < i; j++) {
    if (j % 2 == 0) {
      char* token = strtok(data[j], "]");
      token = strtok(NULL, "-");
      token = strtok(NULL, "-");
      token = strtok(NULL, "]");
      strcpy(temp[j].time_raw, token);
      removeFirstTwoChars(temp[j].time_raw);
      // printf("\ntime %d: %s ", j, temp[j].time_raw);

      // reqid
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      strcpy(temp[j].reqid, token);
      // printf("\nreqid %d: %s ", j, temp[j].reqid);
    } else {
      char* token = strtok(data[j], "]");
      token = strtok(NULL, "-");
      token = strtok(NULL, "-");
      token = strtok(NULL, "]");
      strcpy(temp[j].time_raw, token);
      removeFirstTwoChars(temp[j].time_raw);
      // printf("\ntime %d: %s ", j, temp[j].time_raw);

      // reqid
      token = strtok(NULL, "}");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      token = strtok(NULL, "\"");
      strcpy(temp[j].reqid, token);
      // printf("\nreqid %d: %s ", j, temp[j].reqid);
    }
  }

  int k;
  int total = 0;
  int count = 0;
  for (k = 0; k < 18;) {
    if (strcmp(temp[k].reqid, temp[k + 1].reqid) == 0) {
      // printf("\nreqid %d: %s ", k, temp[k].time_raw);
      // printf("\nreqid %d: %s \n", k + 1, temp[k+1].time_raw);
      total += (calc_mili(temp[k + 1].time_raw) - calc_mili(temp[k].time_raw));
      count++;
    }
    k += 2;
  }

  return total / count;
}

int main() {
  char data_file[MAXLENGTHFILE];
  if (fileToStr(data_file) < 0) return 0;
  // printf("Noi dung cua file log.txt: \n%s", buffer);

  // Cau 1
  printf("so ban tin: %d", CountMessagesSent(data_file, "\"cmd\":\"set\""));

  // Cau 2
  // to do xu ly TH hoa thuong
  char network_code[30];  // "DC53"
  printf("\nNhap dia chi nwk cua thiet bi: ");
  fgets(network_code, sizeof(network_code), stdin);
  // Xóa ký tự newline từ fgets
  network_code[strcspn(network_code, "\n")] = '\0';
  printf("So ban tin gui di la: %d ",
         countMessagesSentFromNetworkCode(data_file, network_code));

  // Cau 3
  CalculateNumberSwitchesExchangeInfo(data_file);

  // Cau 4
  printf("\nSo ban tin loi: %d ", CountMessagesError(data_file));

  // Cau 5
  printf("\nDo tre lon nhat la: %d Millisecond", DelayMax(data_file));

  // Cau 6
  printf("\nDo tre trung binh la: %d Millisecond", DelayTB(data_file));

  return 0;
}
