#include <string>
#include <time.h>
using namespace std;

#ifndef MILKCOLLECTION_H
#define MILKCOLLECTION_H

class MilkCollection
{
public:
	string goatID, staffID, goatShedID;
	double quantity;
	time_t dateCollect;

	MilkCollection(string mgID, string msID, 
		string mgsID, int mqty, time_t mdatecol) 
	{
		goatID = mgID;
		staffID = msID;
		goatShedID = mgsID;
		quantity = mqty;
		dateCollect = mdatecol;
	}

	MilkCollection()
	{
		goatID = "";
		staffID = "";
		goatShedID = "";
		quantity = 0.0;
		dateCollect = 0000-00-00;
	}
};

#endif