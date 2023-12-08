#pragma once
#include "winningStrategy.hpp"

class DefaultWinningStrategy : public WinningStrategy {
public:
	string findWinner(unordered_map<string, double> bids,unordered_map<string, bool> preferredBuyers) {
		priority_queue<pair<double,string>> q;
		unordered_map<double, vector<string>> bidsCount;
		for(auto pr: bids){
			string name= pr.first;
			double amt= pr.second;
			q.push({amt,name});
			bidsCount[amt].push_back(name);
		}
		while(!q.empty()) {
			auto rm= q.top();
			q.pop();
			double amt= rm.first;
			string name= rm.second;
			if(bidsCount[amt].size()==1)
			return name;
			
			vector<string> buyers= bidsCount[amt];
			for(string buyer: buyers)
			{
				if(preferredBuyers.find(name)!=preferredBuyers.end()) 
				return buyer;
			}
		}
		// if no winner found
		return "";
	}
};