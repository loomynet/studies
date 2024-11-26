public class Lab1 {

    public static class Complex {
        private double real;
        private double imaginary;

        //Constructor
        public Complex(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        // Addition
        public Complex Add(Complex other) {
            return new Complex(this.real + other.real, this.imaginary + other.imaginary);
        }

        // Subtraction
        public Complex Sub(Complex other) {
            return new Complex(this.real - other.real, this.imaginary - other.imaginary);
        }

        // Multiplication
        public Complex Mul(Complex other) {
            double realPart = (this.real * other.real) - (this.imaginary * other.imaginary);
            double imaginaryPart = (this.real * other.imaginary) + (this.imaginary * other.real);
            return new Complex(realPart, imaginaryPart);
        }

        // Division
        public Complex Div(Complex other) throws ArithmeticException {
            double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
            if (denominator == 0) {
                throw new ArithmeticException("Cannot divide by a complex number with zero magnitude.");
            }

            double realPart = (this.real * other.real + this.imaginary * other.imaginary) / denominator;
            double imaginaryPart = (this.imaginary * other.real - this.real * other.imaginary) / denominator;
            return new Complex(realPart, imaginaryPart);
        }

        // Comparison
        public boolean Equals(Complex other) {
            return (this.real == other.real) && (this.imaginary == other.imaginary);
        }

        // Conjugate
        public Complex Conjugate() {
            return new Complex(this.real, -this.imaginary);
        }

        // Display method
        public void Display() {
            System.out.println(real + " + " + imaginary + "i");
        }

    }
    public static void main(String[] args) {
        Complex c1 = new Complex(3, 4);
        Complex c2 = new Complex(1, 2);

        System.out.println("Complex Number 1:");
        c1.Display();
        System.out.println("Complex Number 2:");
        c2.Display();

        System.out.println("\nAddition:");
        Complex sum = c1.Add(c2);
        sum.Display();

        System.out.println("\nSubtraction:");
        Complex difference = c1.Sub(c2);
        difference.Display();

        System.out.println("\nMultiplication:");
        Complex product = c1.Mul(c2);
        product.Display();

        System.out.println("\nDivision:");
        try {
            Complex quotient = c1.Div(c2);
            quotient.Display();
        }
        catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\nConjugate of Complex Number 1:");
        Complex conjugate = c1.Conjugate();
        conjugate.Display();

        System.out.println("\nAre Complex Number 1 and Complex Number 2 equal?");
        System.out.println(c1.Equals(c2) ? "Yes" : "No");
    }
}
