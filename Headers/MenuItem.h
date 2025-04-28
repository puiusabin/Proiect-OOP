#ifndef MENUITEM_H
#define MENUITEM_H

#include "Product.h"
#include <string>
#include <iostream>

namespace restaurantManagement {

    class MenuItem : public Product {
    private:
        std::string name_;
        double price_;

    public:
        MenuItem();
        MenuItem(const std::string& name, double price);
        MenuItem(const MenuItem& other);
        MenuItem& operator=(const MenuItem& other);
        ~MenuItem();

        std::string getDescription() const override;
        double getPrice() const override;

        // Overload operator<< pentru afișare
        friend std::ostream& operator<<(std::ostream& os, const MenuItem& item);
    };

} // namespace restaurantManagement

#endif // MENUITEM_H
