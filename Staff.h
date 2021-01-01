#include <string>
#include <ctime>
using namespace std;

#ifndef STAFF_H
#define STAFF_H

class Staff
{
public:
	string staffID, name, staffType, password;
	string gender;
	string telNo;

	Staff(string sID, string sname, string stype, 
		string spwrd, string sgend, string shp)
	{
		staffID = sID;
		name = sname;
		staffType = stype;
		password = spwrd; 
		gender = sgend;
		telNo = shp;
	}
	
	Staff()
	{
		staffID = "";
		name = "";
		staffType = "";
		password = "";
		gender = "";
		telNo = "";
	}
};

#endif