#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"
#include <vector>

namespace restaurantManagement {

    class Observable {
    private:
        std::vector<Observer*> observers_;

    public:
        void addObserver(Observer* obs);
        void notifyObservers(const std::string& message);
    };

} // namespace restaurantManagement

#endif // OBSERVABLE_H
