#include "auctionMgr.hpp"
#include "auction.hpp"
#include "buyerMgr.hpp"
#include "winningStrategy.hpp"

#include <bits/stdc++.h>
using namespace std;

AuctionMgr* AuctionMgr::AuctionMgrInstance = nullptr;
mutex AuctionMgr::mtx;
unordered_map<string, Auction*> auctionsMap;
unordered_map<string, double> bidsMap;
unordered_map<string,bool> preferredBuyers;
WinningStrategy* winningStrategy;
bool isOpenForBid= false;

AuctionMgr* AuctionMgr::GetAuctionMgrInstance(){
    if(AuctionMgrInstance == nullptr){
        mtx.lock();
        if(AuctionMgrInstance == nullptr){
            AuctionMgrInstance = new AuctionMgr;
        }
        mtx.unlock();
    }
    return AuctionMgrInstance;
}

void AuctionMgr::createAuction(string id,double pLowestBidAmount, double pHighestBidAmount, const double pCost, Seller* pSeller){
    auctionsMap[id] = new Auction(id, pLowestBidAmount, pHighestBidAmount, pCost, pSeller);
}

unordered_map<string, double> AuctionMgr::getBids()  {
    return bidsMap;
}      

void createBid(double amount, Buyer* buyer){
    string name= buyer->getName();
    bidsMap[name] = amount;
}

void updateBid(double amount, Buyer* buyer){
    string name= buyer->getName();
    bidsMap[name] = amount;
}

void closeAuction(){
    isOpenForBid = false;
}

Buyer* getAuctionWinner(unordered_map<string, bool> preferredBuyers){
    if(isOpenForBid){ 
        cout<<"Auction is still in progress: "<<endl;
        return NULL;
    }

    StrategyMgr* strategyMgr = StrategyMgr::getStrategyMgr();
    string name = winningStrategy->findWinner(bidsMap, preferredBuyers);
    auto buyers= BuyerMgr::buyersMap;
    return buyers[name];
}