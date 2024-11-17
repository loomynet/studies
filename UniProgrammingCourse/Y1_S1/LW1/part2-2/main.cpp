#include <stdio.h>

int main() 
{

	double a;
	double pi;
	double area;

	printf ("This program calculates area of the circle, please, enter input data.\n");
	printf ("\nCircle radiuss (cm) is: ");
	scanf_s ("%lf", &a);

	pi = 3.1416;
	area = pi * a * a; // Fixed this one (a * a) --> a * a

	printf("\nArea of the circle is: %lf sq.cm \n", area);

	return 0;

}