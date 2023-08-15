#include <stdio.h>

int main() {
   FILE *file1, *file2, *file_merged;
   char ch;

   // Mở tệp tin 1 trong chế độ đọc ("r")
   file1 = fopen("file1.txt", "r");
   if (file1 == NULL) {
      printf("Không thể mở tệp tin 1.\n");
      return 1;
   }

   // Mở tệp tin 2 trong chế độ đọc ("r")
   file2 = fopen("file2.txt", "r");
   if (file2 == NULL) {
      printf("Không thể mở tệp tin 2.\n");
      fclose(file1);
      return 1;
   }

   // Mở tệp tin merged.txt trong chế độ ghi ("w")
   file_merged = fopen("merged.txt", "w");
   if (file_merged == NULL) {
      printf("Không thể tạo tệp tin merged.\n");
      fclose(file1);
      fclose(file2);
      return 1;
   }

   // Ghi dữ liệu từ tệp tin 1 vào tệp tin merged
   while ((ch = fgetc(file1)) != EOF) {
      fputc(ch, file_merged);
   }

   // Ghi dữ liệu từ tệp tin 2 vào tệp tin merged
   while ((ch = fgetc(file2)) != EOF) {
      fputc(ch, file_merged);
   }

   // Đóng tất cả các tệp tin
   fclose(file1);
   fclose(file2);
   fclose(file_merged);

   printf("Dữ liệu đã được nối và ghi vào tệp tin merged.txt.\n");

   return 0;
}
