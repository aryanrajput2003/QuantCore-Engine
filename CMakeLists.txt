cmake_minimum_required(VERSION 3.10)
project(TradingEngine)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(engine main.cpp OrderBook.cpp)