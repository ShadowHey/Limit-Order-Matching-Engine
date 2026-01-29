#include <iostream>
#include <chrono>
#include "matching_engine.hpp"
int main()
{
    MatchingEngine engine;
    std::cout << "Welcome to Citadel Trading Software" << std::endl;
    bool a = true;
    while (a)
    {
        uint64_t display_options;
        std::cout << "Enter 1 to place an order" << std::endl;
        std::cout << "Enter 2 to display orderbook" << std::endl;
        std::cout << "Enter 3 to close the software" << std::endl;
        std::cin >> display_options;
        if (display_options == 1)
        {
            uint64_t category_;
            std::cout << "Enter 1 to place a buy order" << std::endl;
            std::cout << "Enter 2 to place a sell order" << std::endl;
            std::cin >> category_;
            if (category_ == 1)
            {
                uint64_t quantity;
                double price;
                std::cout << "Enter price, quantity,respectively" << std::endl;
                std::cin >> price >> quantity;
                Order buy{ Side::Buy, price, quantity};
                auto start = std::chrono::high_resolution_clock::now();
                engine.process_order(buy);
                auto end = std::chrono::high_resolution_clock::now();
                std ::cout << "Buy remaining: " << buy.quantity << "\n";
                auto latency = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::cout << "Latency (ns): " << latency << "\n";
            }else if (category_ == 2)
            {
                uint64_t quantity;
                double price;
                std::cout << "Enter price, quantity respectively" << std::endl;
                std::cin >> price >> quantity;
                Order sell{ Side::Sell, price, quantity};
                auto start = std::chrono::high_resolution_clock::now();
                engine.process_order(sell);
                auto end = std::chrono::high_resolution_clock::now();
                std ::cout << "Sell remaining: " << sell.quantity << "\n";
                auto latency = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::cout << "Latency (ns): " << latency << "\n";
            }
        }else if (display_options == 2)
        {
            engine.book.print();
        }else if (display_options == 3)
        {
            a=false;
        }
    }
}