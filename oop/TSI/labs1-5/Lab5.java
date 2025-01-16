import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Lab5 {

    public static class ComplexNumberException extends Exception {
        public ComplexNumberException(String message) {
            super(message);
        }
    }

    public static class QuaternionException extends Exception {
        public QuaternionException(String message) {
            super(message);
        }
    }

    public static abstract class Number {
        public abstract void info();
    }

    public static class Complex extends Number {
        private double real;
        private double imaginary;

        public Complex(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        public Complex div(double real, double imaginary) throws ComplexNumberException {
            double denominator = (real * real) + (imaginary * imaginary);
            if (denominator == 0) {
                throw new ComplexNumberException("Cannot divide by a complex number with zero magnitude.");
            }

            double realPart = (this.real * real + this.imaginary * imaginary) / denominator;
            double imaginaryPart = (this.imaginary * real - this.real * imaginary) / denominator;
            return new Complex(realPart, imaginaryPart);
        }

        public void display() {
            System.out.println(String.format("%.2f + %.2fi", real, imaginary));
        }

        @Override
        public void info() {
            System.out.println("This is a complex number with real part " + real + " and imaginary part " + imaginary);
        }
    }

    public static class Quaternion extends Number {
        private double real;
        private double i;
        private double j;
        private double k;

        public Quaternion(double real, double i, double j, double k) {
            this.real = real;
            this.i = i;
            this.j = j;
            this.k = k;
        }

        public Quaternion normalize() throws QuaternionException {
            double magnitude = Math.sqrt((real * real) + (i * i) + (j * j) + (k * k));
            if (magnitude == 0) {
                throw new QuaternionException("Cannot normalize a quaternion with zero magnitude.");
            }
            return new Quaternion(real / magnitude, i / magnitude, j / magnitude, k / magnitude);
        }

        public void display() {
            System.out.printf("%.2f + %.2fi + %.2fj + %.2fk%n", real, i, j, k);
        }

        @Override
        public void info() {
            System.out.println("This is a quaternion with components: " + real + " + " + i + "i + " + j + "j + " + k + "k");
        }
    }

    public static void main(String[] args) {
        System.out.println("Author: Andrejs Jakunins");
        String timeStamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
        System.out.println("Date and time: " + timeStamp);

        Complex c1 = new Complex(3, 4);
        System.out.println("\nComplex Number 1:");
        c1.display();
        c1.info();

        Quaternion q1 = new Quaternion(1, 2, 3, 4);
        System.out.println("\nQuaternion 1:");
        q1.display();
        q1.info();

        try {
            System.out.println("\nAttempting to divide Complex Number 1 by 0...");
            Complex result = c1.div(0, 0); 
            result.display();
        } catch (ComplexNumberException e) {
            System.out.println("Caught ComplexNumberException: " + e.getMessage());
        } finally {
            System.out.println("Complex number division attempt completed.");
        }

        try {
            System.out.println("\nAttempting to normalize Quaternion 1 with zero magnitude...");
            Quaternion qZero = new Quaternion(0, 0, 0, 0);
            Quaternion normalized = qZero.normalize();
            normalized.display();
        } catch (QuaternionException e) {
            System.out.println("Caught QuaternionException: " + e.getMessage());
        } finally {
            System.out.println("Quaternion normalization attempt completed.");
        }

        try {
            System.out.println("\nAttempting to divide by zero...");
            int result = 10 / 0;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Caught ArithmeticException: Division by zero is not allowed.");
        } catch (Exception e) {
            System.out.println("Caught General Exception: " + e.getMessage());
        } finally {
            System.out.println("Division by zero attempt completed.");
        }

        System.out.println("\nException handling completed.");
    }
}