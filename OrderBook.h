#pragma once
#include "Order.h"
#include <map>
#include <unordered_map>
#include <vector>

class OrderBook {
private:
    // Bids: Sorted High -> Low
    std::map<double, OrderList, std::greater<double>> bids;
    
    // Asks: Sorted Low -> High
    std::map<double, OrderList, std::less<double>> asks;

    // Helper functions to execute trades
    void matchOrders();

public:
    // Main interface
    void addOrder(int id, double price, int qty, Side side, OrderType type);
    
    // For visualization/debugging
    void printBook();
};