#include <iostream>
#include <chrono>
#include "matching_engine.hpp"
int main()
{
    MatchingEngine engine;
    Order sell{1, Side::Sell, 102.0, 5, 1};
    Order buy{2, Side::Buy, 90.0, 10, 2};
    
    engine.book.asks.emplace(100.0, PriceLevel(100.0));
    engine.book.asks.find(100.0)->second.orders.push_back(&sell);

    
    auto start = std::chrono::high_resolution_clock::now();
    engine.process_order(buy);
    auto end = std::chrono::high_resolution_clock::now();
    std ::cout << "Buy remaining: " << buy.quantity << "\n";
    auto latency = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Latency (ns): " << latency << "\n";
    return 0;
    
}