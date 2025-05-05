#include <stdio.h>
#include <math.h>

// Define the function whose root you want to find
double func(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

void bisection(double a, double b, double tol, int max_iter) {
    if (func(a) * func(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c;
    int iter = 0;

    printf("Iter\t a\t\t b\t\t c\t\t f(c)\n");
    do {
        c = (a + b) / 2;
        printf("%d\t %lf\t %lf\t %lf\t %lf\n", iter, a, b, c, func(c));

        if (func(c) == 0.0 || fabs(b - a) < tol) {
            break;
        }

        if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (iter < max_iter);

    printf("\nRoot is: %.10lf\n", c);
}

int main() {
    double a = 1, b = 2;      // Interval where the root lies
    double tol = 1e-6;        // Tolerance
    int max_iter = 100;       // Maximum number of iterations

    bisection(a, b, tol, max_iter);
    return 0;
}
