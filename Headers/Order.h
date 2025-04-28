#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <memory>
#include <iostream>
#include "Product.h"

namespace restaurantManagement {

    class Order {
    private:
        int orderId_;
        std::vector<std::shared_ptr<Product>> items_;

    public:
        Order();
        Order(int orderId);
        Order(const Order& other);
        ~Order();

        int getOrderId() const;
        void addItem(const std::shared_ptr<Product>& item);
        double computeTotal() const;

        // Supraincarcare operator+
        Order operator+(const Order& other) const;

        // Supraincarcare operator<< pentru afișare
        friend std::ostream& operator<<(std::ostream& os, const Order& order);
    };

} // namespace restaurantManagement

#endif // ORDER_H
