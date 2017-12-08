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


int main(int argc, char*argv[]) {

	//Variable Initialization
	vector<string> stockTickers(argc-1, "");
	map <string, Stock> stocks;
	map <dateStruct, double> returns;
	double alpha0, totalReturn, riskFreeRate;
	Stock temp;
	string ticker;


	for(int i = 1; i < argc; ++i) {
		initialize(argv[i], temp);
		cout << "Initialized!" << temp.ticker << endl;
		stockTickers[i-1] = temp.ticker;
		stocks.insert( pair<string, Stock>(temp.ticker, temp) );		
	}

	//give alphas and risk free rate an initial value
	alpha0 = .5;
	riskFreeRate = 0.0;

	//temporary weight value which assigns equal weight to each stock
	double weight = 1/stockTickers.size();

	//Calulate each individual stocks daily returns and add it's daily returns to the overall daily returns
	for(int i = 0; i < stockTickers.size(); ++i) {
		ticker = stockTickers[i];
		temp = stocks.at(ticker);
		temp.calculateDailyReturns(riskFreeRate, weight, returns);
	}


	return 0;

}






