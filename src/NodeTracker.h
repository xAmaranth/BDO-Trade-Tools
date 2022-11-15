//
// Created by tseed on 2022-11-15.
//

#ifndef BDOTRADER_NODETRACKER_H
#define BDOTRADER_NODETRACKER_H
#include <map>
#include "TradeNode.h"


class NodeTracker {
public:
   std::map<std::string, TradeNode> tradeNodes;

   NodeTracker();
   explicit NodeTracker(std::map<std::string, TradeNode> tradeNodes);

   void addNewTradeNode(const TradeNode& newNode);
   TradeNode getTradeNode(const std::string& name);
};


#endif //BDOTRADER_NODETRACKER_H
