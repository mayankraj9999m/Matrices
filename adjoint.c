#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        printf("[ ");
        for (int j = 0; j < column; j++)
        {
            printf("%d, ", matrix[i][j]);
        }
        printf(" ]\n");
    }
}

void get_cofactor_matrix(int row, int c, int **new_matrix, int **matrix, int r)
{
    int i = 0, j = 0;
    for (int row1 = 0; row1 < row; row1++)
    {
        for (int col = 0; col < row; col++)
        {
            if (row1 != r && col != c)
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
        get_cofactor_matrix(row, c, new_matrix, matrix, 0);
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

void adjoint(int **matrix, int **adj, int r)
{
    int **new_matrix = (int **)malloc((r - 1) * sizeof(int *));
    for (int i = 0; i < (r - 1); i++)
    {
        new_matrix[i] = (int *)malloc((r - 1) * sizeof(int));
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            get_cofactor_matrix(r, j, new_matrix, matrix, i);
            adj[j][i] = determinant_of_a_matrix(r - 1, r, new_matrix);
        }
    }
    // Freeing Memory
    for (int i = 0; i < r - 1; i++)
    {
        free(new_matrix[i]);
    }
    free(new_matrix);
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
    print_matrix(matrix, x, x);
    int **adj = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        adj[i] = (int *)malloc(x * sizeof(int));
    }
    adjoint(matrix, adj, x);
    printf("The Adjoint of the matrix is\n");
    print_matrix(adj, x, x);

    // Freeing Memory
    for (int i = 0; i < x; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    press_any_key_to_exit();

    return 0;
}