#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>

namespace restaurantManagement {

    class Logger {
    private:
        std::ofstream logFile_;
        std::mutex mtx_;

        Logger();
        ~Logger();

    public:
        static Logger& getInstance();
        void log(const std::string& message);
    };

} // namespace restaurantManagement

#endif // LOGGER_H
