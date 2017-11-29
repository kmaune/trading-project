/* initialization.cpp */

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "stock.h"
#include "initialization.h"

using namespace std;

void initialize(string ticker, Stock &temp) {

	stockData sd;
	string trash, adjOpen, adjClose, adjHigh, adjLow, adjVolume; 
	string filepath = ticker+".csv";
	cout << filepath << endl;

	temp.ticker = ticker;

	//Initialize and open excel file with stock info
	ifstream stockInfo;
	stockInfo.open(filepath);

	//Make sure file opens correctly
	if(stockInfo.is_open()) {  cout << "File has been opened" << endl; }
	else { cout << "Error opening file" << endl; }

	int count = 0;

	//Read Data from file into stock class. 
	while(!stockInfo.eof() && count != 1501) {
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, trash, ',');
		getline(stockInfo, adjOpen, ',');
		getline(stockInfo, adjHigh, ',');
		getline(stockInfo, adjLow, ',');
		getline(stockInfo, adjClose, ',');
		getline(stockInfo, adjVolume);

		if(count > 0)
		{
			sd.open  = stod(adjOpen);
			sd.close = stod(adjClose);
			sd.high = stod(adjHigh);
			sd.low = stod(adjLow);
			sd.volume = stod(adjVolume);
			temp.data[count] = sd;
		}

		/*
		if(count < 4 && count > 0)
		{
			cout << "open" << sd.open << endl;
			cout << "high" << sd.high << endl;
			cout << "low" << sd.low << endl;
			cout << "close" << sd.close << endl;
			cout << "volume" << sd.volume << endl;
		}	
		*/
		
		count++;
	}

	return;
}