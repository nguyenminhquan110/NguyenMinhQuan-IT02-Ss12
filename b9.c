#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhập phần tử tại hàng %d, cột %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Ma trận:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm in các phần tử ở góc
void printCorners(int rows, int cols, int matrix[rows][cols]) {
    printf("Các phần tử ở góc:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == cols - 1) || 
                (i == rows - 1 && j == 0) || (i == rows - 1 && j == cols - 1)) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printBorders(int rows, int cols, int matrix[rows][cols]) {
    printf("Các phần tử nằm trên đường biên:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printDiagonals(int rows, int cols, int matrix[rows][cols]) {
    printf("Các phần tử nằm trên đường chéo chính và chéo phụ:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j || i + j == cols - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void printPrimes(int rows, int cols, int matrix[rows][cols]) {
    printf("Các phần tử là số nguyên tố:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPrime(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Nhập số dòng của ma trận: ");
    scanf("%d", &rows);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Số dòng và số cột phải lớn hơn 0.\n");
        return 1;
    }

    int matrix[rows][cols];

    int choice;
    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(rows, cols, matrix);
                break;
            case 2:
                printMatrix(rows, cols, matrix);
                break;
            case 3:
                printCorners(rows, cols, matrix);
                break;
            case 4:
                printBorders(rows, cols, matrix);
                break;
            case 5:
                printDiagonals(rows, cols, matrix);
                break;
            case 6:
                printPrimes(rows, cols, matrix);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 7);

    return 0;
}