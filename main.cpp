#include "buyer.hpp"
#include "seller.hpp"
#include "auction.hpp"
#include "buyerMgr.hpp"
#include "sellerMgr.hpp"
#include "auctionMgr.hpp"
#include<bits/stdc++.h>
using namespace std;

void run_test_case_1()
{
    BuyerMgr* buyerMgr = BuyerMgr::GetBuyerMgrInstance();
    SellerMgr* sellerMgr = SellerMgr::GetSellerMgrInstance();
    AuctionMgr* auctionMgr = AuctionMgr::GetAuctionMgrInstance();

    buyerMgr->addBuyer("buyer1");
    buyerMgr->addBuyer("buyer2");
    buyerMgr->addBuyer("buyer3");

    sellerMgr->addSeller("seller1");

    Seller* seller1= sellerMgr->getSeller("seller1");
    auctionMgr->createAuction("A1",10,50,1,seller1);

    Buyer* buyer1= buyerMgr->getBuyer("buyer1");
    Buyer* buyer2= buyerMgr->getBuyer("buyer2");
    Buyer* buyer3= buyerMgr->getBuyer("buyer3");

    auctionMgr->createBid(17,buyer1);
    auctionMgr->createBid(15,buyer2);
    auctionMgr->updateBid(19,buyer2);
    auctionMgr->createBid(19,buyer3);

    auctionMgr->closeAuction();
    unordered_map<string, bool> preferred;
    preferred["buyer1"] = true;
    preferred["buyer2"] = true;

    Buyer* winner= auctionMgr->getAuctionWinner(preferred);
}
void run_test_case_2(){}

int main(){

    run_test_case_1();
    run_test_case_2();
}