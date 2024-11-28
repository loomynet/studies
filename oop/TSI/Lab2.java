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

    public class Quaternion {
        private double real;
        private double imaginary;
        private double j;
        private double k;

        public Quaternion(double real, double imaginary, double j, double k) {
            this.real = real;
            this.imaginary = imaginary;
            this.j = j;
            this.k = k;
        }

        public Quaternion(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
            this.j = 0;
            this.k = 0;
        }    

        public Quaternion() {
            this.real = 0;
            this.imaginary = 0;
            this.j = 0;
            this.k = 0;
        }
        
        public Quaternion add(double real, double imaginary, double j, double k) {
            return new Quaternion(this.real + real, this.imaginary + imaginary, this.j + j, this.k + k);
        }
        
    }
    public static void main(String[] args) {
        
    }
}
