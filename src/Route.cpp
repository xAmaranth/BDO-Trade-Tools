//
// Created by tseed on 2022-11-14.
//

#include "TradeNode.h"

Route::Route(TradeNode& origin, TradeNode& destination, int value, float time) :
    origin(origin), destination(destination), value(value), time(time) {}

float Route::getSilverPerHour() const { return static_cast<float>(value) / time; }
