/*
Yêu cầu: Thực hiện trích xuất và hiển thị thông tin từ một đối tượng JSON.
*/

#include <stdio.h>
#include <string.h>

void JsonExtract(char json[], char hoten[], char gioitinh[], char sodienthoai[],
                 char email[]) {
  /*
  mang info dung de luu thong tin cua hoten, gioitinh, sdt, email
  info[0] luu gia tri: {"hoten":"Nguyen The An"
  info[1] luu gia tri: "gioitinh":"nam"
  info[2] luu gia tri: "sodienthoai":"123456789"
  info[3] luu gia tri: "email":"annt@gmail.com"}
  */

  char info[4][100];
  int i = 0;

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

int main() {
  char json[] =
      "{\"hoten\":\"Nguyen The "
      "An\",\"gioitinh\":\"nam\",\"sodienthoai\":\"123456789\",\"email\":"
      "\"annt@gmail.com\"}";

  char ho_ten[100];
  char gioi_tinh[100];
  char so_dien_thoai[100];
  char email[100];

  JsonExtract(json, ho_ten, gioi_tinh, so_dien_thoai, email);

  printf("Thong tin cua doi tuong Json: \n");
  printf("Ho ten     : %s \n", ho_ten);
  printf("Gioi tinh  : %s \n", gioi_tinh);
  printf("Dien thoai : %s \n", so_dien_thoai);
  printf("Email      : %s \n", email);

  return 0;
}
