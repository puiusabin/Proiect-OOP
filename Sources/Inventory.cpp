#include "../Headers/Inventory.h"
#include <fstream>
#include <algorithm>

namespace restaurantManagement {

    Inventory::Inventory() {}
    Inventory::~Inventory() {}

    void Inventory::addItem(const std::string& ingredient, int quantity) {
        for (auto& ing : items_) {
            if (ing.name == ingredient) {
                ing.quantity += quantity;
                return;
            }
        }
        items_.push_back({ingredient, quantity});
    }

    bool Inventory::removeItem(const std::string& ingredient, int quantity) {
        for (auto& ing : items_) {
            if (ing.name == ingredient && ing.quantity >= quantity) {
                ing.quantity -= quantity;
                return true;
            }
        }
        return false;
    }

    void Inventory::displayInventory() const {
        std::cout << "Inventory:\n";
        for (const auto& ing : items_) {
            std::cout << " - " << ing.name << ": " << ing.quantity << "\n";
        }
    }

    bool Inventory::saveToFile(const std::string& filename) const {
        std::ofstream out(filename.c_str());
        if (!out.is_open()) return false;
        for (const auto& ing : items_) {
            out << ing.name << " " << ing.quantity << "\n";
        }
        return true;
    }

    bool Inventory::loadFromFile(const std::string& filename) {
        std::ifstream in(filename.c_str());
        if (!in.is_open()) return false;
        items_.clear();
        std::string name;
        int qty;
        while (in >> name >> qty) {
            items_.push_back({name, qty});
        }
        return true;
    }

} // namespace restaurantManagement
