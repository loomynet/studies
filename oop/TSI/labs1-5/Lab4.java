import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Lab4 {
    // Interface for event handling
    public interface CalculationEventHandler {
        void handle(String message);
    }

    // Dispatcher class 
    public static class Dispatcher {
        private final List<CalculationEventHandler> eventHandlers = new ArrayList<>();

        // Add event handler
        public void addHandler(CalculationEventHandler handler) {
            eventHandlers.add(handler);
        }

        // Remove event handler
        public void removeHandler(CalculationEventHandler handler) {
            if (eventHandlers.contains(handler)) {
                eventHandlers.remove(handler);
                System.out.println("Event handler removed successfully.");
            } else {
                System.out.println("Handler not found in the list.");
            }
        }

        // Notify all handlers
        public void notifyHandlers(String message) {
            for (CalculationEventHandler handler : eventHandlers) {
                handler.handle(message);
            }
        }
    }

    // Superclass Number
    public static abstract class Number {
        public abstract void info();
    }

    public static class Complex extends Number {
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

        // Getters and Setters
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

        // Info
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

        // Constructors
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

        // Info
        @Override
        public void info() {
            System.out.println("This is a quaternion with components: " + real + " + " + i + "i + " + j + "j + " + k + "k");
        }
    }

    // Main method
    public static void main(String[] args) {
        System.out.println("Author: Andrejs Jakunins");
        String timeStamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
        System.out.println("Date and time: " + timeStamp);

        Dispatcher dispatcher = new Dispatcher();

        CalculationEventHandler handler1 = message -> System.out.println("Handler 1: " + message);
        CalculationEventHandler handler2 = message -> System.out.println("Handler 2: " + message);

        dispatcher.addHandler(handler1);
        dispatcher.addHandler(handler2);

        // Complex
        Complex c1 = new Complex(3, 4);
        System.out.println("\nInitial Complex Number 1:");
        c1.display();

        Complex c2 = c1.add(2, 3);
        dispatcher.notifyHandlers("Addition performed on Complex Number 1.");
        c2.display();

        Complex c3 = c1.mul(1, -1);
        dispatcher.notifyHandlers("Multiplication performed on Complex Number 1.");
        c3.display();

        //Quaternion
        Quaternion q1 = new Quaternion(1, 2, 3, 4);
        System.out.println("\nInitial Quaternion 1:");
        q1.display();

        Quaternion q2 = q1.add(2, 3, 4, 5);
        dispatcher.notifyHandlers("Addition performed on Quaternion 1.");
        q2.display();

        Quaternion q3 = q1.multiply(1, 0, 0, 1);
        dispatcher.notifyHandlers("Multiplication performed on Quaternion 1.");
        q3.display();

        dispatcher.removeHandler(handler1);

        Complex c4 = c1.add(1, 1);
        dispatcher.notifyHandlers("Addition performed on Complex Number 1 with only Handler 2 listening.");
        c4.display();
    }
}