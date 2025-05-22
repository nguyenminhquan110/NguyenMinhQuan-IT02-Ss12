#include <stdio.h>

void printArray(int arr[], int length) {
    printf("Các phần tử trong mảng là:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length);

    return 0;
}