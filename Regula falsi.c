#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100

// Define the function: f(x) = x^3 - x - 2
double f(double x) {
    return x * x * x - x - 2;
}

void regulaFalsi(double a, double b) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c;
    int iteration = 0;

    printf("Regula Falsi Method:\n");
    while (iteration < MAX_ITER) {
        // Calculate the point of intersection with x-axis
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("Iteration %d: c = %.6lf, f(c) = %.6lf\n", iteration + 1, c, f(c));

        if (fabs(f(c)) < EPSILON) {
            printf("\nRoot found at x = %.6lf after %d iterations\n", c, iteration + 1);
            return;
        }

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iteration++;
    }

    printf("\nMethod did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double a, b;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    regulaFalsi(a, b);

    return 0;
}
