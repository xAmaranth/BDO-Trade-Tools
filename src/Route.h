//
// Created by tseed on 2022-11-14.
//

#ifndef BDOTRADER_ROUTE_H
#define BDOTRADER_ROUTE_H

class TradeNode;

class Route{
public:
    TradeNode &origin;
    TradeNode &destination;
    int value;
    float time;

    Route(TradeNode& origin, TradeNode& destination, int value, float time);

    float getSilverPerHour() const;
};

#endif //BDOTRADER_ROUTE_H
