#include <stdio.h>

int main() {
   FILE *file;
   char data[100];

   // Mở tệp tin trong chế độ đọc ("r")
   file = fopen("test.txt", "r");

   if (file == NULL) {
      printf("Không thể mở tệp tin.\n");
      return 1;
   }

   printf("Nội dung trong tệp tin:\n");

   // Đọc và hiển thị nội dung từ tệp tin
   while (fgets(data, sizeof(data), file) != NULL) {
      printf("%s", data);
   }

   // Đóng tệp tin
   fclose(file);

   return 0;
}
