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
	dateStruct d;
	string trash, unparsedDate, adjOpen, adjClose, adjHigh, adjLow, adjVolume; 
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
		getline(stockInfo, unparsedDate, ',');
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
			parseDate(d, unparsedDate);
			temp.date = d;
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

void parseDate(dateStruct& d, string unparsedDate) {
	int j = 0;
	bool formatFound = false;
	cout << "Unparsed Date: " << unparsedDate << endl;
	while(!formatFound) {
		if(unparsedDate[j] == '/') {
			//cout << "j value: " << j << endl;
			cout << "Month substring: " << unparsedDate.substr(0,j) << endl;
			d.month = stod(unparsedDate.substr(0,j)); 
			monthFormat(d, unparsedDate, j+1);
			break;
		}
		if(unparsedDate[j] == '-') {
			//cout << "j value: " << j << endl;
			cout << "Year substring: " << unparsedDate.substr(0,j) << endl;
			d.year = stod(unparsedDate.substr(0,j));
			yearFormat(d, unparsedDate, j+1);
			break;
		}
		j++;
	}
}

void monthFormat(dateStruct &d, string &unparsedDate, int i) {
	for(int j = 3; j < unparsedDate.size(); j++){
		if(unparsedDate[j] == '/') {
			cout << "Day substring: " << unparsedDate.substr(i, j-i) << endl;
			d.day = stod(unparsedDate.substr(i, j-i));
			i = j+1;
			break;
		}
	}		
	cout << "Year substring: " << unparsedDate.substr(i, unparsedDate.size()-i) << endl;
	d.year = stod(unparsedDate.substr(i, unparsedDate.size()-i));

}



void yearFormat(dateStruct &d, string &unparsedDate, int i) {
	for(int j = 5; j < unparsedDate.size(); j++) {
		if(unparsedDate[j] == '-') {
			cout << "Month substring: " << unparsedDate.substr(i,j-i) << endl;
			d.month = stod(unparsedDate.substr(i,j-1));
			i = j+1;
			break;
		}
	}
	cout << "Day substring: " << unparsedDate.substr(i, unparsedDate.size()-i) << endl;
	d.day = stod(unparsedDate.substr(i,unparsedDate.size()-i));
}
