#ifndef ORDERPROCESSOR_H
#define ORDERPROCESSOR_H

#include "Observable.h"
#include "Order.h"
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace restaurantManagement {

    class OrderProcessor : public Observable {
    private:
        std::queue<Order> queue_;
        std::mutex mtx_;
        std::condition_variable cv_;
        std::thread worker_;
        std::atomic<bool> stop_;

        void processLoop();

    public:
        OrderProcessor();
        ~OrderProcessor();

        void start();
        void stop();
        void addOrderToQueue(const Order& order);
    };

} // namespace restaurantManagement

#endif // ORDERPROCESSOR_H
