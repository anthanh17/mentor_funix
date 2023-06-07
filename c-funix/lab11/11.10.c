#include <stdio.h>
#include <string.h>

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
  static char* string;
  if (input != NULL) string = input;

  if (string == NULL) return string;

  char* end = strstr(string, delimiter);
  if (end == NULL) {
    char* temp = string;
    string = NULL;
    return temp;
  }

  char* temp = string;

  *end = '\0';
  string = end + strlen(delimiter);
  return temp;
}

int main() {
  char json[] =
      "[{\"hoten\":\"Nguyen The "
      "An\",\"gioitinh\":\"nam\",\"sodienthoai\":\"123456789\",\"email\":"
      "\"annt@gmail.com\"},{\"hoten\":\"Nguyen The "
      "Nam\",\"gioitinh\":\"nam\",\"sodienthoai\":\"987654321\",\"email\":"
      "\"namtt@gmail.com\"},{\"hoten\":\"Nguyen Danh "
      "Vinh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"1824673\",\"email\":"
      "\"vinhnd@gmail.com\"},{\"hoten\":\"Nguyen Thi Thanh "
      "An\",\"gioitinh\":\"nu\",\"sodienthoai\":\"852469713\",\"email\":"
      "\"thanhnt@gmail.com\"}]";

  char ho_ten[100], gioi_tinh[100], so_dien_thoai[100], email[100];

  char khachhang[500];
  char hoten_nam[10][100];

  int sl_nam = 0;
  int sl_khachhang = 0;
  int i = 0;

  char* token = multi_tok(json, "},{");
  // printf("test1 %s\n", token);

  while (token != NULL) {
    strcpy(khachhang, token);
    // printf("test2 %s\n", khachhang);

    JsonExtract(khachhang, ho_ten, gioi_tinh, so_dien_thoai, email);
    // printf("test2 %s\n", khachhang);
    printf("test3\n");

    if (strcmp(gioi_tinh, "\"nam\"") == 0) {
      strcpy(hoten_nam[i], ho_ten);
      sl_nam++;
      i++;
    }
    sl_khachhang++;
    token = multi_tok(NULL, "},{");
  }

  printf("Co tong cong %d khach hang nam / tong so %d khach hang \n", sl_nam,
         sl_khachhang);
  if (sl_nam > 0) {
    printf("Ho ten cac khach hang nam: \n");
    for (i = 0; i < sl_nam; i++) {
      printf("%d. %s \n", i + 1, hoten_nam[i]);
    }
  }

  return 0;
}
