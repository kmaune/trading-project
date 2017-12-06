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
		Stock(string tickc);
		//~stock();
		map<dateStruct, stockData> data; 
		string ticker;
		map<dateStruct, double> calculateDailyReturns(double riskFreeRate);



};



#endif 


