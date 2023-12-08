#pragma once
#include "auction.hpp"
#include "buyer.hpp"
#include "strategyMgr.hpp"
#include "winningStrategy.hpp"
#include <mutex>
#include <bits/stdc++.h>
using namespace std;

class AuctionMgr {
    AuctionMgr() {}
    static AuctionMgr* AuctionMgrInstance;
    static mutex mtx;
    // id to auction mapping
    unordered_map<string, Auction*> auctionsMap;
    unordered_map<string, double> bidsMap;
    priority_queue<pair<double,Buyer>> bids;
    unordered_map<string,bool> preferredBuyers;
    WinningStrategy* winningStrategy;
    public:
        static AuctionMgr* GetAuctionMgrInstance();
        void createAuction(string id,double pLowestBidAmount, double pHighestBidAmount, const double pCost, Seller* pSeller);
        void createBid(double amount, Buyer* buyer);
        void updateBid(double amount, Buyer* Buyer);
        unordered_map<string, double> getBids();
        // send list of preferred buyer
        Buyer* getAuctionWinner(unordered_map<string, bool> preferredBuyers);
        void closeAuction();
};