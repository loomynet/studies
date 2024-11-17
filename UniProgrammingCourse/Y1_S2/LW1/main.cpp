#include <iostream>
#include <vector>
#include <string>

// Shop structure
struct Shop {
    std::string title;
    std::string address;
    std::string telNumber;
};

// Function to add shop data to the array
void addShopData(std::vector<Shop>& shops) {
    Shop shop;
    std::cout << "Enter shop title: ";
    std::getline(std::cin, shop.title);
    std::cout << "Enter address: ";
    std::getline(std::cin, shop.address);
    std::cout << "Enter telephone number: ";
    std::getline(std::cin, shop.telNumber);
    shops.push_back(shop);
}

// Function to print all shops
void printShops(const std::vector<Shop>& shops) {
    for (const auto& shop : shops) {
        std::cout << "Title: " << shop.title << ", Address: " << shop.address << ", Tel. Number: " << shop.telNumber << std::endl;
    }
}

// Function to find a telephone number by address
std::string findTelNumberByAddress(const std::vector<Shop>& shops, const std::string& address) {
    for (const auto& shop : shops) {
        if (shop.address == address) {
            return shop.telNumber;
        }
    }
    return "Not found.";
}

int main() {
    const int studentCode = 84816;
    const int taskVarCount = 20;
    std::cout << "Individual task number: " << studentCode % taskVarCount << std::endl;

    std::vector<Shop> shops;
    int choice;
    std::string address;

    do {
        std::cout << "1. Add shop data\n2. Print all shops\n3. Find telephone number by address\n0. Exit\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            addShopData(shops);
            break;
        case 2:
            printShops(shops);
            break;
        case 3:
            std::cout << "Enter address to find the telephone number: ";
            std::getline(std::cin, address);
            std::cout << "Telephone number: " << findTelNumberByAddress(shops, address) << std::endl;
            break;
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
