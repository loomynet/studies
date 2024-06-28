#include <stdio.h>

// Added all the necessary operations

int main() {
    
    double a;
    double b;
    double square_a;
    double square_b;
    double add;
    double sub;
    double multiplication;
    double division;

    printf("Enter the first number: ");
    scanf_s("%lf", &a);
    printf("Enter the second number: ");
    scanf_s("%lf", &b);

    square_a = a * a;
    square_b = b * b;
    add = a + b;
    sub = a - b;
    multiplication = a * b;
    division = a / b;

    printf("\nSquare of %.2lf is %.2lf\n", a, square_a);
    printf("\nSquare of %.2lf is %.2lf\n", b, square_b);
    printf("\n%.2lf + %.2lf = %.2lf\n", a, b, add);
    printf("\n%.2lf - %.2lf = %.2lf\n", a, b, sub);
    printf("\n%.2lf * %.2lf = %.2lf\n", a, b, multiplication);
    printf("\n%.2lf / %.2lf = %.2lf\n", a, b, division);

    return 0;
}