#include <iostream>
#include <string>
#include <cstdlib>
#include <thread> 
#include <chrono>
#include "menu.h"

void takeOrder(Menu& menu)
{
    std::vector<std::string> order;
    std::string input;
    int choice;

    do
    {
        std::cout << "Select an action." << std::endl;
        std::cout << "1. Add Menu Item to order." << std::endl;
        std::cout << "2. Remove Menu Item from order" << std::endl;
        std::cout << "3. View Order" << std::endl;
        std::cout << "4. View Menu" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) 
        {
            std::cin.ignore();
            std::cout << "Enter item to add to order: ";
            std::getline(std::cin, input);
            order.push_back(input);
            std::cout << "Item added successfully" << std::endl;
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
                std::cout << "Item removed successfully" << std::endl;
            } else {
                std::cout << input << " not found." << std::endl;
            }
        } 
        else if (choice == 3)
        {
            std::cout << "-------------CURRENT ORDER-------------" << std::endl;
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
            std::cout << "Exiting" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::system("clear");
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
    } while (choice != 5);
    
}

void takeOrderMenu(Menu& menu)
{
    int choice;
    std::cout << "Take Order Function" << std::endl;

    do {

        std::cout << "Select an action." << std::endl;
        std::cout << "1. View Menu" << std::endl;
        std::cout << "2. Search Menu" << std::endl;
        std::cout << "3. Take Order" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) 
        {
            std::system("clear");
            menu.displayMenuItems();
            std::this_thread::sleep_for(std::chrono::seconds(5));
        } 
        else if (choice == 2) 
        {
            std::system("clear");
            menu.searchMenuItem();
        } 
        else if (choice == 3) 
        {
            std::system("clear");
            takeOrder(menu);
        }
        else if (choice == 4) 
        {
            std::cout << "Exiting" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::system("clear");
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);
}

void fileMenu(Menu& menu) {
    int choice;
    std::cout << "Menu:\n";
    std::cout << "1. Display Menu Items\n";
    std::cout << "2. Search for a Menu Item\n";
    std::cout << "3. Edit Menu\n";
    std::cout << "Enter your choice (1, 2 or 3): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            menu.showMenu();
            menu.displayMenuItems();
            break;
        case 2:
            menu.searchMenuItem();
            break;
        case 3:
            menu.editCSVFile();
            break;
        default:
            std::cout << "Invalid choice. Exiting program." << std::endl;
            break;
    }
}

void inputMenuFromFile(Menu& menu)
{
    std::string input;

    std::cout << "Please Input Menu" << std::endl;
    std::cout << "Enter -1 to stop input" << std::endl;

    do 
    {
        std::cout << "Enter the file name you want to open: ";
        std::cin >> input;

        if (input != "-1") 
        { 
             menu.getloadMenuFromCSV(input);
             //menu.displayMenuItems();
        }
    } while (input != "-1"); 
    std::system("clear");
}

int main() 
{
    Menu menu;
    int choice;

    inputMenuFromFile(menu);

    do {

        std::cout << "Select an action." << std::endl;
        std::cout << "1. Take Order" << std::endl;
        std::cout << "2. Modify Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choice (1, 2, or 3): ";
        std::cin >> choice;

        if (choice == 1) 
        {
            std::system("clear");
            takeOrderMenu(menu);
        } 
        else if (choice == 2) 
        {
            std::system("clear");
            menu.editCSVFile();
        } 
        else if (choice == 3) 
        {
            std::cout << "Exiting" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::system("clear");
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}