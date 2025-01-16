import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Lab1 {
    public static class Complex {
        private double real;
        private double imaginary;

        public Complex(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        public Complex add(double real, double imaginary) {
            return new Complex(this.real + real, this.imaginary + imaginary);
        }

        public Complex sub(double real, double imaginary) {
            return new Complex(this.real - real, this.imaginary - imaginary);
        }

        public Complex mul(double real, double imaginary) {
            double realPart = (this.real * real) - (this.imaginary * imaginary);
            double imaginaryPart = (this.real * imaginary) + (this.imaginary * real);
            return new Complex(realPart, imaginaryPart);
        }

        public Complex div(double real, double imaginary) throws ArithmeticException {
            double denominator = (real * real) + (imaginary * imaginary);
            if (denominator == 0) {
                throw new ArithmeticException("Cannot divide by a complex number with zero magnitude.");
            }

            double realPart = (this.real * real + this.imaginary * imaginary) / denominator;
            double imaginaryPart = (this.imaginary * real - this.real * imaginary) / denominator;
            return new Complex(realPart, imaginaryPart);
        }

        public Complex conjugate() {
            return new Complex(this.real, -this.imaginary);
        }

        public boolean compare(Complex other) {
            return (this.real == other.real) && (this.imaginary == other.imaginary);
        }

        public void display() {
            System.out.println(String.format("%.2f + %.2fi", real, imaginary));
        }        

        public void setReal(double real) {
            this.real = real;
        }

        public void setImaginary(double imaginary) {
            this.imaginary = imaginary;
        }

        public double getReal() {
            return this.real;
        }

        public double getImaginary() {
            return this.imaginary;
        }

    }

    public static void main(String[] args) {
        System.out.println("Author: Andrejs Jakunins");
        String timeStamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
        System.out.println("Date and time: " + timeStamp);

        Complex complex = new Complex(3, 4);
        Complex complexCompare = new Complex(3, 5);

        System.out.println("\nInitial complex number:");
        complex.display();

        System.out.println("\nAdd (1+2i):");
        Complex sum = complex.add(1,2);
        sum.display();

        System.out.println("\nSubtract (3+5i):");
        Complex difference = complex.sub(3, 5);
        difference.display();

        System.out.println("\nMultiply by (2+9i):");
        Complex product = complex.mul(2, 9);
        product.display();

        System.out.println("\nDivide by (0+0i):");
        try {
            Complex quotient = complex.div(0, 0);
            quotient.display();
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\nDivide by (3+7i):");
        try {
            Complex quotient = complex.div(3, 7);
            quotient.display();
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\nConjugate of initial complex number:");
        Complex conjugate = complex.conjugate();
        conjugate.display();

        System.out.println("\nAre initial complex number and complex number 3+5i equal?");
        System.out.println(complex.compare(complexCompare) ? "Yes" : "No");

        System.out.println("\nAre initial complex number and complex number 3+4i equal?");
        System.out.println(complex.compare(complex) ? "Yes" : "No");


        System.out.println("\nSet the real number of initial complex number to 1:");
        complex.setReal(1);
        complex.display();

        System.out.println("\nSet the imaginary number of initial complex number to 1:");
        complex.setImaginary(1);
        complex.display();

        System.out.println("\nGet the real number:");
        System.out.println(complex.getReal());

        System.out.println("\nGet the imaginary number:");
        System.out.println(complex.getImaginary());
    }
}