#include<stdio.h>

int main()
{
    enum Company {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO,
        EBAY,
        MICROSOFT
    };

    enum Company company;
    company = MICROSOFT;
    printf("%d\n",company);
    return 0;
}
