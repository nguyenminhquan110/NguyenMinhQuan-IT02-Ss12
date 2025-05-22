#include <stdio.h>

long long factorial(int n) {
    if (n < 0) {
        return -1; // Trả về -1 nếu n là số âm
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;

    printf("Nhập một số nguyên: ");
    scanf("%d", &num);

    long long result = factorial(num);
    if (result == -1) {
        printf("Không thể tính giai thừa của số âm.\n");
    } else {
        printf("Giai thừa của %d là: %lld\n", num, result);
    }

    return 0;
}