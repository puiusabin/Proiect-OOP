#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>

namespace restaurantManagement {

    class Reservation {
    private:
        std::string customerName_;
        std::string reservationTime_;
        int numberOfPeople_;
        int tableId_;

    public:
        Reservation();
        Reservation(const std::string& name,
                    const std::string& time,
                    int numberOfPeople,
                    int tableId);
        Reservation(const Reservation& other);
        ~Reservation();

        int getNumberOfPeople() const;
        int getTableId() const;
        std::string getCustomerName() const;
        std::string getReservationTime() const;

        friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
    };

} // namespace restaurantManagement

#endif // RESERVATION_H
