#pragma once
#include "winningStrategy.hpp"
#include "auction.hpp"
#include "mutex"
#include <bits/stdc++.h>
using namespace std;

class StrategyMgr {
	StrategyMgr() {}
	static StrategyMgr* strategyMgrInstance;
	static mutex mtx;

public:
	static StrategyMgr* getStrategyMgr();
    
	WinningStrategy* getAuctionWinner(unordered_map<string, double> bidsMap,unordered_map<string, bool> preferredBuyers);
};