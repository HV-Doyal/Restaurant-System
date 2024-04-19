#ifndef MENU_H
#define MENU_H

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
    struct MenuItem {
        std::string name;
        std::string ingredients;
        std::string price;
    };

    std::vector<std::list<MenuItem>> table;
    int tableSize;

    int hashFunction(const std::string& key) const;
    void insertMenuItem(const std::string& name, const std::string& ingredients,
                        const std::string& price);
    void loadItemsFromCSV(const std::string& filename);

public:
    Menu(int size = 101);
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