#include <stdio.h>
#include <math.h>

#define SIZE 10

void gaussElimination(int n) {
    float a[SIZE][SIZE], x[SIZE];
    int i, j, k;

    // Input augmented matrix
    printf("Enter the augmented matrix (row by row):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        float pivot = a[i][i];
        if (pivot == 0) {
            printf("Zero pivot encountered. Cannot proceed.\n");
            return;
        }

        for (j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        // Make below rows 0 in the current column
        for (k = i + 1; k < n; k++) {
            float factor = a[k][i];
            for (j = 0; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
    }

    // Display result
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }
}

int main() {
    int n;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    gaussElimination(n);

    return 0;
}
