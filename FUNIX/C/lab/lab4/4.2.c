#include <stdio.h>

// Khai báo enum với tên các công ty
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

    switch (company) {
        case Google:
            printf("Công ty: Google\n");
            break;
        case Facebook:
            printf("Công ty: Facebook\n");
            break;
        case Xerox:
            printf("Công ty: Xerox\n");
            break;
        case Yahoo:
            printf("Công ty: Yahoo\n");
            break;
        case Ebay:
            printf("Công ty: Ebay\n");
            break;
        case Microsoft:
            printf("Công ty: Microsoft\n");
            break;
        default:
            printf("Công ty không xác định\n");
            break;
    }

    return 0;
}
