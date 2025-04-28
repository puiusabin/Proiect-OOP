#include "../Headers/Observable.h"

namespace restaurantManagement {

    void Observable::addObserver(Observer* obs) {
        observers_.push_back(obs);
    }

    void Observable::notifyObservers(const std::string& message) {
        for (auto* obs : observers_) {
            obs->update(message);
        }
    }

} // namespace restaurantManagement
