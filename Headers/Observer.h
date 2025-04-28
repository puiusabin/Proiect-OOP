#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

namespace restaurantManagement {

    class Observer {
    public:
        virtual ~Observer() {}
        virtual void update(const std::string& eventMessage) = 0;
    };

} // namespace restaurantManagement

#endif // OBSERVER_H
