#include "buyer.hpp"
#include "auction.hpp"
#include <bits/stdc++.h>
using namespace std;

string name;
double balance;

void deductWallet(double amount){
    balance-=amount;
}
double getWalletBalance(){
    return balance;
}
string getName(){
    return name;
}
void placeBid(Auction *auction, double amount){

}

