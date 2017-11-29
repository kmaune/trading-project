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
map <string, vector<stockData> > stocks;
map <string, vector<double> > returns;
vector <double> dailyReturns(1500, INT_MAX);
double alpha0, totalReturn;
Stock temp;



for(int i = 1; i < argc; ++i)
{
	initialize(argv[i], temp);
	cout << "Initialized!" << temp.ticker << endl;
	stockTickers[i-1] = temp.ticker;
	//Add stock class to stocks map
	stocks.insert( pair<string, vector<stockData> >(temp.ticker, temp.data) );		
}

//give alpha an initial value
alpha0 = .5;


//Run calculations





return 0;

}






