#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>   // For abs()

using namespace std;

void fillArrayManually(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

void fillArrayAutomatically(double* arr, int size, double minRange, double maxRange) {
    for (int i = 0; i < size; i++) {
        arr[i] = minRange + (double)rand() / RAND_MAX * (maxRange - minRange);
    }
}

int countNegativeElements(double* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) count++;
    }
    return count;
}

double sumAfterAbsoluteMin(double* arr, int size) {
    int minIndex = 0;
    double minVal = abs(arr[0]);
    double sum = 0;

    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < minVal) {
            minVal = abs(arr[i]);
            minIndex = i;
        }
    }

    for (int i = minIndex + 1; i < size; i++) {
        sum += abs(arr[i]);
    }

    return sum;
}

void replaceAndSort(double* arr, int size) {
    // Replace negatives with squares
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) arr[i] = arr[i] * arr[i];
    }

    // Sort array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    double* arr = new double[size]; // Dynamic array allocation

    cout << "Select array filling method (1 for manual, 2 for automatic): ";
    int method;
    cin >> method;

    if (method == 1) {
        fillArrayManually(arr, size);
    }
    else {
        double minRange, maxRange;
        cout << "Enter the minimum and maximum range for automatic filling: ";
        cin >> minRange >> maxRange;
        fillArrayAutomatically(arr, size, minRange, maxRange);
    }

    cout << "Original Array: ";
    printArray(arr, size);

    // Task 1
    int negativeCount = countNegativeElements(arr, size);
    cout << "Number of negative elements: " << negativeCount << endl;

    // Task 2
    double sum = sumAfterAbsoluteMin(arr, size);
    cout << "Sum after absolute minimum element: " << sum << endl;

    // Task 3
    replaceAndSort(arr, size);
    cout << "Array after replacing negatives and sorting: ";
    printArray(arr, size);

    delete[] arr; // Freeing the allocated memory

    return 0;
}
