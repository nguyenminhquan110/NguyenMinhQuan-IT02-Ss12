#include <stdio.h>

int findMax(int arr[], int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, length);
    printf("Số lớn nhất trong mảng là: %d\n", max);

    return 0;
}