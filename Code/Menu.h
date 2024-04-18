#ifndef MENU_H
#define MENU_H

#include <unordered_map>
#include <string>

class Menu {
public:
    void editMenu();

private:
    std::unordered_map<std::string, double> items;
    // Add additional data structures or methods as needed for menu editing
};

#endif