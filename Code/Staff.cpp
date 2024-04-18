#include "Staff.h"
#include <iostream>

void Staff::displayMenu() {
    int choice;
    do {
        std::cout << "Welcome! Please select an option:\n";
        std::cout << "1. Take Order\n";
        std::cout << "2. Edit Menu\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                takeOrder();
                break;
            case 2:
                editMenu();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void Staff::takeOrder() {
    // Placeholder for take order logic
    std::cout << "Taking order...\n";
}

void Staff::editMenu() {
    // Placeholder for edit menu logic
    std::cout << "Editing menu...\n";
}