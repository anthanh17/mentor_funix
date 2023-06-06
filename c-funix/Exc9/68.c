#include<stdio.h>
#include<string.h>

int main() {
    char c;
    char s[100];
    scanf("%c", &c);
    scanf("%s", s);

    int len = strlen(s);
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            index = i;
            /*
            Gọi lệnh break để dừng vòng lặp do
            đã tìm thấy vị trí đầu tiên mà ký tự c xuất hiện.
            Nếu không có lệnh break thì kết quả của chương trình
            sẽ là vị trí cuối cùng mà ký tự c xuất hiện.
            */
            break;
        }
    }
    printf("%d", index);

    return 0;
}
