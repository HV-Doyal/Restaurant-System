#include "Order.h"

void Order::addItem(const std::string& item, double price) {
    items[item] = price;
}

void Order::removeItem(const std::string& item) {
    items.erase(item);
}

double Order::getTotalPrice() const {
    double total = 0.0;
    for (const auto& pair : items) {
        total += pair.second;
    }
    return total;
}