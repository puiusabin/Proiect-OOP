#include "../Headers/Logger.h"
#include <iostream>

namespace restaurantManagement {

    Logger::Logger() {
        logFile_.open("restaurant.log", std::ios::app);
        if (!logFile_) {
            std::cerr << "[Logger] Failed to open log file.\n";
        }
    }

    Logger::~Logger() {
        if (logFile_.is_open()) logFile_.close();
    }

    Logger& Logger::getInstance() {
        static Logger instance;
        return instance;
    }

    void Logger::log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mtx_);
        logFile_ << message << std::endl;
        std::cout << "[LOG] " << message << std::endl;
    }

} // namespace restaurantManagement
