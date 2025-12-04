#pragma once
#include <iostream>
#include <memory>
#include <list>
#include <ctime>

enum class Side { Buy, Sell };
enum class OrderType { Market, Limit };

struct Order {
    int id;             // Unique Order ID
    double price;       // Price per share
    int quantity;       // Number of shares
    Side side;          // Buy or Sell
    OrderType type;     // Market or Limit

    // Constructor
    Order(int _id, double _price, int _qty, Side _side, OrderType _type)
        : id(_id), price(_price), quantity(_qty), side(_side), type(_type) {}
};

// Typedefs for cleaner code later
using OrderPtr = std::shared_ptr<Order>;
using OrderList = std::list<OrderPtr>;