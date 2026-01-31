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
    uint64_t price;
    uint64_t quantity;
};