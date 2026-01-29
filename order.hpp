#pragma once
#include <cstdint>

enum class Side
{
    Buy,
    Sell
};

struct Order
{
    Side side;
    double price;
    uint64_t quantity;
};