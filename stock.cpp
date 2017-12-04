// stock.cpp //

#include <vector>
#include <string>
#include <map>
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
	data.resize(1500);
}

Stock::Stock(string tick) {
	ticker = tick;
	data.resize(1500);
}
