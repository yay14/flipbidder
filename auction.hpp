#pragma once
#include "seller.hpp"
#include <bits/stdc++.h>
using namespace std;

class Auction{
    public:
    string id;
    double lowestBidAmount;
    double highestBidAmount;
    double participantCost;
    Seller *seller;
    bool isOpenForBid;
    Auction(string pId, double pLowestBidAmount, double pHighestBidAmount, const double pCost, Seller* pSeller){
        this->id = pId;
        this->lowestBidAmount = pLowestBidAmount;
        this->highestBidAmount = pHighestBidAmount;
        this->seller = pSeller;
        this->participantCost = pCost;
        this-> isOpenForBid = true;
    }
};