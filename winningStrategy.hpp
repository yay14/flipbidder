#pragma once
#include "winningStrategy.hpp"
#include <bits/stdc++.h>
using namespace std;

class WinningStrategy {
public:
	WinningStrategy* determineWinningStrategy() {
	cout << "Setting highest bid as default winnning strategy" << endl;
	return new DefaultWinningStrategy();
	}
	virtual string findWinner(unordered_map<string,double> bids, unordered_map<string, bool> preferredBuyers) = 0;
};