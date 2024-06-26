/*  Menu.cpp
    Created: 10/4/2024
    Updated: 20/4/2024
*/

#include "menu.h"

// Implement hash function to calculate index.
int Menu::hashFunction(const std::string& key) const {
    std::hash<std::string> hashFunc;
    return hashFunc(key) % tableSize;
}

// Function to insert menu items to the hash table.
void Menu::insertMenuItem(const std::string& name, 
                          const std::string& ingredients, 
                          const std::string& price) {
    int index = hashFunction(name);
    for (auto& item : table[index]) {
        if (item.name == name) {
            item.ingredients = ingredients;
            item.price = price;
            return; 
        }
    }
    table[index].push_back({name, ingredients, price});
}

// Function to load menu items from a CSV file to the hash table.
void Menu::loadItemsFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        showMenu();
    } else {
        std::cout << "File input successful" << std::endl;
    }

    std::string line, name, ingredients, price;
    while (getline(file, line)) {
        std::stringstream ss(line);
        if (getline(ss, name, ',') && getline(ss, ingredients, ',') 
            && getline(ss, price)) 
        {
            insertMenuItem(name, ingredients, price);
        } 
        else 
        {
            std::cerr << "Failed to parse line: " << line << std::endl;
        }
    }
    file.close();
}

// Constructor to initialize Menu object. 
Menu::Menu(int size) : table(size), tableSize(size) {}

// Function to display menu items stored in the hash table.
void Menu::displayMenuItems() const {
    for (int i = 0; i < tableSize; ++i) {
            if (!table[i].empty()) 
            {
                for (const auto& item : table[i]) {
                    std::cout << "\nItem Key: " << i << "\nItem Name: " 
                              << item.name
                              << "\nIngredients: " << item.ingredients 
                              << "\nPrice: " << item.price << std::endl;
                }
            }
        }
}

// Function to search for menu items by their name or an ingredient.
void Menu::searchMenuItem() {
    std::string filename;

    std::string keyword;
    std::cout << "Enter the item name or ingredients you want "
                << "to search for: ";
    std::cin.ignore();  // Ignore the newline character left in the stream
    std::getline(std::cin, keyword);

    // Turn user input to lowercase for more effective comparison.
    keyword = toLowercase(keyword);
    bool found = false;
    for (int i = 0; i < tableSize; ++i) {
        for (const auto& item : table[i]) {
            // Turn menu item to lowercase for more effective comparison 
            // against user input.
            if (toLowercase(item.name).find(keyword) != std::string::npos || 
                toLowercase(item.ingredients).find(keyword) != 
                            std::string::npos) 
            {
                std::cout << "\nItem Found\nItem Key: " << i 
                        << "\nItem Name: " << item.name
                        << "\nIngredients: " << item.ingredients 
                        << "\nPrice: " << item.price << std::endl;
                found = true;
            }
        }
    }

    if (!found) 
    {
        std::cout << "Item not found in the menu." << std::endl;
    }
}

// Function to get the price of a menu item.
std::string Menu::getPrice(const std::string& keyword) {
    // Turn user input to lowercase for more effective comparison.
    std::string lowercaseKeyword = toLowercase(keyword);
    for (int i = 0; i < tableSize; ++i) {
        for (const auto& item : table[i]) {
            // Turn menu item to lowercase for more effective comparison 
            // against user input.
            if (toLowercase(item.name).find(lowercaseKeyword) != std::string::npos) 
            {
                return item.price; // Return the price if found.
            }
        }
    }
    std::cout << "Item not found in the menu." << std::endl;
    return "0"; 
}

// Function to convert a string to lowercase.
std::string Menu::toLowercase(const std::string& upperString) {
            std::string lowerString = upperString;
        std::transform(lowerString.begin(), lowerString.end(), 
                       lowerString.begin(),
                       [](unsigned char upperCharacter) 
                       { return std::tolower(upperCharacter); });
        return lowerString;
}

