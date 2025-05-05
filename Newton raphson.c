#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  // Tolerance for convergence
#define MAX_ITER 100    // Maximum iterations allowed

// Function whose root we are trying to find
// Example: f(x) = x^3 - x - 2
double f(double x) {
    return x * x * x - x - 2;
}

// Derivative of the function: f'(x) = 3x^2 - 1
double f_derivative(double x) {
    return 3 * x * x - 1;
}

void newtonRaphson(double initial_guess) {
    double x = initial_guess;
    double x_next;
    int iteration = 0;

    printf("Newton-Raphson Method for root finding:\n");
    printf("Initial guess: %.4lf\n", x);

    while (iteration < MAX_ITER) {
        double f_val = f(x);
        double f_deriv_val = f_derivative(x);

        if (fabs(f_deriv_val) < 1e-6) {
            printf("Derivative too small. Method fails.\n");
            return;
        }

        x_next = x - f_val / f_deriv_val;
        printf("Iteration %d: x = %.6lf\n", iteration + 1, x_next);

        if (fabs(x_next - x) < EPSILON) {
            printf("\nConverged to root: %.6lf after %d iterations\n", x_next, iteration + 1);
            return;
        }

        x = x_next;
        iteration++;
    }

    printf("Method did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double guess;

    printf("Enter initial guess: ");
    scanf("%lf", &guess);

    newtonRaphson(guess);

    return 0;
}
