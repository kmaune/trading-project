//// Stock.h ////
/* 

*/

#ifndef __STOCK_H__
#define __STOCK_H__

#include <vector>
#include <string>


using namespace std;

struct dateStruct {
	int day;
	int month;
	int year;

	friend bool operator<(const dateStruct& a, const dateStruct& b);
};

struct stockData {

		double open;
		double close;
		double high;
		double low;
		int volume;
		dateStruct date;
};


class Stock {

	public:
		Stock();
		Stock(string tick);
		//~stock();
		map<dateStruct, stockData> data; 
		map<dateStruct, double> dailyReturns;
		string ticker;
		void calculateDailyReturns(double riskFreeRate, double weight, map<dateStruct, double> &returns);
};



#endif 