// Function to display the menu based on user input of a filename.
void Menu::showMenu() {
        std::string filename;

        std::cout << "Enter the file name you want to open: ";
        std::cin >> filename;

        loadItemsFromCSV(filename);
}

// Function to add new items to a menu.
void Menu::addMenuItems() {
    std::string filename;

    std::cout << "Enter the file name you want to add items to: ";
    std::cin >> filename;

    std::string name, ingredients, price;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter Menu Item: ";
    std::getline(std::cin, name);

    std::cout << "Enter Ingredients: ";
    std::getline(std::cin, ingredients);

    std::cout << "Enter Price: ";
    std::getline(std::cin, price);

    insertMenuItem(name, ingredients, price);
        
    std::ofstream file(filename, std::ios::app);
    for (int i = 0; i < tableSize; ++i) {
        for (const auto& item : table[i]) {
            file << item.name << "," << item.ingredients << "," 
                << item.price << "\n";
        }
    }
    
    file.close();
}

// Function to remove items from a menu.
void Menu::removeMenuItems() {
    std::string filename;

    // Load current menu items.
    std::cout << "Enter the file name you want to remove items from: ";
    std::cin >> filename;
    loadItemsFromCSV(filename);

    // Display current items.
    displayMenuItems();

    int key;
    std::cout << "Enter the item key you want to remove: ";
    std::cin >> key;

    if (key < 0 || key >= tableSize) {
        std::cout << "Invalid key. Key must be between 0 and " 
                  << (tableSize - 1) << "." << std::endl;
        return;
    }

    // Check if there are any items at this key
    if (table[key].empty()) {
        std::cout << "No items found at the given key." << std::endl;
        return;
    }

    // If there's only one item in the list.
    if (table[key].size() == 1) {
        table[key].clear();
        std::cout << "Item removed successfully." << std::endl;
    } else {
        // If more than one item has the same key, ask for item name for 
        // efficient removal.
        std::string nameToRemove;
        std::cout << "Multiple items found at this key. "
                  << "Enter the name of the item to remove: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nameToRemove);

        bool found = false;
        for (auto iter = table[key].begin(); iter != table[key].end(); ++iter) 
        {
            if (iter->name == nameToRemove) 
            {
                table[key].erase(iter);
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Item name not found at the given key." << std::endl;
            return;
        }

        std::cout << "Item removed successfully." << std::endl;
    }

    // Save changes back to the file.
    std::ofstream file(filename, std::ios::trunc); 
    for (const auto& list : table) {
        for (const auto& item : list) {
            file << item.name << "," << item.ingredients << "," << item.price 
                 << "\n";
        }
    }
    file.close();
}

// Function to edit a menu by adding or removing items.
void Menu::editCSVFile() {
    int choice;    

    // Clear the hash before editing.
    for (int i = 0; i < tableSize; ++i) {
        table[i].clear();
    }

    std::cout << "Edit Menu:\n";
    std::cout << "1. Add Menu Items\n";
    std::cout << "2. Remove Menu Items\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        addMenuItems();
    } else if (choice == 2) {
        removeMenuItems();
    } else {
        std::cout << "Invalid choice. Exiting program." << std::endl;
    }
}

bool Menu::isPresent(const std::string& keyword) {
    // Turn user input to lowercase for more effective comparison.
    std::string lowercaseKeyword = toLowercase(keyword);
    for (int i = 0; i < tableSize; ++i) {
        for (const auto& item : table[i]) {
            // Turn menu item to lowercase for more effective comparison 
            // against user input.
            if (toLowercase(item.name).find(lowercaseKeyword) != std::string::npos) 
            {
                return true; // Return true if found.
            }
        }
    }
    return false; // Return false if not found.
}

// Function to load menu items from a CSV file.
void Menu::getloadMenuFromCSV(const std::string& filename) {
    loadItemsFromCSV(filename); 
}