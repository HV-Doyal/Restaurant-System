#ifndef ORDER_H
#define ORDER_H

#include <unordered_map>
#include <string>

class Order {
public:
    void addItem(const std::string& item, double price);
    void removeItem(const std::string& item);
    double getTotalPrice() const;

private:
    std::unordered_map<std::string, double> items;
};

#endif