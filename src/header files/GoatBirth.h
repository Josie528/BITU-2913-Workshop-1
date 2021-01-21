#include <string>
#include <ctime>
using namespace std;

#ifndef GOATBIRTH_H
#define GOATBIRTH_H

class GoatBirth
{
public:
	string goatID, goatBreed, parentGoatID, healthStatus, goatGender;
	time_t goatDOB;

	GoatBirth(string gID, string gbreed, string gparentgID, 
		string ghealthstatus, string ggender, time_t gDOB)
	{
		goatID = gID;
		goatBreed = gbreed;  
		parentGoatID = gparentgID;
		healthStatus = ghealthstatus;
		goatGender = ggender;
		goatDOB = gDOB;
	}

	GoatBirth()
	{
		goatID = "";
		goatBreed = "";
		parentGoatID = "";
		healthStatus = "";
		goatGender = "";
		goatDOB = 0000-00-00;
	}
};

#endif