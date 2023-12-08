#include "buyer.hpp"
#include "buyerMgr.hpp"
#include <bits/stdc++.h>
using namespace std;

BuyerMgr* BuyerMgr::BuyerMgrInstance = nullptr;
mutex BuyerMgr::mtx;
unordered_map<string, Buyer*> buyersMap;

BuyerMgr* BuyerMgr::GetBuyerMgrInstance(){
    if(BuyerMgrInstance == nullptr){
        mtx.lock();
        if(BuyerMgrInstance == nullptr){
            BuyerMgrInstance = new BuyerMgr;
        }
        mtx.unlock();
    }
    return BuyerMgrInstance;
}

void BuyerMgr::addBuyer(string pUserName) {
	buyersMap[pUserName] = new Buyer(pUserName); 
}
Buyer* BuyerMgr::getBuyer(string pUserName) {
	return buyersMap[pUserName];
}
unordered_map<string, Buyer*> getBuyersMap(){
    return buyersMap;
}
