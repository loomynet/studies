 #include <stdio.h>

 /* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating-point version */

int fahrReversed()
{

 printf("\nReversed F table:\n");

 float celsius;

 for (float fahr=300; fahr >=0;fahr-=20)
 {
 celsius = (5.0/9.0) * (fahr-32.0);
 printf("%3.0f %6.1f\n", fahr, celsius);
 }

}

int celsiusTable()
{
 printf("\nThe C table:\n");
 float fahr, celsius;
 float lower, upper, step;
 lower = 0; /* lower limit of temperatuire scale */
 upper = 150; /* upper limit */
 step = 10; /* step size */
 celsius = lower;
  
 while (celsius <= upper)
 {
 fahr = (celsius * 9/5) + 32;
 printf("%3.0f %6.1f\n", celsius, fahr);
 celsius = celsius + step;
 }
 
}	

int main()
{

 printf("\nThis is C to F and F to C temperature conversion table program.\n"); 
 printf("\nThe F table:\n");
 float fahr, celsius;
 float lower, upper, step;
 lower = 0; /* lower limit of temperatuire scale */
 upper = 300; /* upper limit */
 step = 20; /* step size */
 fahr = lower;

 while (fahr <= upper)
 {
 celsius = (5.0/9.0) * (fahr-32.0);
 printf("%3.0f %6.1f\n", fahr, celsius);
 fahr = fahr + step;
 }

 celsiusTable();

 fahrReversed();

 return 0;
}
