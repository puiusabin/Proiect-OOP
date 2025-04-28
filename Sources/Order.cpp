#include "../Headers/Order.h"

namespace restaurantManagement {

    Order::Order()
        : orderId_(0) {}

    Order::Order(int orderId)
        : orderId_(orderId) {}

    Order::Order(const Order& other)
        : orderId_(other.orderId_), items_(other.items_) {}

    Order::~Order() {}

    int Order::getOrderId() const {
        return orderId_;
    }

    void Order::addItem(const std::shared_ptr<Product>& item) {
        items_.push_back(item);
    }

    double Order::computeTotal() const {
        double total = 0.0;
        for (const auto& item : items_) {
            total += item->getPrice();
        }
        return total;
    }

    Order Order::operator+(const Order& other) const {
        Order result;
        result.orderId_ = this->orderId_ + other.orderId_;
        result.items_ = this->items_;
        result.items_.insert(
            result.items_.end(),
            other.items_.begin(),
            other.items_.end()
        );
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "Order #" << order.orderId_ << " (Total: " << order.computeTotal() << " RON)\n";
        for (const auto& item : order.items_) {
            os << "  - " << item->getDescription()
               << " : " << item->getPrice() << " RON\n";
        }
        return os;
    }

} // namespace restaurantManagement
