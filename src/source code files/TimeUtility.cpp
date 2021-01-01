#include <string>
#include <ctime>
#include <sstream>
#include "TimeUtility.h"

using namespace std;

//Completed and tested
string TimeFunc::dateToString(time_t time)
{
	tm* ltm = new tm;

	localtime_s(ltm, &time);

	string local_time;

	local_time += to_string(ltm->tm_year + 1900) + "-";
	local_time += to_string(ltm->tm_mon + 1) + "-";
	local_time += to_string(ltm->tm_mday);

	delete ltm;

	return local_time;
}

//Completed and tested
string TimeFunc::datetimeToString(time_t time)
{
	tm* ltm = new tm;
	localtime_s(ltm, &time);

	string local_time;

	local_time += to_string(ltm->tm_year + 1900) + "-";
	local_time += to_string(ltm->tm_mon + 1) + "-";
	local_time += to_string(ltm->tm_mday) + " ";

	if(ltm->tm_hour >= 10) local_time += to_string(ltm->tm_hour) + ":";
	else local_time += "0" + to_string(ltm->tm_hour) + ":";
	if (ltm->tm_min >= 10) local_time += to_string(ltm->tm_min) + ":";
	else local_time += "0" + to_string(ltm->tm_min) + ":";
	if (ltm->tm_sec >= 10) local_time += to_string(ltm->tm_sec);
	else local_time += "0" + to_string(ltm->tm_sec);

	delete ltm;

	return local_time;
}

//Completed and tested
time_t TimeFunc::dateToTime_t(const string& strDateTime) {
	stringstream ss;

	ss << strDateTime;

	int year, month, day;
	ss >> year;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> day;

	tm t;
	time_t rawtime = time(0);

	localtime_s(&t, &rawtime);

	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;

	return mktime(&t);
}

//Completed and tested
time_t TimeFunc::datetimeToTime_t(const string& strDateTime) {
	stringstream ss;

	ss << strDateTime;

	int year, month, day, hour_24, minute, seconds;
	ss >> year;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> day;
	ss.ignore();
	ss >> hour_24;
	ss.ignore();
	ss >> minute;
	ss.ignore();
	ss >> seconds;

	tm t;
	time_t rawtime = time(0);

	localtime_s(&t, &rawtime);

	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = hour_24;
	t.tm_min = minute;
	t.tm_sec = seconds;

	return mktime(&t);
}