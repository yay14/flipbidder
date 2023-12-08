#pragma once
#include "buyer.hpp"
#include <mutex>
#include <bits/stdc++.h>
using namespace std;

class BuyerMgr {
    BuyerMgr() {}
    static BuyerMgr* BuyerMgrInstance;
    static mutex mtx;
    public:
        static unordered_map<string, Buyer*> buyersMap;
        static BuyerMgr* GetBuyerMgrInstance();
        void addBuyer(string name);
        Buyer* getBuyer(string name);
        unordered_map<string, Buyer*> getBuyersMap();
};