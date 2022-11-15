//
// Created by tseed on 2022-11-15.
//

#include "NodeTracker.h"

#include <utility>
#include <iostream>

NodeTracker::NodeTracker() = default;

NodeTracker::NodeTracker(std::map<std::string, TradeNode> tradeNodes) : tradeNodes(std::move(tradeNodes)) {}

void NodeTracker::addNewTradeNode(const TradeNode& newNode) {
    if (tradeNodes.count(newNode.name) == 1){
        throw std::invalid_argument("Existing node given to addNewTradeNode");
    } else {
        tradeNodes.insert(std::pair<std::string, TradeNode>(newNode.name, newNode));
    }
}

TradeNode NodeTracker::getTradeNode(const std::string& name) {
    if (tradeNodes.count(name) == 0){
        throw std::invalid_argument("Node not found by getTradeNode");
    } else {
        return tradeNodes.find(name) -> second;
    }
}

