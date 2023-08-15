#include <stdio.h>
#include <math.h>

int main() {
    double base, exponent, result;

    printf("Nhập số cơ số: ");
    scanf("%lf", &base);

    printf("Nhập số mũ: ");
    scanf("%lf", &exponent);

    // Tính lũy thừa
    result = pow(base, exponent);
    printf("Kết quả lũy thừa: %.2lf\n", result);

    // Tính căn bậc hai
    if (base >= 0) {
        result = sqrt(base);
        printf("Căn bậc hai của %.2lf: %.2lf\n", base, result);
    } else {
        printf("Không thể tính căn bậc hai của một số âm.\n");
    }

    return 0;
}
