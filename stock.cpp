// stock.cpp //

#include <vector>
#include <string>
#include <map>
#include "stock.h"

using namespace std;

Stock::Stock() {
	ticker = "";
	data.resize(1500);
}

Stock::Stock(string tick) {
	ticker = tick;
	data.resize(1500);
}
