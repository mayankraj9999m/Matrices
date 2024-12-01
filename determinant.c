#include <stdio.h>
#include <stdlib.h>

void get_cofactor_matrix(int row, int c, int **new_matrix, int **matrix)
{
    int i = 0, j = 0;
    for (int row1 = 0; row1 < row; row1++)
    {
        for (int col = 0; col < row; col++)
        {
            if (row1 != 0 && col != c)
            {
                new_matrix[i][j++] = matrix[row1][col];
                if (j == row - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant_of_a_matrix(int row, int x, int **matrix)
{
    int det = 0;
    if (row == 1)
    {
        return matrix[0][0];
    }

    // int new_matrix[row-1][row-1]; // to store cofactor matrix
    int **new_matrix = (int **)malloc((row - 1) * sizeof(int *));
    for (int i = 0; i < (row - 1); i++)
    {
        new_matrix[i] = (int *)malloc((row - 1) * sizeof(int));
    }

    int sign = 1;
    for (int c = 0; c < row; c++)
    {
        get_cofactor_matrix(row, c, new_matrix, matrix);
        det += sign * matrix[0][c] * determinant_of_a_matrix((row - 1), x, new_matrix);
        sign = -sign;
    }

    for (int i = 0; i < row - 1; i++)
    {
        free(new_matrix[i]);
    }
    free(new_matrix);
    return det;
}

void press_any_key_to_exit()
{
    printf("\nPress any key to exit...\n");
    getchar(); // consume the newline character left by the previous input
    getchar(); // wait for user input
}

int main()
{
    printf("Enter dimension of your matrix(e.g, 4 --> 4x4) = ");
    int x;
    scanf("%d", &x);
    // int matrix[x][x];
    // Now , we will allocate memory to matrix using dynamic memory allocation
    int **matrix = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        matrix[i] = (int *)malloc(x * sizeof(int));
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("(%d,%d) = ", i, j);
            int y;
            scanf("%d", &y);
            matrix[i][j] = y;
        }
    }
    printf("\n---------------------------------\n");
    printf("Your Matrix is :\n");
    for (int i = 0; i < x; i++)
    {
        printf("[ ");
        for (int j = 0; j < x; j++)
        {
            printf("%d, ", matrix[i][j]);
        }
        printf(" ]\n");
    }
    
    printf("The Determinant of the matrix is %d", determinant_of_a_matrix(x, x, matrix));

    // Freeing Memory
    for (int i = 0; i < x; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    press_any_key_to_exit();

    return 0;
}