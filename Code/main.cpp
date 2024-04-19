#include <iostream>
#include <string>
#include <cstdlib>
#include "menu.h"

void takeOrder()
{
    std::cout << "Take Order Function" << std::endl;
}

void editMenu(Menu& menu)
{
    std::cout << "Edit Menu Function" << std::endl;
    menu.editCSVFile();
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

    int choice;
    std::cout << "Select an action." << std::endl;
    std::cout << "1.Take Order" << std::endl;
    std::cout << "2.Modify Menu" << std::endl;
    std::cout << "3.Exit" << std::endl;
    std::cout << "Choice(1,2 or 3): ";
    std::cin >> choice;

    if (choice == 1)
    {
        takeOrder();
    }
    else if (choice == 2)
    {
        editMenu(menu);
        main();
    }
    else if (choice == 3)
    {
        std::cout << "Exiting" << std::endl;
        exit(0);
    }

    //menu.searchMenuItem();
    //fileMenu(menu);
    
    return 0;
}
