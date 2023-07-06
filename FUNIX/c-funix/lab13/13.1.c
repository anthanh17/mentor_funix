#include <stdio.h>

int main() {
   FILE *file;
   char data[100];

   // Mở tệp tin trong chế độ ghi ("w")
   file = fopen("test.txt", "w");

   if (file == NULL) {
      printf("Không thể mở tệp tin.\n");
      return 1;
   }

   printf("Nhập thông tin để lưu trữ trong tệp tin:\n");
   fgets(data, sizeof(data), stdin);

   // Ghi thông tin vào tệp tin
   fprintf(file, "%s", data);

   // Đóng tệp tin
   fclose(file);

   printf("Thông tin đã được lưu trữ trong tệp tin thành công.\n");

   return 0;
}
