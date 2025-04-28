#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

namespace restaurantManagement {

    class Product {
    public:
        virtual ~Product() {}
        virtual std::string getDescription() const = 0;
        virtual double getPrice() const = 0;
    };

} // namespace restaurantManagement

#endif // PRODUCT_H
