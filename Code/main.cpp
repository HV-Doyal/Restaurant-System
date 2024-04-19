#include <iostream>
#include <string>
#include "menu.h"

void takeOrder()
{
    std::cout << "Take Order Function" << std::endl;
}

void editMenu()
{
    std::cout << "Edit Menu Function" << std::endl;
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
             menu.displayMenuItems();
        }
    } while (input != "-1"); 
}

int main() 
{
    Menu menu;
    inputMenuFromFile(menu);
    menu.searchMenuItem();
    //fileMenu(menu);
    return 0;
}