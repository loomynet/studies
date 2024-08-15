#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n, m, fillingMethod, minRange, maxRange;
    std::cout << "Enter the dimensions of the array (n m): ";
    std::cin >> n >> m;

    // Dynamic allocation of the array
    int** array = new int* [n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];
    }

    // Menu for filling the array
    std::cout << "Select the method of filling the array:\n";
    std::cout << "1. Manual\n";
    std::cout << "2. Automatic\n";
    std::cin >> fillingMethod;

    // Filling the array
    switch (fillingMethod) {
    case 1: // Manual
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << "Enter element [" << i << "][" << j << "]: ";
                std::cin >> array[i][j];
            }
        }
        break;
    case 2: // Automatic
        std::cout << "Enter the range for random numbers (min max): ";
        std::cin >> minRange >> maxRange;
        std::srand(std::time(nullptr)); // Seed for random number generation
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                array[i][j] = minRange + std::rand() % (maxRange - minRange + 1);
            }
        }
        break;
    }

    // Calculating the product of elements in rows with no positive elements
    long long product = 1;
    bool allNonPositive;
    for (int i = 0; i < n; ++i) {
        allNonPositive = true;
        long long rowProduct = 1;
        for (int j = 0; j < m; ++j) {
            if (array[i][j] > 0) {
                allNonPositive = false;
                break;
            }
            rowProduct *= array[i][j];
        }
        if (allNonPositive) {
            product *= rowProduct;
        }
    }

    // Displaying the result
    std::cout << "The product of elements in rows with no positive elements is: " << product << std::endl;

    // Deallocating the array
    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}


/*

For test cases, here are three examples :

1. Manual Filling :
    Input: n = 2, m = 3, array = [[-1, -2, -3], [4, 5, 6]]
    Output : The product is - 6 (only the first row has no positive elements)

2. Automatic Filling(Assuming random range is - 10 to 10) :
    Input : n = 3, m = 2 (randomly filled)
    Output : The product will vary depending on the random values, but the result should be the product of rows without positive numbers.
    
3. Mixed Cases :
    Input: n = 4, m = 2, array = [[-5, -5], [2, -3], [-4, -4], [7, -2]]
    Output : The product is 400 (only the first and third rows are considered) 
    
*/