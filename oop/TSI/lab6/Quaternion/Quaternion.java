package quaternion;
public class Quaternion {
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

    public Quaternion add(double real, double i, double j, double k) {
        return new Quaternion(this.real + real, this.i + i, this.j + j, this.k + k);
    }

    public Quaternion subtract(double real, double i, double j, double k) {
        return new Quaternion(this.real - real, this.i - i, this.j - j, this.k - k);
    }

    public Quaternion multiply(double real, double i, double j, double k) {
        double newReal = (this.real * real) - (this.i * i) - (this.j * j) - (this.k * k);
        double newI = (this.real * i) + (this.i * real) + (this.j * k) - (this.k * j);
        double newJ = (this.real * j) - (this.i * k) + (this.j * real) + (this.k * i);
        double newK = (this.real * k) + (this.i * j) - (this.j * i) + (this.k * real);
        return new Quaternion(newReal, newI, newJ, newK);
    }

    public Quaternion divide(double real, double i, double j, double k) {
        Quaternion other = new Quaternion(real, i, j, k);
        Quaternion inverseOther = other.inverse();
        return this.multiply(inverseOther.getReal(), inverseOther.getI(), inverseOther.getJ(), inverseOther.getK());
    }

    public Quaternion inverse() {
        double normSquared = (real * real) + (i * i) + (j * j) + (k * k);
        if (normSquared == 0) {
            throw new ArithmeticException("Cannot invert a quaternion with zero magnitude.");
        }
        return new Quaternion(real / normSquared, -i / normSquared, -j / normSquared, -k / normSquared);
    }

    @Override
    public String toString() {
        return String.format("%.2f + %.2fi + %.2fj + %.2fk", real, i, j, k);
    }
}