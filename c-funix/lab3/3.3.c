#include<stdio.h>

int main()
{
    enum Company {
        GOOGLE,
        FACEBOOK,
        XEROX = 1,
        YAHOO,
        EBAY,
        MICROSOFT
    };

    enum Company google = GOOGLE;
    enum Company facebook = FACEBOOK;
    enum Company xerox = XEROX;
    enum Company yahoo = YAHOO;
    enum Company ebay = EBAY;
    enum Company microsoft = MICROSOFT;

    printf("The value of google: %d\n", google);
    printf("The value of facebook: %d\n", facebook);
    printf("The value of xerox: %d\n", xerox);
    printf("The value of yahoo: %d\n", yahoo);
    printf("The value of ebay: %d\n", ebay);
    printf("The value of microsoft: %d\n", microsoft);
    return 0;
}
