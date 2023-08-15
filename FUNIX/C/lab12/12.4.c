#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int age;
    char address[100];
    float gpa;
};

struct Classroom {
    struct Student students[MAX_STUDENTS];
    int count;
};

void print_menu() {
    printf("===== Quản lý học sinh =====\n");
    printf("1. Nhập thông tin học sinh\n");
    printf("2. Tìm thông tin học sinh\n");
    printf("3. Thoát\n");
}

void add_student(struct Classroom* classroom) {
    if (classroom->count >= MAX_STUDENTS) {
        printf("Danh sách học sinh đã đầy!\n");
        return;
    }

    struct Student student;
    printf("Họ và tên học sinh: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Xóa ký tự newline

    printf("Tuổi: ");
    scanf("%d", &student.age);
    getchar(); // Đọc ký tự newline sau scanf

    printf("Địa chỉ: ");
    fgets(student.address, sizeof(student.address), stdin);
    student.address[strcspn(student.address, "\n")] = '\0'; // Xóa ký tự newline

    printf("Điểm trung bình tích lũy GPA: ");
    scanf("%f", &student.gpa);
    getchar(); // Đọc ký tự newline sau scanf

    classroom->students[classroom->count] = student;
    classroom->count++;

    printf("Đã thêm thông tin học sinh thành công!\n");
}

void find_student(struct Classroom classroom) {
    char name[50];
    printf("Nhập tên học sinh cần tìm: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Xóa ký tự newline

    int found = 0;
    for (int i = 0; i < classroom.count; i++) {
        if (strcmp(classroom.students[i].name, name) == 0) {
            printf("Thông tin học sinh:\n");
            printf("Họ và tên: %s\n", classroom.students[i].name);
            printf("Tuổi: %d\n", classroom.students[i].age);
            printf("Địa chỉ: %s\n", classroom.students[i].address);
            printf("Điểm trung bình tích lũy GPA: %.2f\n", classroom.students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm thấy học sinh!\n");
    }
}

int main() {
    struct Classroom classroom;
    classroom.count = 0;

    while (1) {
        print_menu();

        char choice;
        printf("Nhập lựa chọn của bạn: ");
        scanf("%c", &choice);
        getchar(); // Đọc ký tự newline sau scanf

        switch (choice) {
            case '1':
                add_student(&classroom);
                break;
            case '2':
                find_student(classroom);
                break;
            case '3':
                return 0;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn lại.\n");
        }
    }

    return 0;
}
