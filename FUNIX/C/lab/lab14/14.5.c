#include <stdio.h>

int main() {
   char old_name[] = "old_file.txt";  // Tên tệp tin cần đổi tên hoặc xóa
   char new_name[] = "new_file.txt";  // Tên mới sau khi đổi tên

   // Đổi tên tệp tin
   if (rename(old_name, new_name) == 0) {
      printf("Đổi tên tệp tin thành công.\n");
   } else {
      printf("Không thể đổi tên tệp tin.\n");
      return 1;
   }

   // Xóa tệp tin
   if (remove(new_name) == 0) {
      printf("Xóa tệp tin thành công.\n");
   } else {
      printf("Không thể xóa tệp tin.\n");
      return 1;
   }

   return 0;
}
