#pragma once
#include <cstdint>

enum class Side
{
    Buy,
    Sell
};

struct Order
{
    uint64_t order_id;
    Side side;
    double price;
    uint64_t quantity;
    uint64_t timestamp;
};