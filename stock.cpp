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

map<dateStruct, double> Stock::calculateDailyReturns(double riskFreeRate) {
	//map<dateStruct, stockData>::iterator iterHelper = data.begin();
	map<dateStruct, double> temp;
	double dayReturn;
	for(map<dateStruct, stockData>::iterator iter = data.begin(); iter != data.end(); ++iter) {
		//cout << "iterHelper Date: " << iterHelper->first.month << "/" << iterHelper->first.day << "/" << iterHelper->first.year << endl;
		cout << "iter Date: " << iter->first.month << "/" << iter->first.day << "/" << iter->first.year << endl;

		// (r_f - r_i)/r_i
		dayReturn = (iter->second.close - iter->second.open)/iter->second.open;
		dayReturn -= riskFreeRate;
		cout << "dayReturn = " << dayReturn << endl;
		temp.insert(pair<dateStruct, double>(iter->first, dayReturn));
	}

	return temp;
}


