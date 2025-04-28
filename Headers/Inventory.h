#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>

namespace restaurantManagement {

    struct Ingredient {
        std::string name;
        int quantity;
    };

    class Inventory {
    private:
        std::vector<Ingredient> items_;

    public:
        Inventory();
        ~Inventory();

        void addItem(const std::string& ingredient, int quantity);
        bool removeItem(const std::string& ingredient, int quantity);
        void displayInventory() const;

        bool saveToFile(const std::string& filename) const;
        bool loadFromFile(const std::string& filename);
    };

} // namespace restaurantManagement

#endif // INVENTORY_H
