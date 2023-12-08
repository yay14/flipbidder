#include "strategyMgr.hpp"
#include "winningStrategy.hpp"
#include "defaultWinningStrategy.hpp"

StrategyMgr* StrategyMgr::strategyMgrInstance = nullptr;
mutex StrategyMgr::mtx;

StrategyMgr* StrategyMgr::getStrategyMgr() {
	if (strategyMgrInstance == nullptr) {
		mtx.lock();
		if (strategyMgrInstance == nullptr) {
			strategyMgrInstance = new StrategyMgr();
		}
		mtx.unlock();
	}
	return strategyMgrInstance;
}

WinningStrategy* StrategyMgr::getAuctionWinner(unordered_map<string, double> bidsMap,unordered_map<string, bool> preferredBuyers) {
	cout << "Based on selection, setting winning strategy" << endl;
	DefaultWinningStrategy* defaultWinner= new DefaultWinningStrategy();
    defaultWinner->findWinner(bidsMap, preferredBuyers );
}

