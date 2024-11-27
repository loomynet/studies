import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Lab1 {
    public static class Complex {
        private double real;
        private double imaginary;

        // Constructor
        public Complex(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        // Addition
        public Complex add(double real, double imaginary) {
            return new Complex(this.real + real, this.imaginary + imaginary);
        }

        // Subtraction
        public Complex sub(double real, double imaginary) {
            return new Complex(this.real - real, this.imaginary - imaginary);
        }

        // Multiplication
        public Complex mul(double real, double imaginary) {
            double realPart = (this.real * real) - (this.imaginary * imaginary);
            double imaginaryPart = (this.real * imaginary) + (this.imaginary * real);
            return new Complex(realPart, imaginaryPart);
        }

        // Division
        public Complex div(double real, double imaginary) throws ArithmeticException {
            double denominator = (real * real) + (imaginary * imaginary);
            if (denominator == 0) {
                throw new ArithmeticException("Cannot divide by a complex number with zero magnitude.");
            }

            double realPart = (this.real * real + this.imaginary * imaginary) / denominator;
            double imaginaryPart = (this.imaginary * real - this.real * imaginary) / denominator;
            return new Complex(realPart, imaginaryPart);
        }

        // Conjugate
        public Complex conjugate() {
            return new Complex(this.real, -this.imaginary);
        }

        // Comparison
        public boolean compare(Complex other) {
            return (this.real == other.real) && (this.imaginary == other.imaginary);
        }

        // Display method
        public void display() {
            System.out.println(real + " + " + imaginary + "i");
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

        System.out.println("\nComplex Number: ");
        complex.display();

        System.out.println("\nAddition:");
        Complex sum = complex.add(1,1);
        sum.display();

        System.out.println("\nSubtraction:");
        Complex difference = complex.sub(3, 5);
        difference.display();

        System.out.println("\nMultiplication:");
        Complex product = complex.mul(2, 9);
        product.display();

        System.out.println("\nDivision:");
        try {
            Complex quotient = complex.div(0, 0);
            quotient.display();
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\nConjugate of Complex Number:");
        Complex conjugate = complex.conjugate();
        conjugate.display();

        System.out.println("\nAre Complex Number 1 and Complex Number 2 equal?");
        System.out.println(complex.compare(complexCompare) ? "Yes" : "No");

        System.out.println("\nSet the real number to 1: ");
        complex.setReal(1);
        complex.display();

        System.out.println("\nSet the imaginary number to 1: ");
        complex.setImaginary(1);
        complex.display();

        System.out.println("\nGet the real number: ");
        System.out.println(complex.getReal());

        System.out.println("\nGet the imaginary number: ");
        System.out.println(complex.getImaginary());
    }
}