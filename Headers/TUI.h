#ifndef TUI_H
#define TUI_H

#include "Restaurant.h"
#include "OrderProcessor.h"
#include "Observer.h"

namespace restaurantManagement {

    class TUI : public Observer {
    private:
        Restaurant restaurant_;
        OrderProcessor processor_;

        void displayMenu() const;
        void handleChoice(int choice);

    public:
        TUI();
        ~TUI();

        void run();
        void update(const std::string& eventMessage) override;
    };

} // namespace restaurantManagement

#endif // TUI_H
