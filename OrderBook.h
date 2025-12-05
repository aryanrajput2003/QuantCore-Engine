#pragma once
#include "Order.h"
#include <map>
#include <unordered_map>
#include <vector>

class OrderBook {
private:
    std::map<double, OrderList, std::greater<double>> bids;
    
    std::map<double, OrderList, std::less<double>> asks;

    void matchOrders();

public:
    void addOrder(int id, double price, int qty, Side side, OrderType type);
    
    void printBook();
};
