import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Lab2 {
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

    public static class Quaternion {
        private double real;
        private double i;
        private double j;
        private double k;

        //Constructors
        public Quaternion(double real, double i, double j, double k) {
            this.real = real;
            this.i = i;
            this.j = j;
            this.k = k;
        }

        public Quaternion(double real, double i) {
            this.real = real;
            this.i = i;
            this.j = 0;
            this.k = 0;
        }    

        public Quaternion() {
            this.real = 0;
            this.i = 0;
            this.j = 0;
            this.k = 0;
        }
        
        // Addition
        public Quaternion add(double real, double i, double j, double k) {
            return new Quaternion(this.real + real, this.i + i, this.j + j, this.k + k);
        }

        public Quaternion add(double real, double i) {
            return new Quaternion(this.real + real, this.i + i, this.j, this.k);
        }

        // Subtraction
        public Quaternion subtract(double real, double i, double j, double k) {
            return new Quaternion(this.real - real, this.i - i, this.j - j, this.k - k);
        }

        // Multiplication
        public Quaternion multiply(double real, double i, double j, double k) {
            double newReal = (this.real * real) - (this.i * i) - (this.j * j) - (this.k * k);
            double newI = (this.real * i) + (this.i * real) + (this.j * k) - (this.k * j);
            double newJ = (this.real * j) - (this.i * k) + (this.j * real) + (this.k * i);
            double newK = (this.real * k) + (this.i * j) - (this.j * i) + (this.k * real);
            return new Quaternion(newReal, newI, newJ, newK);
        }

        //Conjugate of a quaternion
        public Quaternion conjugate() {
            return new Quaternion(this.real, -this.i, -this.j, -this.k);
        }

        // Magnitude squared of a quaternion
        public double norm() {
            return (real * real) + (i * i) + (j * j) + (k * k);
        }

        // Inverse of a quaternion
        public Quaternion inverse() {
            double normSquared = this.norm();
            if (normSquared == 0) {
                throw new ArithmeticException("Cannot invert a quaternion with zero magnitude.");
            }
            Quaternion conjugate = this.conjugate();
            return new Quaternion(conjugate.real / normSquared, conjugate.i / normSquared, conjugate.j / normSquared, conjugate.k / normSquared);
        }

        // Divide
        public Quaternion divide(double real, double i, double j, double k) {
            Quaternion other = new Quaternion(real, i, j, k);
            Quaternion inverseOther = other.inverse();
            return this.multiply(inverseOther.real, inverseOther.i, inverseOther.j, inverseOther.k);
        }

        // Normalization
        public Quaternion normalize() {
            double magnitude = Math.sqrt(this.norm());
            if (magnitude == 0) {
                throw new ArithmeticException("Cannot normalize a quaternion with zero magnitude.");
            }
            return new Quaternion(this.real / magnitude, this.i / magnitude, this.j / magnitude, this.k / magnitude);
        }

        // Display the quaternion
        public void display() {
            System.out.printf("%.2f + %.2fi + %.2fj + %.2fk%n", real, i, j, k);
        }

        // Getters and Setters
        public double getReal() {
            return real;
        }

        public double getI() {
            return i;
        }

        public double getJ() {
            return j;
        }

        public double getK() {
            return k;
        }

        public void setReal(double real) {
            this.real = real;
        }

        public void setI(double i) {
            this.i = i;
        }

        public void setJ(double j) {
            this.j = j;
        }

        public void setK(double k) {
            this.k = k;
        }
    }
        // Main 
        public static void main(String[] args) {
            System.out.println("Author: Andrejs Jakunins");
            String timeStamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
            System.out.println("Date and time: " + timeStamp);

            Quaternion q1 = new Quaternion(1, 2, 3, 4);

            System.out.println("\nQuaternion 1:");
            q1.display();

            System.out.println("\nAddition (q1 + (5 + 6i + 7j + 8k)):");
            Quaternion sum = q1.add(5, 6, 7, 8);
            sum.display();

            System.out.println("\nAddition (q1 + (4 + 3i)):");
            Quaternion sumTwo = q1.add(4, 3);
            sumTwo.display();

            System.out.println("\nSubtraction (q1 - (5 - 6i - 7j - 8k)):");
            Quaternion difference = q1.subtract(5, 6, 7, 8);
            difference.display();

            System.out.println("\nMultiplication (q1 * (5 + 6i + 7j + 8k)):");
            Quaternion product = q1.multiply(5, 6, 7, 8);
            product.display();

            System.out.println("\nDivision (q1 / (5 + 6i + 7j + 8k)):");
            try {
                Quaternion quotient = q1.divide(5, 6, 7, 8);
                quotient.display();
            } catch (ArithmeticException e) {
                System.out.println(e.getMessage());
            }

            System.out.println("\nNormalization of Quaternion 1:");
            try {
                Quaternion normalized = q1.normalize();
                normalized.display();
            } catch (ArithmeticException e) {
                System.out.println(e.getMessage());
            }
        }
}