#include "OrderBook.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void OrderBook::addOrder(int id, double price, int qty, Side side, OrderType type) {
    auto newOrder = make_shared<Order>(id, price, qty, side, type);

    // Generic match lambda (same functionality, shorter code)
    auto matchAgainst = [&](auto &book, auto priceOk) {
        auto it = book.begin();
        while (it != book.end() && newOrder->quantity > 0) {
            double bestPrice = it->first;
            if (!priceOk(newOrder->price, bestPrice)) break;

            OrderList &ordersAtPrice = it->second;
            auto ordersIt = ordersAtPrice.begin();

            while (ordersIt != ordersAtPrice.end() && newOrder->quantity > 0) {
                auto matchedOrder = *ordersIt;
                int tradeQty = min(newOrder->quantity, matchedOrder->quantity);

                // Trade messages preserved exactly
                if (newOrder->side == Side::Buy) {
                    cout << "[TRADE] Buy Order " << newOrder->id
                         << " matched with Sell Order " << matchedOrder->id
                         << " for " << tradeQty << " shares @ $" << bestPrice << "\n";
                } else {
                    cout << "[TRADE] Sell Order " << newOrder->id
                         << " matched with Buy Order " << matchedOrder->id
                         << " for " << tradeQty << " shares @ $" << bestPrice << "\n";
                }

                newOrder->quantity -= tradeQty;
                matchedOrder->quantity -= tradeQty;

                if (matchedOrder->quantity == 0)
                    ordersIt = ordersAtPrice.erase(ordersIt);
                else
                    ++ordersIt;
            }

            if (ordersAtPrice.empty())
                it = book.erase(it);
            else
                ++it;
        }
    };

    if (side == Side::Buy) {
        matchAgainst(asks, [](double np, double bp) { return np >= bp; });
        if (newOrder->quantity > 0) bids[newOrder->price].push_back(newOrder);
    } else {
        matchAgainst(bids, [](double np, double bp) { return np <= bp; });
        if (newOrder->quantity > 0) asks[newOrder->price].push_back(newOrder);
    }
}

void OrderBook::printBook() {
    cout << "\n=== ORDER BOOK ===\n";
    cout << "ASKS (Sells):\n";

    for (auto it = asks.rbegin(); it != asks.rend(); ++it) {
        cout << "  $" << it->first << " : ";
        for (const auto &order : it->second) cout << "[" << order->quantity << "] ";
        cout << "\n";
    }

    cout << "-----------------\n";
    cout << "BIDS (Buys):\n";

    for (const auto &pair : bids) {
        cout << "  $" << pair.first << " : ";
        for (const auto &order : pair.second) cout << "[" << order->quantity << "] ";
        cout << "\n";
    }

    cout << "==================\n\n";
}
