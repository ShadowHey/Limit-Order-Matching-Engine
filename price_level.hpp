#pragma once
#include <deque>
#include "order.hpp"

struct PriceLevel {
    double price;
    std::deque<Order*> orders;

    explicit PriceLevel(double p) : price(p) {}
};

//why deque can add or remove at both ends add at back
//remove filled orders from front


//orders are created like PriceLevel level(100) which
//means create a shelf named level for price 100 which
//is double

// PriceLevel(100) that is without a name it would be
// create and then destroy immediately

//pragma once means include this file once only not
//to slow down the program by including it multiple times 
