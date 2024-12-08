#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <chrono>

std::queue<int> readDataFromFile(std::string filename) {
    std::queue<int> dataQueue;
    std::ifstream file(filename);
    int value;

    if (file.is_open()) {
        while (file >> value) {
            dataQueue.push(value);
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }

    return dataQueue;
}

void displayQueue(std::queue<int> dataQueue) {
    std::cout << "Contents of the queue:" << std::endl;
    while (!dataQueue.empty()) {
        std::cout << dataQueue.front() << std::endl;
        dataQueue.pop();
    }
}

bool searchQueue(std::queue<int> dataQueue, int key) {
    while (!dataQueue.empty()) {
        if (dataQueue.front() == key) {
            return true;
        }
        dataQueue.pop();
    }
    return false;
}

void addElementToEnd(std::queue<int>& dataQueue, int element) {
    dataQueue.push(element);
    std::cout << "Element " << element << " added to the end of the queue." << std::endl;
}

void addElementToBeginning(std::queue<int>& dataQueue, int element) {
    std::queue<int> tempQueue;
    tempQueue.push(element);
    while (!dataQueue.empty()) {
        tempQueue.push(dataQueue.front());
        dataQueue.pop();
    }
    std::cout << "Element " << element << " added to the beginning of the queue." << std::endl;
    dataQueue = tempQueue;
}

void addElementAfter(std::queue<int>& dataQueue, int target, int element) {
    std::queue<int> tempQueue;
    bool added = false;
    while (!dataQueue.empty()) {
        tempQueue.push(dataQueue.front());
        if (dataQueue.front() == target && !added) {
            tempQueue.push(element);
            added = true;
        }
        dataQueue.pop();
    }
    std::cout << "Trying to add element " << element << " after " << target << "." << std::endl;
    if (!added) {
        std::cerr << "Error: target element " << target << " not found." << std::endl;
    } else {
        std::cout << "Element added successfully." << std::endl;
    }
    dataQueue = tempQueue;
}

void deleteElement(std::queue<int>& dataQueue, int target) {
    std::queue<int> tempQueue;
    bool found = false;
    while (!dataQueue.empty()) {
        if (dataQueue.front() == target) {
            found = true;
        } else {
            tempQueue.push(dataQueue.front());
        }
        dataQueue.pop();
    }
    std::cout << "Trying to delete element " << target << "." << std::endl;
    if (!found) {
        std::cerr << "Error: target element " << target << " not found." << std::endl;
    } else {
        std::cout << "Element deleted successfully." << std::endl;
    }
    dataQueue = tempQueue;
}

void benchmark(std::queue<int> dataQueue, const std::string& operation, int key = 0) {
    auto start = std::chrono::high_resolution_clock::now();

    if (operation == "search") {
        searchQueue(dataQueue, key);
    } else if (operation == "display") {
        displayQueue(dataQueue);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken for " << operation << ": " << elapsed.count() << " seconds" << std::endl;
}

int main() {
    

    // initial data from lms wirh unknown symbols
    
    /*
    std::ifstream f ("initial.data");

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }
    
    std::string s;

    while (getline(f, s)){
        std::cout << s << std::endl;
    }
    f.close();
    */

    // the same data but without unknown symbols
    const std::string filename = "data/clients.data";
    std::queue<int> dataQueue = readDataFromFile(filename);

    if (dataQueue.empty()) {
        std::cerr << "Queue is empty. Exiting program." << std::endl;
        return 1;
    }

    int key = 123; 
    std::cout << "Searching for: " << key << std::endl;
    std::cout << (searchQueue(dataQueue, key) ? "Found" : "Not Found") << std::endl;

    addElementToEnd(dataQueue, 100);

    addElementToBeginning(dataQueue, 200);

    addElementAfter(dataQueue, 544, 300);

    deleteElement(dataQueue, 140);

    benchmark(dataQueue, "display");

    return 0;
}