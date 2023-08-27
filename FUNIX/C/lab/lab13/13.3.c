#include <stdio.h>

struct Distance {
    int feet;
    int inch;
};

void addDistance(struct Distance d1, struct Distance d2) {
    struct Distance sum;
    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;

    // Xử lý trường hợp khi tổng inch vượt quá 12
    if (sum.inch >= 12) {
        sum.feet += sum.inch / 12;
        sum.inch %= 12;
    }

    printf("Tổng hai khoảng cách: %d feet %d inch\n", sum.feet, sum.inch);
}

int main() {
    struct Distance distance1, distance2;

    printf("Nhập khoảng cách thứ nhất:\n");
    printf("Feet: ");
    scanf("%d", &distance1.feet);
    printf("Inch: ");
    scanf("%d", &distance1.inch);

    printf("Nhập khoảng cách thứ hai:\n");
    printf("Feet: ");
    scanf("%d", &distance2.feet);
    printf("Inch: ");
    scanf("%d", &distance2.inch);

    addDistance(distance1, distance2);

    return 0;
}
