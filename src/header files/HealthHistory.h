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
		sickness = hsick;
		treatment = htreat;
		dateOfRecord = hdaterec;
		symptom = hsymp;
		goatID = hgID;
	}

	HealthHistory()
	{
		healthHistoryID = "";
		sickness = "";
		treatment = "";
		dateOfRecord = 0000 - 00 - 00;
		symptom = "";
		goatID = "";
	}

};
#endif
