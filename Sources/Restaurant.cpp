#include "../Headers/Restaurant.h"
#include <iostream>

namespace restaurantManagement {

    Restaurant::Restaurant() {}
    Restaurant::~Restaurant() {}

    void Restaurant::addTable(const Table& table) {
        tables_.push_back(table);
    }

    bool Restaurant::addReservation(const Reservation& reservation) {
        // Verificăm existența mesei și capacitatea
        for (const auto& table : tables_) {
            if (table.getTableId() == reservation.getTableId()) {
                if (table.getCapacity() < reservation.getNumberOfPeople()) {
                    std::cout << "[Error] Table " << table.getTableId()
                              << " capacity (" << table.getCapacity()
                              << ") is insufficient for "
                              << reservation.getNumberOfPeople() << " people.\n";
                    return false;
                }
                reservations_.push_back(reservation);
                return true;
            }
        }
        std::cout << "[Error] Table ID " << reservation.getTableId() << " not found.\n";
        return false;
    }

    void Restaurant::addOrder(const Order& order) {
        orders_.push_back(order);
    }

    void Restaurant::displayTables() const {
        std::cout << "--- Tables ---\n";
        for (const auto& t : tables_) {
            std::cout << t << "\n";
        }
    }

    void Restaurant::displayReservations() const {
        std::cout << "--- Reservations ---\n";
        for (const auto& r : reservations_) {
            std::cout << r << "\n";
        }
    }

    void Restaurant::displayOrders() const {
        std::cout << "--- Orders ---\n";
        for (const auto& o : orders_) {
            std::cout << o << "\n";
        }
    }

    Inventory& Restaurant::getInventory() {
        return inventory_;
    }

} // namespace restaurantManagement
