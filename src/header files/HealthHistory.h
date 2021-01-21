#include <string>
#include <time.h>
using namespace std;

#ifndef HEALTHHISTORY_H
#define HEALTHHISTORY_H

class HealthHistory
{
public:
	string healthHistoryID, sickness, treatment, symptom, goatID;
	time_t dateOfRecord;

	HealthHistory(string hID, string hsick, string htreat, time_t hdaterec,
		string hsymp, string hgID)
	{
		healthHistoryID = hID;
		goatID = hgID;
		sickness = hsick;
		symptom = hsymp;
		treatment = htreat;
		dateOfRecord = hdaterec;	
	}

	HealthHistory()
	{
		healthHistoryID = "";
		goatID = "";
		sickness = "";
		symptom = "";
		treatment = "";
		dateOfRecord = 0000 - 00 - 00;
	}

};
#endif
