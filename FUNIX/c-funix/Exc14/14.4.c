#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *localTime;
    char dateTime[100];

    // Lấy thời gian hiện tại của hệ thống
    currentTime = time(NULL);

    // Chuyển đổi thời gian thành cấu trúc tm (thời gian địa phương)
    localTime = localtime(&currentTime);

    // Định dạng ngày và giờ
    strftime(dateTime, sizeof(dateTime), "%d/%m/%Y %H:%M:%S", localTime);

    // In ra ngày và giờ
    printf("Ngày và giờ hiện tại: %s\n", dateTime);

    return 0;
}
