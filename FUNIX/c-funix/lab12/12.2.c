#include <stdio.h>

#define MAX_EMPLOYEES 100

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    float salary;
    struct Date birthDate;
};

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees;

    printf("Nhập số lượng nhân viên: ");
    scanf("%d", &numEmployees);

    // Nhập thông tin cho từng nhân viên
    for (int i = 0; i < numEmployees; i++) {
        printf("Nhập thông tin cho nhân viên %d:\n", i + 1);
        printf("Tên: ");
        scanf("%s", employees[i].name);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Tiền lương: ");
        scanf("%f", &employees[i].salary);
        printf("Ngày sinh (ngày/tháng/năm): ");
        scanf("%d/%d/%d", &employees[i].birthDate.day, &employees[i].birthDate.month, &employees[i].birthDate.year);
        printf("\n");
    }

    // Hiển thị thông tin của các nhân viên đã nhập
    printf("Thông tin chi tiết của nhân viên:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Nhân viên %d:\n", i + 1);
        printf("Tên: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        printf("Tiền lương: %.2f\n", employees[i].salary);
        printf("Ngày sinh: %d/%d/%d\n", employees[i].birthDate.day, employees[i].birthDate.month, employees[i].birthDate.year);
        printf("\n");
    }

    return 0;
}
