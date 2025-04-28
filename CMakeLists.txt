cmake_minimum_required(VERSION 3.30)
project(proiect)

set(CMAKE_CXX_STANDARD 20)

add_executable(proiect main.cpp
        Headers/MenuItem.h
        Sources/MenuItem.cpp
        Headers/Reservation.h
        Sources/Reservation.cpp
        Headers/Table.h
        Sources/Table.cpp
        Headers/Order.h
        Sources/Order.cpp
        Headers/Inventory.h
        Sources/Inventory.cpp
        Headers/Restaurant.h
        Sources/Restaurant.cpp
        Headers/TUI.h
        Sources/TUI.cpp
        Headers/Product.h
        Headers/Observer.h
        Headers/Observable.h
        Sources/Observable.cpp
        Headers/Logger.h
        Sources/Logger.cpp
        Headers/OrderProcessor.h
        Sources/OrderProcessor.cpp
)
