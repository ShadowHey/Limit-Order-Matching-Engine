#include "matching_engine.hpp"
#include <algorithm>
//bids ka mtlb hai itne mein khareedunga
//asks hain itne mein bechunga bhaiii
//sell kroge to bids ke paas jaao
//buy krna hai to asks ke paas jaao
void MatchingEngine :: process_order(Order& order){
    if(order.side == Side::Buy){
        auto best = book.asks.begin();
        while (order.quantity > 0 && best!= book.asks.end()){
                if(best->first > order.price) break;
                else {
                    if(best->second <= order.quantity){
                        order.quantity -= best->second;
                        book.asks.erase(best++);
                        
                    } else {
                        best->second -= order.quantity;
                        order.quantity =0;
                        break;
                    }
                }
        }
        if (order.quantity >0){
            book.bids.emplace(order.price,order.quantity);
        }
        } else if(order.side ==Side::Sell){
        auto best = book.bids.begin();
        while (order.quantity > 0 && best!= book.bids.end()){
                if(best->first < order.price) break;
                else {
                    if(best->second <= order.quantity){
                        order.quantity -= best->second;
                        book.asks.erase(best++);
                        
                    } else {
                        best->second -= order.quantity;
                        order.quantity =0;
                        break;
                    }
                }
        }
        if (order.quantity >0){
            book.asks.emplace(order.price,order.quantity);
        }
    }

}

