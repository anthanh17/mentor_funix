#include <stdio.h>

enum Company {
    Google,
    Facebook,
    Xerox,
    Yahoo,
    Ebay,
    Microsoft
};

int main() {
    enum Company company = Google;

    printf("Giá trị ban đầu của company: %d\n", company);

    // Thay đổi giá trị của company thành Microsoft
    company = Microsoft;

    printf("Giá trị sau khi thay đổi: %d\n", company);

    return 0;
}
