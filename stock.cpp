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
	//map<dateStruct, double> temp;
	double dayReturn;
	for(map<dateStruct, stockData>::iterator iter = data.begin(); iter != data.end(); ++iter) {
		//cout << "iter Date: " << iter->first.month << "/" << iter->first.day << "/" << iter->first.year << endl;

		// calculate stocks individual daily return, (r_f - r_i)/r_i, then subtract the risk free rate
		dayReturn = (iter->second.close - iter->second.open)/iter->second.open;
		dayReturn -= riskFreeRate;
		//cout << "dayReturn = " << dayReturn << endl;
		dailyReturns.insert(pair<dateStruct, double>(iter->first, dayReturn));

		//Add the individual stocks daily return to the total daily returns map, using the weight to make the appropriate adjustment
		//If this date hasn't been added to the total Returns map yet
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


