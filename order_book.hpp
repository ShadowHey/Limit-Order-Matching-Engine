#pragma once
#include <map>
#include <iostream>
#include "price_level.hpp"

struct OrderBook
{
    std::map<double,PriceLevel,std::greater<double>> bids;// Key: price, Value: PriceLevel
    std::map<double,PriceLevel ,std::less<double>> asks; // Key: price, Value: PriceLevel      
    void print() const {
        std::cout << "\n---Order Book---\n";
        std::cout << "Bids:\n";
        for (const auto &[price, level] : bids)
        {
            std::cout << "Price: " << price << ", Orders: ";
            for (const auto &order : level.orders)
            {
                std::cout << order->order_id << " ";
            }
            std::cout << "\n";
        }

    std::cout << "Asks:\n";
    for (const auto& [price, level] : asks) {
        std::cout << "Price: " << price << ", Orders: ";
        for (const auto& order : level.orders) {
            std::cout << order->order_id << " ";
        }
        std::cout << "\n";
        }
    }
};

