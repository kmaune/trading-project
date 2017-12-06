//returns.cpp

#include <iostream>
#include <cmath>
#include <string> 
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <climits>
#include "stock.h"
#include "initialization.h"

using namespace std;



// compute the excess return time series r_i-r_f for each of the three names and run the computations described 
// in the doc, varying the parameter \alpha_0

int main(int argc, char*argv[]) {

	//Variable Initialization
	vector<string> stockTickers(argc-1, "");
	map <string, Stock> stocks;
	//map <string, vector<double> > returns;
	//vector <double> dailyReturns(1500, INT_MAX);
	map<dateStruct, double> dailyReturns;
	double alpha0, totalReturn, riskFreeRate;
	Stock temp;
	string ticker;


	for(int i = 1; i < argc; ++i) {
		initialize(argv[i], temp);
		cout << "Initialized!" << temp.ticker << endl;
		stockTickers[i-1] = temp.ticker;
		//Add stock class to stocks map
		stocks.insert( pair<string, Stock>(temp.ticker, temp) );		
	}

	//give alpha an initial value
	alpha0 = .5;
	riskFreeRate = 0.0;

	//Run calculations
	for(int i = 0; i < 1/*stockTickers.size()*/; ++i) {
		ticker = stockTickers[i];
		cout << ticker << endl;
		temp = stocks.at(ticker);
		temp.calculateDailyReturns(riskFreeRate);
	}



	return 0;

}






