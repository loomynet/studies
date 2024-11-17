#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to calculate ln(x) using Taylor series
pair<double, int> calculateLnTaylorSeries(double x, double epsilon) {
    if (x <= 0.0) {
        throw domain_error ("x must be greater than 0");
    }

    int n_terms = 0;
    double term = (x - 1) / (x + 1);
    double ln_value = 2 * term;

    // Add terms until the next term is smaller than epsilon
    while (abs(term) > epsilon) {
        n_terms++;
        term *= (x - 1) / (x + 1) * (2 * n_terms - 1) / (2 * n_terms + 1);
        ln_value += 2 * term;
    }

    return { ln_value, n_terms + 1 }; // +1 to include the first term
}

// Function to create a table of ln(x) values using a while loop
void createLnTable(double xBeg, double xEnd, double dx, double epsilon) {
    // Validate the input
    if (xEnd <= xBeg) {
       cout << "xEnd must be greater than xBeg";
       return;
    }
    if (dx <= 0) {
        cout << "dx must be greater than 0";
        return;
    }

    // Print table header
    cout << setw(10) << "x"
        << " | " << setw(20) << "ln(x) Taylor"
        << " | " << setw(10) << "Terms"
        << " | " << setw(20) << "ln(x) Math" << endl;
    cout << string(64, '-') << endl;

    double x = xBeg;
    while (x <= xEnd) {
        double lnTaylor;
        int termsUsed;
        pair<double, int> result = calculateLnTaylorSeries(x, epsilon);
        lnTaylor = result.first;
        termsUsed = result.second;
        double lnMath = log(x);
        cout << fixed << setprecision(4) << setw(10) << x
            << " | " << setprecision(10) << setw(20) << lnTaylor
            << " | " << setw(10) << termsUsed
            << " | " << setw(20) << lnMath << endl;
        x += dx;
    }
}

int main() {
    double xBeg, xEnd, dx, epsilon;

    // Prompt the user for input values
    cout << "Enter xBeg: ";
    cin >> xBeg;
    cout << "Enter xEnd: ";
    cin >> xEnd;
    cout << "Enter dx: ";
    cin >> dx;
    cout << "Enter epsilon: ";
    cin >> epsilon;

    try {
        createLnTable(xBeg, xEnd, dx, epsilon);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}