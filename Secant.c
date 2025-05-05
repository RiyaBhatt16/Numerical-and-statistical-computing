#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100

// Function whose root is to be found
// Example: f(x) = x^3 - x - 2
double f(double x) {
    return x * x * x - x - 2;
}

void secantMethod(double x0, double x1) {
    double x2;
    int iteration = 0;

    printf("Secant Method for root finding:\n");
    printf("Initial guesses: x0 = %.4lf, x1 = %.4lf\n", x0, x1);

    while (iteration < MAX_ITER) {
        double f_x0 = f(x0);
        double f_x1 = f(x1);

        if (fabs(f_x1 - f_x0) < 1e-6) {
            printf("Denominator too small. Method fails.\n");
            return;
        }

        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        printf("Iteration %d: x = %.6lf\n", iteration + 1, x2);

        if (fabs(x2 - x1) < EPSILON) {
            printf("\nConverged to root: %.6lf after %d iterations\n", x2, iteration + 1);
            return;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    }

    printf("Method did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double x0, x1;

    printf("Enter two initial guesses (x0 and x1): ");
    scanf("%lf %lf", &x0, &x1);

    secantMethod(x0, x1);

    return 0;
}
