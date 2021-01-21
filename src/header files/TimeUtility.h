#ifndef TimeUtility_H
#define TimeUtility_H

#include<string>
#include<ctime>

using namespace std;

class TimeFunc {
public:
	//Convert time_t variable to a string with format "yyyy-mm-dd"
	string dateToString(time_t time);

	//Convert time_t variable to a string with format "yyyy-mm-dd HH:mm:ss"
	string datetimeToString(time_t time);

	//Convert string in the form "yyyy-mm-dd" to time_t variable
	time_t dateToTime_t(const string& strDateTime);

	//Convert string in the form "yyyy-mm-dd HH:mm::ss" to time_t variable
	time_t datetimeToTime_t(const string& strDateTime);

	time_t userInputToTime_t(int year, int month, int day);

	time_t userInputToTime_t(int year, int month, int day, int hour_24, int minute, int seconds);
};

#endif
