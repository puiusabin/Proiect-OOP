#include "../Headers/TUI.h"
#include "../Headers/MenuItem.h"
#include "../Headers/Reservation.h"
#include "../Headers/Logger.h"
#include <iostream>
#include <limits>
#include <limits>
#include <string>
#include <cstdlib>

namespace restaurantManagement {
    TUI::TUI() {
        // mese exemplu
        restaurant_.addTable(Table(1, 4));
        restaurant_.addTable(Table(2, 2));
        restaurant_.addTable(Table(3, 6));

        // pornim procesor și ne abonăm
        processor_.addObserver(this);
        processor_.start();

        // încărcăm inventar dacă există
        if (restaurant_.getInventory().loadFromFile("inventory.txt")) {
            Logger::getInstance().log("Loaded inventory from file");
        }
    }

    TUI::~TUI() {
        processor_.stop();
        restaurant_.getInventory().saveToFile("inventory.txt");
        Logger::getInstance().log("Saved inventory and exiting");
    }

    // --- Validare HH:MM ---
    static bool isValidTimeFormat(const std::string &t) {
        if (t.size() != 5 || t[2] != ':') return false;
        // Doar numere
        for (int i = 0; i < 5; ++i) {
            if (i == 2) continue;
            if (!std::isdigit(t[i])) return false;
        }
        int hh = std::stoi(t.substr(0, 2));
        int mm = std::stoi(t.substr(3, 2));
        return hh >= 0 && hh < 24 && mm >= 0 && mm < 60;
    }

    void TUI::displayMenu() const {
        std::cout << "\n=== Restaurant TUI ===\n"
                << "1. Show Tables\n"
                << "2. Show Reservations\n"
                << "3. Show Orders\n"
                << "4. Add Reservation\n"
                << "5. Add Order\n"
                << "6. Update Inventory\n"
                << "7. Show Inventory\n"
                << "8. Save Inventory\n"
                << "9. Exit\n"
                << "Choice: ";
    }

    void TUI::handleChoice(int choice) {
        switch (choice) {
            case 1:
                restaurant_.displayTables();
                break;
            case 2:
                restaurant_.displayReservations();
                break;
            case 3:
                restaurant_.displayOrders();
                break;
            case 4: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string name, time;
                int ppl, tid;

                std::cout << "Name: ";
                std::getline(std::cin, name);

                // prompt until valid HH:MM
                do {
                    std::cout << "Time (HH:MM): ";
                    std::getline(std::cin, time);
                    if (!isValidTimeFormat(time)) {
                        std::cout << "[Error] Invalid time. Please use 24-hour format HH:MM.\n";
                    }
                } while (!isValidTimeFormat(time));

                std::cout << "People: ";
                std::cin >> ppl;
                std::cout << "Table ID: ";
                std::cin >> tid;

                Reservation r(name, time, ppl, tid);
                if (restaurant_.addReservation(r))
                    Logger::getInstance().log("Added reservation for " + name + " at " + time);
                else
                    Logger::getInstance().log("Failed reservation for " + name + " at " + time);
                break;
            }
            case 5: {
                int oid, cnt;
                std::cout << "Order ID: ";
                std::cin >> oid;
                Order o(oid);
                std::cout << "Items count: ";
                std::cin >> cnt;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                for (int i = 0; i < cnt; ++i) {
                    std::string n;
                    double p;
                    std::cout << "  Item name: ";
                    std::getline(std::cin, n);
                    std::cout << "  Price: ";
                    std::cin >> p;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    o.addItem(std::make_shared<MenuItem>(n, p));
                }
                restaurant_.addOrder(o);
                processor_.addOrderToQueue(o);
                Logger::getInstance().log("Enqueued Order #" + std::to_string(oid));
                break;
            }
            case 6: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string ing;
                int qty;
                std::cout << "Ingredient: ";
                std::getline(std::cin, ing);
                std::cout << "Quantity: ";
                std::cin >> qty;
                restaurant_.getInventory().addItem(ing, qty);
                Logger::getInstance().log("Inventory += " + ing);
                break;
            }
            case 7:
                restaurant_.getInventory().displayInventory();
                break;
            case 8:
                if (restaurant_.getInventory().saveToFile("inventory.txt"))
                    std::cout << "Saved.\n";
                else
                    std::cout << "Save error.\n";
                break;
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid.\n";
        }
    }

    void TUI::run() {
        int choice = 0;
        do {
            displayMenu();
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                choice = 0;
            }
            if (choice != 9) handleChoice(choice);
        } while (choice != 9);
    }

    void TUI::update(const std::string &eventMessage) {
        std::cout << "\n[Notification] " << eventMessage << "\n";
        Logger::getInstance().log("Notification: " + eventMessage);
    }
} // namespace restaurantManagement
