#include <iostream>
#include <limits>
#include <map>
#include <string>
#include "OrderBook.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    map<string, OrderBook> exchange;

    bool isRunning = true;
    int orderIdCounter = 1;

    while (isRunning) {
        cout << "\n================================\n";
        cout << "   MULTI-ASSET EXCHANGE (NSE)   \n";
        cout << "================================\n";
        cout << "1. Place Order\n";
        cout << "2. View Order Book for a Stock\n";
        cout << "3. Exit\n";
        cout << ">> Select Option: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input.\n";
            clearInput();
            continue;
        }

        if (choice == 1) {
            string symbol;
            cout << "Enter Stock Symbol (e.g., RELIANCE, TCS): ";
            cin >> symbol;

            int sideChoice;
            double price;
            int quantity;

            cout << "Side (1 = Buy, 2 = Sell): ";
            cin >> sideChoice;
            
            Side side = (sideChoice == 1) ? Side::Buy : Side::Sell;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Sending Order to " << symbol << " book...\n";
            exchange[symbol].addOrder(orderIdCounter++, price, quantity, side, OrderType::Limit);
            
        } 
        else if (choice == 2) {
            string symbol;
            cout << "Enter Stock Symbol to View: ";
            cin >> symbol;

            if (exchange.find(symbol) != exchange.end()) {
                cout << "\n--- Order Book for " << symbol << " ---\n";
                exchange[symbol].printBook();
            } else {
                cout << "[ERROR] No orders exist for " << symbol << " yet.\n";
            }
        } 
        else if (choice == 3) {
            isRunning = false;
        } 
    }

    return 0;
}
