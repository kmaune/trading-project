//// Stock.h ////
/* 

*/

#ifndef __STOCK_H__
#define __STOCK_H__

#include <vector>
#include <string>


using namespace std;

struct stockData {

		double open;
		double close;
		double high;
		double low;
		int volume;
};

struct dateStruct {
	int day;
	int month;
	int year;

	friend bool operator<(const dateStruct& a, const dateStruct& b);
};

class Stock {

	public:
		Stock();
		Stock(string tickc);
		//~stock();
		vector<stockData> data; 
		string ticker;
		dateStruct date;

};



#endif 


