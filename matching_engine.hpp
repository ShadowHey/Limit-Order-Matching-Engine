#pragma once
#include "order_book.hpp"

struct MatchingEngine
{
    OrderBook book;
    void process_order(Order &order);
    void cancel(uint64_t order_id);

};