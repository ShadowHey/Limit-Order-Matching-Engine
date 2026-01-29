#pragma once
#include <map>
#include <iostream>
#include "price_level.hpp"

struct OrderBook
{
    std::map<double,uint64_t,std::greater<double>> bids;// Key: price, Value: PriceLevel
    std::map<double,uint64_t ,std::less<double>> asks; // Key: price, Value: PriceLevel      
    void print() const {
        std::cout << "\n<-------Order Book------->\n";
        std::cout << "Bids:\n";
        std::cout << "Price" << "\t" << "Quantity" << "\n";
        for (const auto &[price, quantity] : bids)
        {
            std::cout << price << "\t" << quantity <<"\n";
        }

        std::cout << "Asks:\n";
        std::cout << "Price" << "\t" << "Quantity" << "\n";
        for (const auto& [price, quantity] : asks) 
        {
            std::cout << price << "\t" << quantity <<"\n";

        }
        std::cout << "\n<-------Order Book End------->\n";
    }
};

