#include <stdio.h>
#include <math.h>

#define SIZE 10
#define EPSILON 0.001
#define MAX_ITER 100

void gaussSeidel(int n) {
    float a[SIZE][SIZE], b[SIZE], x[SIZE] = {0};
    int i, j, iter = 0;
    float sum, diff, max_diff;

    // Input matrix A and vector B
    printf("Enter the coefficients of the matrix A (row by row):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants vector B:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Iterative calculation
    printf("\nIteration results:\n");
    do {
        max_diff = 0;
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            diff = fabs((sum / a[i][i]) - x[i]);
            if (diff > max_diff)
                max_diff = diff;

            x[i] = sum / a[i][i];
        }

        iter++;
        printf("Iteration %d: ", iter);
        for (i = 0; i < n; i++) {
            printf("x[%d] = %.4f  ", i + 1, x[i]);
        }
        printf("\n");

    } while (max_diff > EPSILON && iter < MAX_ITER);

    printf("\nFinal solution after %d iterations:\n", iter);
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int n;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    gaussSeidel(n);

    return 0;
}
