#ifndef MENU_H
#define MENU_H

// Use of standard and OS independant C++ libraries. 
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <cctype>
#include <limits>

class Menu {
private:
    // Structure to store the details of each menu item.
    struct MenuItem {
        std::string name;
        std::string ingredients;
        std::string price;
    };

    // Private methods.
    int hashFunction(const std::string& key) const;
    void insertMenuItem(const std::string& name, const std::string& ingredients,
                        const std::string& price);
    void loadItemsFromCSV(const std::string& filename);

public:
    // Public methods.
    Menu(int size = 101);
    std::vector<std::list<MenuItem>> table;
    int tableSize;
    void displayMenuItems() const;
    void searchMenuItem();
    std::string getPrice(const std::string& keyword);
    static std::string toLowercase(const std::string& upperString);
    void showMenu();
    void addMenuItems();
    void removeMenuItems();
    void editCSVFile();
    void getloadMenuFromCSV(const std::string& filename);
};

#endif