#include "seller.hpp"
#include "sellerMgr.hpp"
#include <bits/stdc++.h>
using namespace std;

SellerMgr* SellerMgr::SellerMgrInstance = nullptr;
mutex SellerMgr::mtx;
unordered_map<string, Seller*> usersMap;

SellerMgr* SellerMgr::GetSellerMgrInstance(){
    if(SellerMgrInstance == nullptr){
        mtx.lock();
        if(SellerMgrInstance == nullptr){
            SellerMgrInstance = new SellerMgr;
        }
        mtx.unlock();
    }
    return SellerMgrInstance;
}

void SellerMgr::addSeller(string pUserName) {
	usersMap[pUserName] = new Seller(pUserName); 
}
Seller* SellerMgr::getSeller(string pUserName) {
	return usersMap[pUserName];
}