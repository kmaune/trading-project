/* initialization.h */

#ifndef __INITIALIZATION_H__
#define __INITIALIZATION_H__

#include <vector>
#include <string>
#include "stock.h"


using namespace std;


void initialize(string ticker, Stock &temp, double weight);

void parseDate(dateStruct &d, string unparsedDate);

void monthFormat(dateStruct &d, string &unparsedDate, int i);

void yearFormat(dateStruct &d, string &unparsedDate, int i); 

#endif 
