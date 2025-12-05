#pragma once
#include <iostream>
#include <memory>
#include <list>
#include <ctime>

enum class Side { Buy, Sell };
enum class OrderType { Market, Limit };

struct Order {
    int id;            
    double price;       
    int quantity;     
    Side side;        
    OrderType type;    

    Order(int _id, double _price, int _qty, Side _side, OrderType _type)
        : id(_id), price(_price), quantity(_qty), side(_side), type(_type) {}
};

using OrderPtr = std::shared_ptr<Order>;
using OrderList = std::list<OrderPtr>;
