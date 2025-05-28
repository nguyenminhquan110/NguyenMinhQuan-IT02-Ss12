#include <stdio.h>

void createMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhập phần tử tại hàng %d, cột %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Ma trận vừa nhập là:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &rows);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Số hàng và số cột phải lớn hơn 0.\n");
        return 1;
    }

    int matrix[rows][cols];

    createMatrix(rows, cols, matrix);

    printMatrix(rows, cols, matrix);

    return 0;
}