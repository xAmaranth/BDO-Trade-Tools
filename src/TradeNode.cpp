//
// Created by tseed on 2022-11-14.
//

#include <utility>
#include <xstring>
#include "TradeNode.h"

TradeNode::TradeNode(std::string name) : name(std::move(name)), visited(false) {}

void TradeNode::visitNode() { visited = true; }

void TradeNode::resetVisit() { visited = false; }

void TradeNode::newRoute(TradeNode& destination, int value, float time) {
    availableRoutes.emplace_back(Route(*this, destination, value, time));

}
