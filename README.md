# High-Performance Limit Order Book (C++)
A low-latency Order Matching Engine implementing a multi-asset exchange simulator. Designed to handle Limit Orders with strict Price-Time priority matching.

## Key Features
Core Engine: Implemented in C++17 using STL containers (`std::map`, `std::unordered_map`) for O(log n) order insertion and deletion.
Multi-Asset Support: Supports trading across multiple ticker symbols (e.g., RELIANCE, TCS) concurrently.
Smart Pointers: Utilizes `std::shared_ptr` for automated memory management and leak prevention.
Interactive CLI: Dashboard interface for placing orders and visualizing market depth in real-time.

## How to Build & Run
### Prerequisites
* G++ Compiler (supporting C++17) or CMake

### Build
g++ -std=c++17 main.cpp OrderBook.cpp -o QuantCore

### Run
./QuantCore