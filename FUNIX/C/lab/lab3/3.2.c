#include <stdio.h>

int main() {
    char name[100];
    char dob[20];
    char mobile[20];

    printf("Nhập tên của bạn: ");
    scanf("%[^\n]", name);

    printf("Nhập ngày tháng năm sinh của bạn: ");
    scanf(" %[^\n]", dob);

    printf("Nhập số điện thoại của bạn: ");
    scanf(" %[^\n]", mobile);

    printf("Thông tin của bạn:\n");
    printf("Name: %s\n", name);
    printf("DOB: %s\n", dob);
    printf("Mobile: %s\n", mobile);

    return 0;
}
