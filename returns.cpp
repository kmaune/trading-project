/* returns.cpp */

#include <iostream>
#include <cmath>
#include <string> 
#include <fstream>
#include <vector>
#include <map>
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

	//temporary weight value which assigns equal weight to each stock
 	double tempWeight = 1.0/(argc-1);

	//Initialize stocks 
	for(int i = 1; i < argc; ++i) {
		initialize(argv[i], temp, tempWeight);
		cout << "Initialized!" << temp.ticker << endl;
		stockTickers[i-1] = temp.ticker;
		stocks.insert( pair<string, Stock>(temp.ticker, temp) );		
	}

	//give alphas and risk free rate an initial value
	alpha0 = .5;
	riskFreeRate = 0.0;

	//Calulate each individual stocks daily returns and add it's daily returns to the overall daily returns
	for(int i = 0; i < stockTickers.size(); ++i) {
		ticker = stockTickers[i];
		temp = stocks.at(ticker);
		temp.calculateDailyReturns(riskFreeRate, returns);
	}

	//Run MLE or Min log likelihood calculation

	//For given alpha calculate optimal phi

	

	return 0;

}






