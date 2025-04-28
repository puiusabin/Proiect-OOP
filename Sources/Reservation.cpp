#include "../Headers/Reservation.h"

namespace restaurantManagement {

    Reservation::Reservation()
        : customerName_(""), reservationTime_(""), numberOfPeople_(0), tableId_(0) {}

    Reservation::Reservation(const std::string& name,
                             const std::string& time,
                             int numberOfPeople,
                             int tableId)
        : customerName_(name),
          reservationTime_(time),
          numberOfPeople_(numberOfPeople),
          tableId_(tableId) {}

    Reservation::Reservation(const Reservation& other)
        : customerName_(other.customerName_),
          reservationTime_(other.reservationTime_),
          numberOfPeople_(other.numberOfPeople_),
          tableId_(other.tableId_) {}

    Reservation::~Reservation() {}

    int Reservation::getNumberOfPeople() const {
        return numberOfPeople_;
    }

    int Reservation::getTableId() const {
        return tableId_;
    }

    std::string Reservation::getCustomerName() const {
        return customerName_;
    }

    std::string Reservation::getReservationTime() const {
        return reservationTime_;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& r) {
        os << "Reservation: " << r.customerName_
           << " at " << r.reservationTime_
           << " for " << r.numberOfPeople_ << " people, Table "
           << r.tableId_;
        return os;
    }

} // namespace restaurantManagement
