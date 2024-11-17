#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

using namespace ::std;

struct Device {
    string name;
    int power;
    float price;
};

vector<Device> devices;
const string filename = "devices.txt";

void saveDevicesToFile() {
    ofstream file(filename, ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Failed to open file for writing.\n";
        return;
    }
    for (const auto& device : devices) {
        file << device.name << ","
            << device.power << ","
            << device.price << "\n";
    }
    file.close();
}

void addDevice() {
    Device newDevice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter device name: ";
    getline(cin, newDevice.name);

    cout << "Enter device power (in watts, no sign): ";
    cin >> newDevice.power;

    cout << "Enter device price (in dollars, no sign): ";
    cin >> newDevice.price;

    devices.push_back(newDevice);
    saveDevicesToFile();
}

void viewDevices() {
    ifstream file(filename, ios::ate); 

    if (file.is_open() && file.tellg() == 0) {
        cout << "There are no devices yet." << endl;
    }
    else {
        file.close(); 
        file.open(filename, ios::in); 

        if (!file.is_open()) {
            cerr << "Failed to open file for reading.\n";
            return;
        }

        devices.clear(); 
        Device tempDevice;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            if (getline(ss, tempDevice.name, ',') && ss >> tempDevice.power && ss.ignore() && ss >> tempDevice.price) {
                devices.push_back(tempDevice);
            }
        }

        if (devices.empty()) {
            cout << "\nThere are no devices yet." << endl;
        }
        else {
            for (const auto& device : devices) {
                cout << "Device Name: " << device.name
                    << ", Power: " << device.power
                    << "W, Price: $" << device.price << endl;
            }
        }
    }
    file.close(); 
}

float calculateAveragePrice(int powerThreshold) {
    float sum = 0.0f;
    int count = 0;
    for (const auto& device : devices) {
        if (device.power > powerThreshold) {
            sum += device.price;
            ++count;
        }
    }
    return count > 0 ? sum / count : 0.0f;
}

void loadDevicesFromFile() {
    devices.clear();
    ifstream file(filename, ios::in);
    if (!file.is_open()) {
        cerr << "Failed to open file for reading.\n";
        return;
    }
    Device tempDevice;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        if (getline(ss, tempDevice.name, ',') && ss >> tempDevice.power && ss.ignore() && ss >> tempDevice.price) {
            devices.push_back(tempDevice);
        }
    }
    file.close();
}

int getMenuChoice() {
    int choice;
    cout << "\nMenu:\n";
    cout << "1. Add Device\n";
    cout << "2. View Devices\n";
    cout << "3. Calculate Average Price\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int studentCode = 84816;
    int taskVarCount = 20;
    cout << "Individual Task Number: " << studentCode % taskVarCount << endl;

    loadDevicesFromFile();

    bool running = true;
    while (running) {
        int choice = getMenuChoice();

        switch (choice) {
        case 1:
            addDevice();
            break;
        case 2:
            viewDevices();
            break;
        case 3: {
            int powerThreshold;
            cout << "Enter power threshold (no sign): ";
            cin >> powerThreshold;
            cout << "Average price: $" << calculateAveragePrice(powerThreshold) << endl;
            break;
        }
        case 4:
            running = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}
