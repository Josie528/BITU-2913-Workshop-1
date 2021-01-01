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

	HealthHistory(string hID, string hsick, string htreat,
		string hsymp, string hgID, time_t hdaterec)
	{
		healthHistoryID = hID;
		sickness = hsick;
		treatment = htreat;
		symptom = hsymp;
		goatID = hgID;
		dateOfRecord = hdaterec;
	}

	HealthHistory()
	{
		healthHistoryID = "";
		sickness = "";
		treatment = "";
		symptom = "";
		goatID = "";
		dateOfRecord = 0000-00-00;
	}

};
#endif
