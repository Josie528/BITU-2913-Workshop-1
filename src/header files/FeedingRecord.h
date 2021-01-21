#include <string>
#include <time.h>
using namespace std;

#ifndef FEEDINGRECORD_H
#define FEEDINGRECORD_H

class FeedingRecord
{
public:
	string goatID, feedID, staffID;
	double quantity;
	time_t feedingTime;

	FeedingRecord(string frgID, string frfID, 
		string frsID, int frqty, time_t frfeedtime)
	{
		goatID = frgID;
		feedID = frfID;
		staffID = frsID;
		quantity = frqty;
		feedingTime = frfeedtime;
	}

	FeedingRecord()
	{
		goatID = "";
		feedID = "";
		staffID = "";
		quantity = 0;
		feedingTime = time(0);
	}
};

#endif