#include "matching_engine.hpp"
#include <algorithm>

void MatchingEngine :: process_order(Order& order){
    if(order.side == Side::Buy){
        auto& asks = book.asks;
        while (order.quantity >0 && !asks.empty()){
            auto it = asks.begin();
            PriceLevel &level = it->second;
            Order *sell = level.orders.front();
            if (order.price != 0 && sell->price > order.price) break;

            uint64_t traded = std::min(order.quantity, sell->quantity);
            order.quantity -= traded;
            sell->quantity -= traded;
            if (sell->quantity ==0){
                level.orders.pop_front();
            }
            if (level.orders.empty()){
                asks.erase(it);
            }
        }

    }
    else if (order.side == Side::Sell)
    {
        auto &bids = book.bids;
        while (order.quantity > 0 && !bids.empty())
        {
            auto it = bids.begin();
            PriceLevel &level = it->second;
            Order *buy = level.orders.front();
            if (order.price != 0 && buy->price < order.price) break;
            uint64_t traded = std::min(order.quantity, buy->quantity);
            order.quantity -= traded;
            buy->quantity -= traded;
            if (buy->quantity ==0){
                level.orders.pop_front();
            }
            if (level.orders.empty()){
                bids.erase(it);
            }
        }
    }
    if (order.quantity > 0) {
    if (order.side == Side::Buy) {
        book.bids.emplace(order.price, PriceLevel(order.price));
        book.bids.find(order.price)->second.orders.push_back(&order);
    }
    else if (order.side == Side::Sell) {
        book.asks.emplace(order.price, PriceLevel(order.price));
        book.asks.find(order.price)->second.orders.push_back(&order);
    }
}

}
