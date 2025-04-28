#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include "Table.h"
#include "Reservation.h"
#include "Order.h"
#include "Inventory.h"

namespace restaurantManagement {

    class Restaurant {
    private:
        std::vector<Table> tables_;
        std::vector<Reservation> reservations_;
        std::vector<Order> orders_;
        Inventory inventory_;

    public:
        Restaurant();
        ~Restaurant();

        void addTable(const Table& table);
        bool addReservation(const Reservation& reservation);
        void addOrder(const Order& order);

        void displayTables() const;
        void displayReservations() const;
        void displayOrders() const;

        Inventory& getInventory();
    };

} // namespace restaurantManagement

#endif // RESTAURANT_H
