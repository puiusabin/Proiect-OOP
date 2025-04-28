#include "../Headers/MenuItem.h"

namespace restaurantManagement {

    MenuItem::MenuItem()
        : name_("Unknown"), price_(0.0) {}

    MenuItem::MenuItem(const std::string& name, double price)
        : name_(name), price_(price) {}

    MenuItem::MenuItem(const MenuItem& other)
        : name_(other.name_), price_(other.price_) {}

    MenuItem& MenuItem::operator=(const MenuItem& other) {
        if (this != &other) {
            name_ = other.name_;
            price_ = other.price_;
        }
        return *this;
    }

    MenuItem::~MenuItem() {}

    std::string MenuItem::getDescription() const {
        return name_;
    }

    double MenuItem::getPrice() const {
        return price_;
    }

    std::ostream& operator<<(std::ostream& os, const MenuItem& item) {
        os << item.name_ << " - " << item.price_ << " RON";
        return os;
    }

} // namespace restaurantManagement
