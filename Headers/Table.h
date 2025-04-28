#ifndef TABLE_H
#define TABLE_H

#include <iostream>

namespace restaurantManagement {

    class Table {
    private:
        int tableId_;
        int capacity_;
        bool isOccupied_;
        static int tableCount_;          // membru static: numărul total de mese create

    public:
        Table();
        Table(int tableId, int capacity);
        Table(const Table& other);
        ~Table();

        int getTableId() const;
        int getCapacity() const;
        bool getIsOccupied() const;

        void bookTable();
        void freeTable();

        static int getTableCount();      // accesează membrul static

        friend std::ostream& operator<<(std::ostream& os, const Table& table);
    };

} // namespace restaurantManagement

#endif // TABLE_H
