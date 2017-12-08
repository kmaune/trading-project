// stock.cpp //

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "stock.h"

using namespace std;


bool operator<(const dateStruct& a, const dateStruct& b) {
	if(a.year == b.year) {
		if(a.month == b.month) {
			return (a.day < b.day);
		}
		return (a.month < b.month);
	}
	return (a.year < b.year);
}

Stock::Stock() {
	ticker = "";
}

Stock::Stock(string tick) {
	ticker = tick;
}

void Stock::calculateDailyReturns(double riskFreeRate, double weight, map<dateStruct, double> &returns) {
	double dayReturn;
	for(map<dateStruct, stockData>::iterator iter = data.begin(); iter != data.end(); ++iter) {
		// calculate stocks individual daily return minus risk free rate
		dayReturn = (iter->second.close - iter->second.open)/iter->second.open;
		dayReturn -= riskFreeRate;
		dailyReturns.insert(pair<dateStruct, double>(iter->first, dayReturn));

		//Add indiv. stocks daily return to the total daily returns map w/ weight adjustment
		//If this date hasn't been initialized in total returns map yet
		if(returns.find(iter->first) == returns.end()) {
			returns.insert(pair<dateStruct, double>(iter->first, dayReturn*weight));
		}

		//If the date has already been init. in the total returns map
		else {
			returns[iter->first] = returns[iter->first] + (dayReturn*weight);
		}
	}

	return;
}


