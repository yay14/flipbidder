#pragma once
#include "seller.hpp"
#include <mutex>
#include <bits/stdc++.h>
using namespace std;

class SellerMgr {
    SellerMgr() {}
    static SellerMgr* SellerMgrInstance;
    static mutex mtx;
    unordered_map<string, Seller*> sellersMap;
    public:
        static SellerMgr* GetSellerMgrInstance();
        void addSeller(string name);
        Seller* getSeller(string name);
};