#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 100

void inputArray(int arr[], int *length) {
    printf("Nhập số phần tử cần nhập (tối đa %d): ", CAPACITY);
    scanf("%d", length);
    if (*length > CAPACITY || *length <= 0) {
        printf("Số phần tử không hợp lệ.\n");
        *length = 0;
        return;
    }
    for (int i = 0; i < *length; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int length) {
    printf("Các phần tử trong mảng:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *length) {
    if (*length >= CAPACITY) {
        printf("Mảng đã đầy, không thể thêm phần tử.\n");
        return;
    }
    int value, index;
    printf("Nhập giá trị muốn thêm: ");
    scanf("%d", &value);
    printf("Nhập vị trí muốn thêm (0-%d): ", *length);
    scanf("%d", &index);
    if (index < 0 || index > *length) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }
    for (int i = *length; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*length)++;
}

void editElement(int arr[], int length) {
    int index, value;
    printf("Nhập vị trí muốn sửa (0-%d): ", length - 1);
    scanf("%d", &index);
    if (index < 0 || index >= length) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }
    printf("Nhập giá trị mới: ");
    scanf("%d", &value);
    arr[index] = value;
}

void deleteElement(int arr[], int *length) {
    int index;
    printf("Nhập vị trí muốn xóa (0-%d): ", *length - 1);
    scanf("%d", &index);
    if (index < 0 || index >= *length) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }
    for (int i = index; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
}

void sortAscending(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int length) {
    int value;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &value);
    bool found = false;
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            printf("Phần tử %d được tìm thấy tại vị trí %d.\n", value, i);
            found = true;
        }
    }
    if (!found) {
        printf("Phần tử %d không tồn tại trong mảng.\n", value);
    }
}
void binarySearch(int arr[], int length) {
    int value;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &value);
    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            printf("Phần tử %d được tìm thấy tại vị trí %d.\n", value, mid);
            return;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Phần tử %d không tồn tại trong mảng.\n", value);
}

int main() {
    int arr[CAPACITY];
    int length = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhập số phần tử cần nhập và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử đang quản lý\n");
        printf("3. Thêm một phần tử vào vị trí chỉ định\n");
        printf("4. Sửa một phần tử ở vị trí chỉ định\n");
        printf("5. Xóa một phần tử ở vị trí chỉ định\n");
        printf("6. Sắp xếp các phần tử\n");
        printf("   a. Giảm dần\n");
        printf("   b. Tăng dần\n");
        printf("7. Tìm kiếm phần tử nhập vào\n");
        printf("   a. Tìm kiếm tuyến tính\n");
        printf("   b. Tìm kiếm nhị phân\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &length);
                break;
            case 2:
                printArray(arr, length);
                break;
            case 3:
                addElement(arr, &length);
                break;
            case 4:
                editElement(arr, length);
                break;
            case 5:
                deleteElement(arr, &length);
                break;
            case 6: {
                int subChoice;
                printf("Chọn kiểu sắp xếp:\n");
                printf("1. Giảm dần\n");
                printf("2. Tăng dần\n");
                printf("Lựa chọn của bạn: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sortDescending(arr, length);
                } else if (subChoice == 2) {
                    sortAscending(arr, length);
                } else {
                    printf("Lựa chọn không hợp lệ.\n");
                }
                break;
            }
            case 7: {
                int subChoice;
                printf("Chọn kiểu tìm kiếm:\n");
                printf("1. Tìm kiếm tuyến tính\n");
                printf("2. Tìm kiếm nhị phân\n");
                printf("Lựa chọn của bạn: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    linearSearch(arr, length);
                } else if (subChoice == 2) {
                    sortAscending(arr, length); // Sắp xếp trước khi tìm kiếm nhị phân
                    binarySearch(arr, length);
                } else {
                    printf("Lựa chọn không hợp lệ.\n");
                }
                break;
            }
            case 8:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 8);

    return 0;
}