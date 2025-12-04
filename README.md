# QuantCore Engine 🚀

**A High-Performance Limit Order Book (LOB) & Matching Engine built in C++17.**

![C++](https://img.shields.io/badge/Language-C++17-blue.svg)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## 📖 Overview
**QuantCore Engine** is a low-latency financial exchange simulator designed to mimic the core matching logic of major stock exchanges (like NASDAQ or NSE). It supports multi-asset trading, handling thousands of orders with strict **Price-Time Priority** logic.

This project demonstrates advanced systems programming concepts, including manual memory management using Smart Pointers, algorithmic optimization (Big O complexity), and Object-Oriented Design.

## ✨ Key Features
* **Multi-Asset Support:** scalable architecture capable of handling multiple ticker symbols (e.g., RELIANCE, TCS, AAPL) simultaneously using a dynamic `Exchange` manager.
* **Price-Time Priority:** Implements standard FIFO matching:
    * *Price Priority:* Best offers are filled first.
    * *Time Priority:* Orders at the same price are filled based on arrival time.
* **Optimized Data Structures:**
    * Uses `std::map` (Red-Black Trees) for **O(log n)** order book depth management.
    * Uses `std::list` for **O(1)** insertion/deletion of orders at specific price levels.
* **Modern C++ Practices:** Zero manual `new`/`delete`. Utilizes `std::shared_ptr` for leak-free memory management.
* **Interactive CLI:** Real-time dashboard to place orders, view market depth, and visualize trade executions.

## 🛠️ Technical Architecture
The system is built on three core components:

1.  **The Order (`Order.h`):** Lightweight structure managed via smart pointers.
2.  **The Order Book (`OrderBook.cpp`):** The core matching engine. It separates Bids and Asks into sorted maps to allow for instant "Best Price" lookup.
3.  **The Interface (`main.cpp`):** A command-line gateway that parses user input and routes trades to the correct order book.

## 🚀 How to Build & Run

### Prerequisites
* A C++ Compiler (GCC, Clang, or MSVC) supporting C++17.

### Compilation
You can compile the engine using the following command in your terminal:

```bash
g++ -std=c++17 main.cpp OrderBook.cpp -o QuantCore
