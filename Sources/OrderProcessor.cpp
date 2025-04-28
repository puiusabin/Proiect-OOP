#include "../Headers/OrderProcessor.h"
#include "../Headers/Logger.h"
#include <chrono>

namespace restaurantManagement {

    OrderProcessor::OrderProcessor()
        : stop_(false) {}

    OrderProcessor::~OrderProcessor() {
        stop();
        if (worker_.joinable())
            worker_.join();
    }

    void OrderProcessor::start() {
        stop_ = false;
        worker_ = std::thread(&OrderProcessor::processLoop, this);
    }

    void OrderProcessor::stop() {
        stop_ = true;
        cv_.notify_all();
    }

    void OrderProcessor::addOrderToQueue(const Order& order) {
        {
            std::lock_guard<std::mutex> lock(mtx_);
            queue_.push(order);
        }
        cv_.notify_one();
    }

    void OrderProcessor::processLoop() {
        while (!stop_) {
            std::unique_lock<std::mutex> lock(mtx_);
            cv_.wait(lock, [this]() { return !queue_.empty() || stop_; });
            if (stop_) break;

            Order ord = queue_.front();
            queue_.pop();
            lock.unlock();

            Logger::getInstance().log("Preparing Order #" + std::to_string(ord.getOrderId()));
            std::this_thread::sleep_for(std::chrono::seconds(2)); // simulare

            notifyObservers("Order #" + std::to_string(ord.getOrderId()) + " is ready");
        }
    }

} // namespace restaurantManagement
