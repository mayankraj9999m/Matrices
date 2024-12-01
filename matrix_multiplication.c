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

// Multiply two matrices
void mat_mul(int **m1, int **m2, int **m3, int r1, int r2, int c1, int c2)
{
    printf("Doing m1 x m2\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < r2; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main()
{
    int rows1, columns1;
    printf("----------------------\n");
    printf("MATRIX 1\n");
    printf("----------------------\n");
    printf("Enter no of rows: ");
    scanf("%d", &rows1);
    printf("Enter no of columns: ");
    scanf("%d", &columns1);

    int rows2, columns2;
    printf("----------------------\n");
    printf("MATRIX 2\n");
    printf("----------------------\n");
    printf("Enter no of rows: ");
    scanf("%d", &rows2);
    printf("Enter no of columns: ");
    scanf("%d", &columns2);

    if (columns1 == rows2)
    {
        // Allocating memory for these matrices
        int **mat1 = (int **)malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++)
        {
            mat1[i] = (int *)malloc(columns1 * sizeof(int));
        }

        int **mat2 = (int **)malloc(rows2 * sizeof(int *));
        for (int i = 0; i < rows2; i++)
        {
            mat2[i] = (int *)malloc(columns2 * sizeof(int));
        }

        int **result = (int **)malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++)
        {
            result[i] = (int *)malloc(columns2 * sizeof(int));
        }

        create_matrix(mat1, rows1, columns1);
        printf("**************NEXT****************\n");
        create_matrix(mat2, rows2, columns2);

        printf("Matrix 1\n");
        print2DArray(mat1, rows1, columns1);

        printf("Matrix 2\n");
        print2DArray(mat2, rows2, columns2);

        mat_mul(mat1, mat2, result, rows1, rows2, columns1, columns2);
        
        printf("Resultant Matrix\n");
        print2DArray(result, rows1, columns2);

        // Freeing the allocated memory
        for (int i = 0; i < rows1; i++)
        {
            free(mat1[i]);
        }
        free(mat1);

        for (int i = 0; i < rows2; i++)
        {
            free(mat2[i]);
        }
        free(mat2);

        for (int i = 0; i < rows1; i++)
        {
            free(result[i]);
        }
        free(result);
    }
    else
    {
        printf("Cannot do as column of 1st != row of 2nd\n^-^");
    }

    return 0;
}