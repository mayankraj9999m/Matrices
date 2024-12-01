#include <stdio.h>
#include <stdlib.h>

// get two matrices
void create_matrix(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int n;
            printf("(%d,%d) = ", i, j);
            scanf("%d", &n);
            *(*(matrix + i) + j) = n;
        }
    }
}

// Function to print the 2D array
void print2DArray(int **matrix, int rows, int cols)
{
    printf("------------------------------------\n");
    for (int i = 0; i < rows; i++)
    {
        printf("[");
        for (int j = 0; j < cols; j++)
        {
            printf("%d, ", *(*(matrix + i) + j));
        }
        printf("]");
        printf("\n");
    }
    printf("------------------------------------\n");
}

void transposed(int **matrix, int row, int column, int **transpose)
{
    for (int r = 0; r < column; r++)
    {
        for (int c = 0; c < row; c++)
        {
            transpose[r][c] = matrix[c][r];
        }
    }
}

int main()
{
    int row, column;
    printf("Enter no. of rows : ");
    scanf("%d", &row);
    printf("Enter no. of columns : ");
    scanf("%d", &column);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int x = 0; x < row; x++)
    {
        matrix[x] = (int *)malloc(column * sizeof(int));
    }
    int **transpose = (int **)malloc(column * sizeof(int *));
    for (int x = 0; x < row; x++)
    {
        transpose[x] = (int *)malloc(row * sizeof(int));
    }
    create_matrix(matrix, row, column);
    print2DArray(matrix, row, column);
    transposed(matrix, row, column, transpose);
    print2DArray(transpose, column, row);
}