// Use of standard and OS independant C++ libraries.
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread> 
#include <chrono>
#include <iomanip>
#include "menu.h"

// Function to take orders.
void takeOrder(Menu& menu)
{
    std::vector<std::string> order;
    std::string input, item;
    int choice;
    bool found;
    double price, total;
    total = 0.00;

    do {
        // Display options to the user.
        std::cout << "\n----------Order Menu----------\n" << std::endl;
        std::cout << "1. Add Menu Item to order." << std::endl;
        std::cout << "2. Remove Menu Item from order" << std::endl;
        std::cout << "3. View Order" << std::endl;
        std::cout << "4. View Menu" << std::endl;
        std::cout << "5. Calculate bill and end order" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "\nEnter your choice (1-6): ";

        // Validate user input
        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cin.clear();  // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid choice. Please enter a number between 1 and 6: ";
        }

        if (choice == 1) 
        {
            std::cin.ignore();
            found = false;
            while (!found) {
                std::cout << "Enter item to add to order: ";
                std::getline(std::cin, input);
                if (menu.isPresent(input)) {
                    order.push_back(input);
                    std::cout << "Item added successfully." << std::endl;
                    found = true;
                } else {
                    std::cout << "Item not found." << std::endl;
                }
            }         
        } 
        else if (choice == 2) 
        {
            std::cin.ignore();
            std::cout << "Enter item to remove from order: ";
            std::getline(std::cin, input);
            std::vector<std::string>::iterator it = std::find(order.begin(), 
                                                              order.end(), 
                                                              input);
            if (it != order.end()) {
                std::cout << input << " found at index " 
                          << std::distance(order.begin(), it) 
                          << std::endl;
                // Removing the string
                order.erase(it);
                std::cout << "Item removed successfully." << std::endl;
            } else {
                std::cout << input << " not found." << std::endl;
            }
        } 
        else if (choice == 3)
        {
            std::cout << "\n-------------CURRENT ORDER-------------" << std::endl;
            for (size_t i = 0; i < order.size(); ++i) 
            {
                std::cout << order[i] << std::endl;
            }
            std::cout << "---------------------------------------" << std::endl;
        }
        else if (choice == 4)
        {
            std::cout << "---------------------------------------" << std::endl;
            menu.displayMenuItems();
            std::cout << "---------------------------------------" << std::endl;
        }
        else if (choice == 5)
        {
            for (const std::string& item : order) {
            price = std::stod(menu.getPrice(item));
            total = total + price;
        }
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Price is " << total << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "\nExiting..." << std::endl;
        std::cout << "Come back soon!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::system("clear");
        exit(0);
        }
        else if (choice == 6)
        {
            std::cout << "\nExiting..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::system("clear");
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
    } while (choice != 6);
    
}

// Function to display take order options to user.
void takeOrderMenu(Menu& menu)
{
    int choice;

    do {
        std::cout << "\n--------Order Managing Menu--------\n" << std::endl;
        std::cout << "1. View Menu" << std::endl;
        std::cout << "2. Search Menu" << std::endl;
        std::cout << "3. Take Order" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "\nEnter your choice (1-4): ";

        // Validate user input
        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cin.clear();  // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
        }

        if (choice == 1) {
            std::system("clear");
            menu.displayMenuItems();
            std::this_thread::sleep_for(std::chrono::seconds(5));
        } else if (choice == 2) {
            std::system("clear");
            menu.searchMenuItem();
        } else if (choice == 3) {
            std::system("clear");
            takeOrder(menu);
        } else if (choice == 4) {
            std::cout << "\nExiting..." << std::endl;
            std::cout << "Come back soon!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::system("clear");
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);
}

// Function to display modify options to user.
void fileMenu(Menu& menu) {
    int choice;
    std::cout << "\n----------Modification Menu----------\n";
    std::cout << "1. Display Menu Items\n";
    std::cout << "2. Search for a Menu Item\n";
    std::cout << "3. Edit Menu\n";
    std::cout << "\nEnter your choice (1-3): ";

    // Validate user input
    while (!(std::cin >> choice) || choice < 1 || choice > 6) {
        std::cin.clear();  // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid choice. Please enter a number between 1 and 3: ";
    }

    do {
        if (choice == 1) {
            menu.showMenu();
            menu.displayMenuItems();
        } else if (choice == 2) {
            menu.searchMenuItem();
        } else if (choice == 3) {
            menu.editCSVFile();
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);
}

// Function to ask user for CSV file input.
void inputMenuFromFile(Menu& menu)
{
    std::string input;

    std::cout << "Please Input Menus." << std::endl;
    std::cout << "Enter -1 to stop input." << std::endl;

    do 
    {
        std::cout << "\nEnter the file name you want to open: ";
        std::cin >> input;

        if (input != "-1") { 
            menu.getloadMenuFromCSV(input);
        }

    } while (input != "-1"); 
    std::system("clear");
}

int main() 
{
    Menu menu;
    int choice;

    std::cout << "\n------WELCOME TO BITES AND WONDERS-----\n" << std::endl;        

    inputMenuFromFile(menu);

    // Main menu.
    std::cout << "\n----------Main Menu----------\n" << std::endl;
    std::cout << "1. Take Order" << std::endl;
    std::cout << "2. Modify Menu" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
    std::cout << "\nEnter your choice (1-3): ";

    // Validate user input
    while (!(std::cin >> choice) || choice < 1 || choice > 6) {
        std::cin.clear();  // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid choice. Please enter a number between 1 and 3: ";
    }

    if (choice == 1) {
        std::system("clear");
        takeOrderMenu(menu);
    } else if (choice == 2) {
        std::system("clear");
        menu.editCSVFile();
    } else if (choice == 3) {
        std::cout << "\nExiting..." << std::endl;
        std::cout << "Come back soon!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::system("clear");
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
    return 0;
}