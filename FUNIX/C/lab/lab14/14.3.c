#include <stdio.h>

int main() {
   FILE *file;
   char ch;
   int line_count = 0;

   // Mở tệp tin trong chế độ đọc ("r")
   file = fopen("test.txt", "r");

   if (file == NULL) {
      printf("Không thể mở tệp tin.\n");
      return 1;
   }

   // Đếm số dòng trong tệp tin
   while ((ch = fgetc(file)) != EOF) {
      if (ch == '\n') {
         line_count++;
      }
   }

   // Đóng tệp tin
   fclose(file);

   printf("Số dòng trong tệp tin: %d\n", line_count);

   return 0;
}
