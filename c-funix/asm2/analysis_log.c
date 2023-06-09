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

// 1. Tính số bản tin gửi đi trong thời gian log.
int CountMessagesSent(const char *str, const char *sub) {
    int count = 0;
    int len = strlen(sub);

    if (len == 0)
        return 0;
        
    // Hàm strstr trả về con trỏ đến vị trí đầu tiên của chuỗi con trong chuỗi cha 
    // hoặc NULL nếu không tìm thấy.
    
    // Nếu strstr trả về NULL, tức là không tìm thấy chuỗi con nữa, vòng lặp kết thúc 
    // và chương trình trả về giá trị count, là số lần xuất hiện của chuỗi con trong chuỗi cha.
    
    // Nếu strstr trả về một con trỏ hợp lệ, tức là tìm thấy chuỗi con, chúng ta tăng giá trị 
    // của count lên 1 và di chuyển con trỏ str để tiếp tục tìm kiếm chuỗi con từ vị trí tiếp theo. 
    // Điều này được thực hiện bằng cách cộng len vào con trỏ str.

    while ((str = strstr(str, sub)) != NULL)
    {
        count++;
        str += len;
    }

    return count;
}

// 2. Tính số bản tin được gửi đi từ thiết bị cho trước, các bạn nhập vào các mã network của thiết bị sau đó, 
// chương trình sẽ lọc ra và hiển thị các bản tin của thiết bị đó. Viết hàm trả về số bản tin gửi đi của từ 
// thiết bị khi nhập mã network và hiển thị các bản tin của thiết bị đó.

int countMessagesSentFromNetworkCode(const char *str, const char *code) {
    return 0;
}

int main() {
  char data_file[MAXLENGTHFILE];
  if (fileToStr(data_file) < 0)
    return 0;
  // printf("Noi dung cua file log.txt: \n%s", buffer);
  printf("so ban tin: %d", CountMessagesSent(data_file, "\"cmd\":\"set\""));
  
  char network_code[30];
  printf("\nNhap dia chi nwk cua thiet bi: ");
  fgets(network_code, sizeof(network_code), stdin);
  // printf("Name: %s", name);
  
  countMessagesSentFromNetworkCode(data_file, network_code);
  return 0;
}
