#include <stdio.h>

int main()
{

	double base;
	double height;

	printf ("This program calculates area of the triangle, please, enter input data. \n");
	printf ("\nEnter base of a triangle (cm) : ");
	scanf_s ("%lf", &base);
	printf ("\nEnter height of a triangle (cm) : ");
	scanf_s ("%lf", &height);

	double area;
	area = 0.5 * base * height;

	printf("\nArea of the triangle is: %lf sq.cm\n", area);

	return 0;

}