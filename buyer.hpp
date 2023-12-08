#pragma once
#include "auction.hpp"
#include <bits/stdc++.h>
using namespace std;

class Buyer{
    string name;
    // assume initial wallet amount is same for each buyer
    double balance = 500;
    public:
    Buyer(string pName){
        this->name = pName;
    }
    void deductWallet(double amount);
    double getWalletBalamce();
    string getName();
    bool placeBid(Auction *auction, double amount);
};