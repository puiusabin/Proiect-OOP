#include "../Headers/Table.h"

namespace restaurantManagement {

    // Inițializare membru static
    int Table::tableCount_ = 0;

    Table::Table()
        : tableId_(++tableCount_), capacity_(0), isOccupied_(false) {}

    Table::Table(int tableId, int capacity)
        : tableId_(tableId), capacity_(capacity), isOccupied_(false) {
        ++tableCount_;
    }

    Table::Table(const Table& other)
        : tableId_(other.tableId_), capacity_(other.capacity_), isOccupied_(other.isOccupied_) {
        ++tableCount_;
    }

    Table::~Table() {
        --tableCount_;
    }

    int Table::getTableId() const {
        return tableId_;
    }

    int Table::getCapacity() const {
        return capacity_;
    }

    bool Table::getIsOccupied() const {
        return isOccupied_;
    }

    void Table::bookTable() {
        isOccupied_ = true;
    }

    void Table::freeTable() {
        isOccupied_ = false;
    }

    int Table::getTableCount() {
        return tableCount_;
    }

    std::ostream& operator<<(std::ostream& os, const Table& table) {
        os << "Table " << table.tableId_
           << " (Capacity: " << table.capacity_ << ") - "
           << (table.isOccupied_ ? "Occupied" : "Available");
        return os;
    }

} // namespace restaurantManagement
